// CVPRO Platooning Production - Follower - Firmware v1.0.0.
// Code Developed by Suresh Balaji N and Meritus R & D Team - 26-12-2023
// Copyright © 2023 Suresh Balaji N and Meritus R & D Team. All rights reserved.
// This program is the intellectual property of Meritus AI, and may not be distributed or reproduced without explicit authorization from the copyright holder.

#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <NewPing.h>
#include "FastLED.h"

#define TRIGGER_PIN 5     // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN 18       // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 500  // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define nsleep 13         // act as swit1ch for motor driver for power consumption

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);  // NewPing setup of pins and maximum distance.

// Battery
int bat = 39;

// LED
#define NUM_LEDS 1
#define DATA_PIN 15
CRGB leds[NUM_LEDS];
unsigned long previousMillis = 0;
int ledState = LOW;
bool hasIRNeed = false;

// Master Bot - Place the first bot, before the Follower bot
const char *platoonssid = "cvpro0153";     // Wi-Fi network SSID
const char *platoonpassword = "12345678";  // Wi-Fi network password

// Follower(Slave) Bot - Place the second bot, after the first (Master) bot
// Its act as a 'slave' in Wifi Connection and act as 'main cvpro' in hotspot connection
const char *ssid = "cvpro0156";     // Wi-Fi network SSID
const char *password = "12345678";  // Wi-Fi network password

// IP address
const char *mqtt_broker = "192.168.4.2";  //"broker.emqx.io";
const int mqtt_port = 1883;
const char *mqtt_username = ssid;  //"cvpro";
const char *mqtt_password = ssid;  //"cvpro";

int ctrl_left = 0;
int ctrl_right = 0;
int consecutiveLowReadings = 0;
// IR Right-Side ---> irSensorPinR
// IR Left-Side  ---> irSensorPinL
const int irSensorPinR = 2;
const int irSensorPinL = 23;
int direction = 1;

char *pch;

WiFiClient espClient;
PubSubClient client(espClient);

int count = 0;

// Define variables for motor control
unsigned long startTime;
const unsigned long duration = 5000;  // Duration in milliseconds (5 seconds)

void setup() {

  Serial.begin(115200);
  // Initialize LED strip
  pinMode(nsleep, OUTPUT);
  FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
  leds[0] = CRGB(0, 0, 0);  // Set initial color (black)

  // Set the IR sensor pin as input
  pinMode(irSensorPinR, INPUT);
  pinMode(irSensorPinL, INPUT);

  // Connect to Wi-Fi
  WiFi.begin(platoonssid, platoonpassword);
  Serial.print("Connecting to WiFi");

  int attempt = 0;
  while (WiFi.status() != WL_CONNECTED && attempt < 20) {
    delay(1000);
    Serial.print(".");
    attempt++;
  }
  // WIFI-Connection
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nConnected to the WiFi network");
    // Your additional setup code here
    // Set nsleep pin as OUTPUT
    pinMode(nsleep, OUTPUT);
    char *topic = "platoon";
    hasIRNeed = true;
    setupMQTT();
    client.subscribe(topic);
  } else {
    Serial.println("\nFailed to connect to WiFi. Starting as hotspot");
    startHotspot();
    char *topic = "cvpro";
    hasIRNeed = false;
    setupMQTT();
    client.subscribe(topic);
  }

  setup_motorControl();
  // publish and subscribe
  // client.publish(topic, "ssid");
  left_front(0, 0);
  right_front(0, 0);
  left_back(0, 0);
  right_back(0, 0);
}

void setupMQTT() {
  // Connecting to MQTT broker
  client.setServer(mqtt_broker, mqtt_port);
  client.setCallback(callback);
  while (!client.connected()) {
    String client_id = "esp32-client-";
    client_id += String(WiFi.macAddress());
    // Serial.printf("The client %s connects to the public mqtt broker\n", client_id.c_str());
    if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
      Serial.println("MQTT broker connected");
      led(0, 0, 255);
      delay(1000);
      led(0, 0, 0);
    } else {
      led(255, 255, 0);
      delay(1000);
      led(0, 0, 0);
      Serial.print("Failed to connect to MQTT broker with state ");
      Serial.println(client.state());
    }
  }
}

void startHotspot() {
  // Function to start the hotspot
  // Uncomment the following lines to enable hotspot
  WiFi.softAP(ssid, password);       // Configure the ESP32 as an access point
  IPAddress myIP = WiFi.softAPIP();  // Get the IP address of the ESP32 access point
  Serial.print("Access point started with SSID ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(myIP);
}

void callback(char *topic, byte *payload, unsigned int length) {
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  payload[length] = '\0';
  char *msg = (char *)payload;
  Serial.print("Receiving message ");
  Serial.println(msg);
  int n = sscanf(msg, "%d,%d", &ctrl_left, &ctrl_right);
  // Serial.println("left");
  // Serial.println(ctrl_left);
  // Serial.println("right");
  // Serial.println(ctrl_right);

  if (n != 2) {
    Serial.println("Invalid message format");
    return;
  }
  navigation(ctrl_left, ctrl_right);
}

void loop() {

  delay(50);
  digitalWrite(13, HIGH);
  led(0, 255, 0);
  unsigned int distance = sonar.ping_cm();
  Serial.print("distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Read the state of the IR sensors
  int irSensorState1 = digitalRead(irSensorPinR);
  int irSensorState2 = digitalRead(irSensorPinL);

  Serial.println(irSensorState1);
  Serial.println(irSensorState2);
  //If Minimum distance less than 10, the Follower bot is stop
  if (distance < 10 && hasIRNeed == true) {
    platoon_stop();
    Serial.println("platoon stop!!!");
  }
  //distance < 40
  if (((irSensorState1 == LOW && irSensorState2 == LOW) && (hasIRNeed == true)) || (distance < 40 && hasIRNeed == true)) {
    if (direction == 1) {
      frwd_motors();
    }
    client.loop();
    direction = 0;
    led(255, 255, 255);
  }

  if ((irSensorState1 == HIGH && irSensorState2 == HIGH) && hasIRNeed == true) {
    frwd_motors();
    delay(1000);
    motorstop();
    direction = 0;
  }

  if ((irSensorState1 == HIGH && irSensorState2 == LOW) && hasIRNeed == true) {
    left_motors();
    direction = 1;
    led(255, 255, 255);
  }
  if ((irSensorState1 == LOW && irSensorState2 == HIGH) && hasIRNeed == true) {
    right_motors();
    direction = 1;
    led(255, 255, 255);
  }

 // backward
  if ((distance < 20 && distance > 0) && hasIRNeed == false) {
    Serial.println("stop");
    motorstop();

  } else {
    Serial.println("run");
    client.loop();
  }

  if ((ctrl_left == 0) && (ctrl_right == 0)) {
    int sensorValue = analogRead(bat);  // Read the voltage on the ADC pin
    Serial.print("Battery voltage: ");
    float voltage = (sensorValue / 4095.0) * 4;
    Serial.println(voltage);

    if (voltage < 3.40) {
      consecutiveLowReadings++;

      if (consecutiveLowReadings >= 10) {
        unsigned long currentMillis = millis();

        // Blink the LED every second
        if (currentMillis - previousMillis >= 1000) {
          previousMillis = currentMillis;

          // Toggle the LED state
          ledState = !ledState;

          while (true) {
            // Set the LED color based on the state
            if (ledState) {
              led(255, 0, 0);  // Red color
              delay(1000);
            }
            // Turn off the LED
            led(0, 0, 0);
            delay(1000);

            digitalWrite(nsleep, LOW);
            motorstop();
          }
        }
      }
    }
  }
}
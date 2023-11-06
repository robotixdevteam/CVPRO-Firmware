// CVPRO Production Firmware v1.0.0. 
// Code Developed by Suresh Balaji, E.V.V Thrilok kumar and Meritus R & D Team - 30-10-2023
// Copyright © 2023 Suresh Balaji, E.V.V Thrilok kumar and Meritus R & D Team. All rights reserved.
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

// wifi name and password
const char *ssid = "cvpro0121";  // <serial_number of CVPRO Brick>. For example, cvpro0123
const char *password = "12345678";

// IP address
const char *mqtt_broker = "192.168.4.2";  //"broker.emqx.io"; 
const int mqtt_port = 1883;
const char *mqtt_username = ssid; //"cvpro";
const char *mqtt_password = ssid; //"cvpro";

const char *topic = "cvpro";
int ctrl_left = 0;
int ctrl_right = 0;

char *pch;

WiFiClient espClient;
PubSubClient client(espClient);

int count = 0;

void setup() {
  // Put your setup code here, to run once:
  // // connecting to a WiFi network

  //  pinMode(echoPin, INPUT);
  //  pinMode(trigPin, OUTPUT);

  // WiFi.begin(ssid, password);
  // while (WiFi.status() != WL_CONNECTED) {
  //   Serial.println("Connecting to WiFi..");
  // }
  // Serial.println("Connected to the WiFi network");
  pinMode(nsleep, OUTPUT);
  FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
  led(0, 0, 0);

  // Hotspot
  WiFi.softAP(ssid, password);       // Configure the ESP32 as an access point
  IPAddress myIP = WiFi.softAPIP();  // Get the IP address of the ESP32 access point
  Serial.print("Access point started with SSID ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(myIP);

  //connecting to a mqtt broker
  client.setServer(mqtt_broker, mqtt_port);
  client.setCallback(callback);
  while (!client.connected()) {
    String client_id = "esp32-client-";
    client_id += String(WiFi.macAddress());
    // Serial.printf("The client %s connects to the public mqtt broker\n", client_id.c_str());
    if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
       Serial.println("Public emqx mqtt broker connected");
      led(0, 0, 255);
      delay(1000);
      led(0, 0, 0);
    } else {
      led(255, 255, 0);
      delay(1000);
      led(0, 0, 0);
      Serial.print("failed with state ");
      Serial.print(client.state());
    }
  }
  setup_motorControl();
  // publish and subscribe
  // client.publish(topic, "Hi EMQX I'm ESP32 ^^");
  left_front(0, 0);
  left_back(0, 0);
  right_front(0, 0);
  right_back(0, 0);
  client.subscribe(topic);
  Serial.begin(115200);
}

void callback(char *topic, byte *payload, unsigned int length) {
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  payload[length] = '\0';
  char *msg = (char *)payload;
  Serial.println("message");
  Serial.println(msg);
  int n = sscanf(msg, "%d,%d", &ctrl_left, &ctrl_right);
  Serial.println("left");
  Serial.println(ctrl_left);
  Serial.println("right");
  Serial.println(ctrl_right);

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
  // backward

  if (distance < 20 && distance > 0) {
    Serial.println("stop");
    motorstop();

  } else {
    client.loop();
  }

  // float vbat = batteryVoltage(bat);
  // Serial.print("vbat");
  // Serial.print(vbat);

  // int sensorValue = analogRead(bat);  // Read the voltage on the ADC pin
  // Serial.print("Battery voltage: ");
  // float voltage = (sensorValue / 4095.0) * 4;
  // Serial.println(voltage);

  // if (voltage < 3.7) {
  //   count += 1;
  // }
  // if (count == 3) {
  //   led(255, 0, 0); // Red color
  //   Serial.print("count");
  //   Serial.print(count);
  //   digitalWrite(nsleep, LOW);
  //   left_front(255, 255);
  //   left_back(255, 255);
  //   right_front(255, 255);
  //   right_back(255, 255);
  // }
}

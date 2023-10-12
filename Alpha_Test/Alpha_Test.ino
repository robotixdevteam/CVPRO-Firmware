// Test-Code for CVPRO
// for testing Peripherals  
// Code Developed by E.V.V Thrilok kumar and Meritus R & D Team - 28-08-2023
// Copyright © 2023 E.V.V Thrilok kumar and Meritus R & D Team. All rights reserved.
// This program is the intellectual property of Meritus AI, and may not be distributed or reproduced without explicit authorization from the copyright holder.

#include "FastLED.h"
//Motor-Pins
int motorpinLF1 = 14;
int motorpinLF2 = 16;
int motorpinLB1 = 32;
int motorpinLB2 = 33;
int motorpinRF1 = 19;
int motorpinRF2 = 17;
int motorpinRB1 = 25;
int motorpinRB2 = 26;

const int motorEnablePin = 13;
//Battery-Pin
int bat = 39;
//IR-Pins
const int irPin1 = 23;  // Digital input pin for IR sensor 1
const int irPin2 = 2;  // Digital input pin for IR sensor 2
//Ultrasonic-Pins
#define trigPin 5
#define echoPin 18

#define analogInPin 39
const float Vin = 3.7;   // Input voltage (in volts)
const float R1 = 150.0;  // Resistance of R1 (in ohms)
const float R2 = 560.0;  // Resistance of R2 (in ohms)

unsigned long previousTime = 0;
const long interval = 100;  // set interval time in milliseconds

#define NUM_LEDS 1
#define DATA_PIN 15
CRGB leds[NUM_LEDS];

void setup() {
  Serial.println("Initializing the setup");
  pinMode(motorEnablePin, OUTPUT);
  digitalWrite(motorEnablePin, HIGH);
  analogReadResolution(12);
  hardwaresetup();
  FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
  // led(0, 0, 0);
  reset();
  Serial.begin(115200);
}

void loop() {

  if (Serial.available() > 0) {
    String msg = Serial.readStringUntil('\n');
    Serial.print(msg);
    options(msg);
  }
}

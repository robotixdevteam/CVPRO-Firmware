// Code Developed by E.V.V Thrilok kumar and Meritus R & D Team - 28-08-2023
// Copyright © 2023 E.V.V Thrilok kumar and Meritus R & D Team. All rights reserved.
// This program is the intellectual property of Meritus AI, and may not be distributed or reproduced without explicit authorization from the copyright holder.

// Test-Code for CVPRO
// for Runtime 
// When the battery voltage less than 3.7 V, the bot will be stop.

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

void hardwaresetup() {
  //Motors

  ledcSetup(0, 5000, 8);
  ledcSetup(1, 5000, 8);
  ledcSetup(2, 5000, 8);
  ledcSetup(3, 5000, 8);
  ledcSetup(4, 5000, 8);
  ledcSetup(5, 5000, 8);
  ledcSetup(6, 5000, 8);
  ledcSetup(7, 5000, 8);

  ledcAttachPin(motorpinLF1, 0);
  ledcAttachPin(motorpinLF2, 1);
  ledcAttachPin(motorpinLB1, 2);
  ledcAttachPin(motorpinLB2, 3);
  ledcAttachPin(motorpinRF1, 4);
  ledcAttachPin(motorpinRF2, 5);
  ledcAttachPin(motorpinRB1, 6);
  ledcAttachPin(motorpinRB2, 7);
}
void lf(int motorLF1, int motorLF2) {
  ledcWrite(0, motorLF1);
  ledcWrite(1, motorLF2);
}
void rb(int motorRB1, int motorRB2) {
  ledcWrite(6, motorRB1);
  ledcWrite(7, motorRB2);
}
void rf(int motorRF1, int motorRF2) {
  ledcWrite(4, motorRF1);
  ledcWrite(5, motorRF2);
}
void lb(int motorLB1, int motorLB2) {
  ledcWrite(2, motorLB1);
  ledcWrite(3, motorLB2);
}
void reset() {
  lf(0, 0);
  lb(0, 0);
  rf(0, 0);
  rb(0, 0);
}

void motors() {
  lf(255, 0);
  lb(255, 0);
  rf(255, 0);
  rb(255, 0);

  delay(1000);

  lf(0, 255);
  lb(0, 255);
  rf(0, 255);
  rb(0, 255);

  delay(1000);
}

int count = 0;
void runtime() {
  motors();
  int sensorValue = analogRead(bat);  // Read the voltage on the ADC pin
  Serial.print("Battery voltage: ");
  float voltage = (sensorValue / 4095.0) * 4;
  Serial.println(voltage);
  if (voltage < 3.7) {
    count += 1;
  }
  if (count == 3) {
    Serial.print("count");
    Serial.print(count);

    digitalWrite(motorEnablePin, LOW);
    lf(255, 255);
    lb(255, 255);
    rf(255, 255);
    rb(255, 255);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.println("Initializing the setup");
  pinMode(motorEnablePin, OUTPUT);
  digitalWrite(motorEnablePin, HIGH);
  hardwaresetup();
  reset();
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  runtime();
}

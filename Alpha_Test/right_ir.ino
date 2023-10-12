// Test-Code for CVPRO
// for checking the Right-Front Sensor

void right_ir() {
  int sensorValue2 = digitalRead(irPin2);
  Serial.print("Sensor 2: ");
  Serial.println(sensorValue2);
}
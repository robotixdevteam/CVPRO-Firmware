// Test-Code for CVPRO
// for checking the Left-IR sensor

void left_ir() {
  int sensorValue1 = digitalRead(irPin1);
  Serial.print("Sensor 1: ");
  Serial.println(sensorValue1);
}
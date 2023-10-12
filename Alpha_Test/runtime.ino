// Test-Code for CVPRO
// for checking the Runtime

void runtime() {
  motors();
  float vbat = batteryVoltage();
  Serial.print("vbat");
  Serial.println(vbat);

  if (vbat < 3.7) {
    reset();
  }
}
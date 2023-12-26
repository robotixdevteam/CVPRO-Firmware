//Battery Voltage

float batteryVoltage(int analogInPin) {
  int sensorValue = analogRead(analogInPin);  // Read the voltage on the ADC pin
  // Serial.print("Battery voltage: ");
  float voltage = (sensorValue / 4095.0) * 4;
  // Serial.print(voltage);
  delay(1000);  // Wait for 1 second before reading again
  return voltage;
}

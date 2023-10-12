// Test-Code for CVPRO
// for checking the Ultrasonic Sensor

void ultrasonic() {
  unsigned long currentTime = millis();
  if (currentTime - previousTime >= interval) {
    previousTime = currentTime;

    // Send 10us pulse to trigger pin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Calculate duration of pulse in microseconds
    long duration = pulseIn(echoPin, HIGH);

    // Calculate distance in centimeters
    int distance = duration / 58.0;

    // Print distance to serial monitor
    Serial.print(": ");
    Serial.println(distance);
    Serial.print(" cm");
  }
}
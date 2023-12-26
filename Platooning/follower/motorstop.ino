//Motors stop

void motorstop() {
  ledcWrite(0, 255);
  ledcWrite(1, 255);
  ledcWrite(2, 255);
  ledcWrite(3, 255);
  ledcWrite(4, 255);
  ledcWrite(5, 255);
  ledcWrite(6, 255);
  ledcWrite(7, 255);
  // String message = String(0);
  // Serial.print("Publishing Platooning Data: ");
  // Serial.println(message);
  // client.publish("cvpro", message.c_str());
}

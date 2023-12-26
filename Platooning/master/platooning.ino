
void publishPlatooningData(int data1, int data2) {

  String message = String(data1+10) + "," + String(data2+10);

  // Print the message to Serial
  Serial.print("Publishing Platooning Data: ");
  Serial.println(message);

  // Publish the message
  client.publish("platoon", message.c_str());
}


// Test-Code for CVPRO
// for checking the Right-Back motors

void rb(int motorRB1, int motorRB2) {
  ledcWrite(6, motorRB1);
  ledcWrite(7, motorRB2);
}
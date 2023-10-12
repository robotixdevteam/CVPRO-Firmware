// Test-Code for CVPRO
// for checking the Right-Front motors

void rf(int motorRF1, int motorRF2) {
  ledcWrite(4, motorRF1);
  ledcWrite(5, motorRF2);
}
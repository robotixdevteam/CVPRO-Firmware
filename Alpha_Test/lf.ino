// Test-Code for CVPRO
// for checking the Left-front motors

void lf(int motorLF1, int motorLF2) {
  ledcWrite(0, motorLF1);
  ledcWrite(1, motorLF2);
}
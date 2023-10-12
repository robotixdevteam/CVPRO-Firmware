// Test-Code for CVPRO
// for checking the Left-Back motors

void lb(int motorLB1, int motorLB2){
  ledcWrite(2, motorLB1);
  ledcWrite(3, motorLB2);

}
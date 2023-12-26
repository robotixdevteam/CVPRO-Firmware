//Motor code - Left-Back Direction

void left_back(int motorLB1,int motorLB2){
  ledcWrite(2, motorLB1);
  ledcWrite(3, motorLB2);
}
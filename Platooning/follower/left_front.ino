//Motor code - Left-Front Direction

void left_front(int motorLF1, int motorLF2){
  ledcWrite(0, motorLF1); 
  ledcWrite(1, motorLF2);

}
//Motor code - Right-Front Direction

void right_front(int motorRF1,int motorRF2){
  ledcWrite(4, motorRF1);
  ledcWrite(5, motorRF2);
  
}
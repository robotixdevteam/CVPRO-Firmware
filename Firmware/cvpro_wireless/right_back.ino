//Motor code - Right-Back Direction

void right_back(int motorRB1, int motorRB2){
  ledcWrite(6, motorRB1);
  ledcWrite(7, motorRB2);

}
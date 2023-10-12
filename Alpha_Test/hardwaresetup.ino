// Test-Code for CVPRO
// Initialization

void hardwaresetup() {

  //IR pins
  pinMode(irPin1, INPUT);
  pinMode(irPin2, INPUT);

  // ultrasonic
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //Motors
  ledcSetup(0, 5000, 8);
  ledcSetup(1, 5000, 8);
  ledcSetup(2, 5000, 8);
  ledcSetup(3, 5000, 8);
  ledcSetup(4, 5000, 8);
  ledcSetup(5, 5000, 8);
  ledcSetup(6, 5000, 8);
  ledcSetup(7, 5000, 8);

  ledcAttachPin(motorpinLF1, 0);
  ledcAttachPin(motorpinLF2, 1);
  ledcAttachPin(motorpinLB1, 2);
  ledcAttachPin(motorpinLB2, 3);
  ledcAttachPin(motorpinRF1, 4);
  ledcAttachPin(motorpinRF2, 5);
  ledcAttachPin(motorpinRB1, 6);
  ledcAttachPin(motorpinRB2, 7);
}
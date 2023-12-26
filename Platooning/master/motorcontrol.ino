//Motor Control

void setup_motorControl() {
  // Set the PWM frequency to control the speed of the motors
  ledcSetup(0, 5000, 8);
  ledcSetup(1, 5000, 8);
  ledcSetup(2, 5000, 8);
  ledcSetup(3, 5000, 8);
  ledcSetup(4, 5000, 8);
  ledcSetup(5, 5000, 8);
  ledcSetup(6, 5000, 8);
  ledcSetup(7, 5000, 8);

  // Deltasssz
  
  // ledcAttachPin(17, 0);
  // ledcAttachPin(16, 1);
  // ledcAttachPin(19, 2);  
  // ledcAttachPin(21, 3);  
  // ledcAttachPin(33, 4);  
  // ledcAttachPin(32, 5); 
  // ledcAttachPin(25, 6);  
  // ledcAttachPin(26, 7); 

// final cvpro
  ledcAttachPin(14, 0);
  ledcAttachPin(16, 1);
  ledcAttachPin(32, 2);  
  ledcAttachPin(33, 3);  
  ledcAttachPin(19, 4);  
  ledcAttachPin(17, 5); 
  ledcAttachPin(25, 6);  
  ledcAttachPin(26, 7); 

}

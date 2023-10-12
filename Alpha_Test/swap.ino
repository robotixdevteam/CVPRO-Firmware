// Test-Code for CVPRO
// for Swapping Motors

void swap() {
  // Swap the pins for the left front motor
  int temp = motorpinLF1;
  motorpinLF1 = motorpinLF2;
  motorpinLF2 = temp;

  // Swap the pins for the left rear motor
  temp = motorpinLB1;
  motorpinLB1 = motorpinLB2;
  motorpinLB2 = temp;

  // Swap the pins for the right front motor
  temp = motorpinRF1;
  motorpinRF1 = motorpinRF2;
  motorpinRF2 = temp;

  // Swap the pins for the right rear motor
  temp = motorpinRB1;
  motorpinRB1 = motorpinRB2;
  motorpinRB2 = temp;

  Serial.println("Swapped motor pins");
}
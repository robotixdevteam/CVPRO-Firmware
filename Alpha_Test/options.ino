// Test-Code for CVPRO
// List menu options

void options(String msg) {
  if (msg == "lb") {
    Serial.println(" ---> Left Back Motor");
    lb(255, 0);

  } else if (msg == "lf") {
    Serial.println(" ---> Left Front Motor");
    lf(255, 0);

  } else if (msg == "rf") {
    Serial.println(" ---> Right Front Motor");
    rf(255, 0);

  } else if (msg == "rb") {
    Serial.println(" ---> Right Back Motor");
    rb(255, 0);

  } else if (msg == "us") {
    ultrasonic();
    Serial.println(" ---> Ultrasonic sensor");

  } else if (msg == "lir") {
    left_ir();
    Serial.println(" ---> Left IR sensor");

  } else if (msg == "rir") {
    right_ir();
    Serial.println(" ---> Right IR sensor");


  } else if (msg == "s") {
    Serial.println(" ---> Swapping motors");
    swap();
    motors();

  } else if (msg == "m") {
    Serial.println(" ---> All Motors Running");
    motors();

  } else if (msg == "of") {
    Serial.println(" ---> Motors reset");
    reset();

  } else if (msg == "f") {
    Serial.println(" ---> Motors Running Forward");
    motors();

  } else if (msg == "b") {
    Serial.println(" ---> Motors Running Backward");
    lf(0, 255);
    lb(0, 255);
    rf(0, 255);
    rb(0, 255);
  } else if (msg == "r") {
    Serial.println(" ---> Motors running Right");
    lf(255, 0);
    lb(255, 0);
    rf(0, 255);
    rb(0, 255);
  } else if (msg == "l") {
    Serial.println(" ---> Motors Running Left ");
    lf(0, 255);
    lb(0, 255);
    rf(255, 0);
    rb(255, 0);
  } else if (msg == "v") {
    Serial.println(" ---> Voltage of the battery ");
    batteryVoltage();
  } else if (msg == "rt") {
    Serial.println(" ---> Run time of the bot");
    runtime();
  } else if (msg == "led") {
    Serial.println(" ---> LED blinking of the bot");
    led(255, 0, 0);
    delay(1000);
    led(0, 255, 0);
    delay(1000);
    led(0, 0, 255);
    delay(1000);
    led(0, 255, 255);
    delay(1000);
    led(0, 0, 0);
    delay(1000);
  } else{
    Serial.print("Type correct Option");
  }
}
// Test-Code for CVPRO
// for checking the LED Blinking

void led(int R, int G, int B) {
  leds[0] = CRGB(G, R, B);
  FastLED.show();
}
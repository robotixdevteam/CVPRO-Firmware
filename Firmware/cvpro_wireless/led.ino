//LED Glowing

void led(int R, int G, int B) {
  leds[0] = CRGB(G, R, B);
  FastLED.show();
}
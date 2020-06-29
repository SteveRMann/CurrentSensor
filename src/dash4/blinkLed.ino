//blinkLed() will switch GPIO2 from input to output, blink the LED on GPIO2 and return the mode to input.
//Button2 is also on GPIO2.

void blinkLed() {
  pinMode(BUTTON_TWO_PIN, OUTPUT);
  //digitalWrite(LED_BUILTIN, LED_ON);
  digitalWrite(BUTTON_TWO_PIN, LED_ON);
  delay(50);
  digitalWrite(LED_BUILTIN, LED_OFF);
  delay(50);
  pinMode(BUTTON_TWO_PIN, INPUT);
}

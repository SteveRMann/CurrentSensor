//========== Setup ==========
void setup() {
    Serial.begin(115200);
    Serial.println(F("\n"));
    delay(10);
    Serial.println(F(sketchName));
    Serial.print(F("Version "));
    Serial.println(F(sketchVersion));
    Serial.println();


  //********** CHANGE PIN FUNCTION  TO GPIO **********
  pinMode(1, FUNCTION_3);   //Use Tx as GPIO1
  pinMode(3, FUNCTION_3);   //Use Rx as GPIO

  pinMode(BUTTON_ONE_PIN, INPUT_PULLUP);
  pinMode(BUTTON_TWO_PIN, INPUT_PULLUP);
  pinMode(BUTTON_THREE_PIN, INPUT_PULLUP);
  pinMode(BUTTON_FOUR_PIN, INPUT_PULLUP);

  // Initialize the buttons
  button1.begin();
  button2.begin();
  button3.begin();
  button4.begin();

  // Add the callback function to be called when the buttons are pressed.
  button1.onPressed(onButton1PressedShort);
  button1.onPressedFor(1000, onButton1PressedLong);
  button2.onPressed(onButton2PressedShort);
  button2.onPressedFor(1000, onButton2PressedLong);
  button3.onPressed(onButton3PressedShort);
  button3.onPressedFor(1000, onButton3PressedLong);
  button4.onPressed(onButton4PressedShort);
  button4.onPressedFor(1000, onButton4PressedLong);


  setup_wifi();
  start_OTA();
  client.setServer(mqttServer, mqttPort);
  mqttConnect();

  client.publish(statusTopic, "ready");
  delay(5);

}

//========== Loop ==========
void loop()
{
  ArduinoOTA.handle();

  // Continuously read the status of the buttons
  button1.read();
  delay (10);
  button2.read();
  delay (10);
  button3.read();
  delay (10);
  button4.read();
  delay (10);

  //Make sure we stay connected to the mqtt broker
  if (!client.loop()) client.connect(connectName);

}

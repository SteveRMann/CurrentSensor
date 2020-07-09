//========== Loop ==========
void loop()
{
  ArduinoOTA.handle();

  // Every ten seconds, send a status.

  
  //Make sure we stay connected to the mqtt broker
  if (!client.loop()) client.connect(connectName);

}

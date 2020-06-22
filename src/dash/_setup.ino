// ================================== setup() ==================================
void setup()
{
  Serial.begin(115200);

  Serial.println();
  Serial.println();
  Serial.println(F(SketchName));
  Serial.println(F(sketchVersion));
  Serial.println();

  setup_wifi();


  // Call the PubSubClent setServer method, passing as first argument the
  // address and as second the port.
  client.setServer(mqttServer, mqttPort);
  mqttConnect();

  // Tell the game operator what was dialed.  (Both formats work).
  //client.publish(numberDialedTopic, (char*)dialedDigits);
  client.publish(statusTopic, "open");
  delay(5);
}

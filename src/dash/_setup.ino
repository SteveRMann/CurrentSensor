// ================================== setup() ==================================
void setup()
{

  /*  Serial.begin(115200);
    Serial.println();
    Serial.println();
    Serial.println(F(SketchName));
    Serial.println(F(sketchVersion));
    Serial.println();
  */

  // digitalWrite(ledPin, ledON);

  setup_wifi();
  client.setServer(mqttServer, mqttPort);
  mqttConnect();

  client.publish(statusTopic, "true");
  delay(5);

  // digitalWrite(ledPin, ledOFF);
  // delay(100);

  //Now, sleep, waiting for RST
  ESP.deepSleep( 0, WAKE_RF_DEFAULT );
}

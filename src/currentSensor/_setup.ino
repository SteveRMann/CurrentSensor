//========== Setup ==========
void setup() {
  Serial.begin(115200);
  Serial.println(F("\n"));
  delay(10);
  Serial.println(F(sketchName));
  Serial.print(F("Version "));
  Serial.println(F(sketchVersion));
  Serial.println();

  pinMode(2, INPUT_PULLUP);
  
  setup_wifi();
  start_OTA();
  client.setServer(mqttServer, mqttPort);
  mqttConnect();

  client.publish(statusTopic, "ready");
  delay(5);

}

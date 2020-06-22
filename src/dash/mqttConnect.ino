
// ================================== mqttConnect() =================================
// Connect or Reconnect to MQTT broker
void mqttConnect() {
  // Loop until we're Connected
  while (!client.connected()) {
    Serial.print(F("Attempting MQTT connection..."));

    // Attempt to connect
    if (client.connect(connectName)) {
      Serial.println(F("connected"));

      //client.setCallback(callback);

      //Subscribe or resubscribe to a topic
      //client.subscribe(incomingTopic);
      //Serial.print(F("Subscribing to "));
      //Serial.println(incomingTopic);
      //Serial.println();
    } else {
      Serial.print(F("failed, rc="));
      Serial.print(String(client.state()));
      Serial.println(F(" try again in 5 seconds"));
      delay(5000);
    }
  }
}

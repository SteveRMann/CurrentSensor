// Callback functions to be called when a button is pressed

// ---- Button 1 ----
void onButton1PressedShort() {
  client.publish(statusTopic, "1");
}

void onButton1PressedLong() {
  client.publish(statusTopic, "5");
}

// ---- Button 2 ----
void onButton2PressedShort() {
  client.publish(statusTopic, "2");
}

void onButton2PressedLong() {
  client.publish(statusTopic, "6");
}

// ---- Button 3 ----
void onButton3PressedShort() {
  client.publish(statusTopic, "3");
}

void onButton3PressedLong() {
  client.publish(statusTopic, "7");
}

// ---- Button 4 ----
void onButton4PressedShort() {
  client.publish(statusTopic, "4");
}

void onButton4PressedLong() {
  client.publish(statusTopic, "8");
}

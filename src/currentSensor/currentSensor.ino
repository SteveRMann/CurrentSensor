#define sketchName "currentSensor.ino"
#define sketchVersion "Version 1.0 (7/10/2020)"
#define hostPrefix "iSense-"     // 6-chars MAX. Used by setup_wifi()

/*
  This project provides current sensing MQTT messages for devices that have no feedback
  to Home Assistant or Node-Red.  A television or washing-machine, for example
*/

#include <ArduinoOTA.h>
#include <ESP8266WiFi.h>        // Connect (and reconnect) an ESP8266 to the a WiFi network.
#include <PubSubClient.h>       // connect to a MQTT broker and publish/subscribe messages in topics.

#include "D:\River Documents\Arduino\libraries\Kaywinnet.h"  \\ WiFi credentials


char macBuffer[24];             // Holds the last three digits of the MAC, in hex.
char hostNamePrefix[] = hostPrefix;
char hostName[12];              // Holds hostNamePrefix + the last three bytes of the MAC address.
IPAddress myIP;                 // Holds the IP address
int rssi;


// ********** Globals **********
#define DEBUG false              //Set to true for debug output, false for no debug ouput
#define Serial if(DEBUG)Serial

#define NODENAME "currentSensor4"
const char *statusTopic = NODENAME "/status";               // Status is the most recent button number, 1-8, pressed.
const char *connectName =  NODENAME "sensor";               // Must be unique on the network
const char *mqttServer = mqtt_server;                       // Local broker defined in Kaywinnet.h
//const char *mqttServer = "broker.hivemq.com";
const int mqttPort = 1883;

// Declare an object of class WiFiClient, which allows to establish a connection to a specific IP and port
// Declare an object of class PubSubClient, which receives as input of the constructor the previously defined WiFiClient.
// The constructor MUST be unique on the network.
WiFiClient currentSensor1Client;
PubSubClient client(currentSensor1Client);

#define SketchName "dash.ino"
#define sketchVersion "Version 1.0 (6/22/2020)"

/*
 * I had a fan that dies, but I kept the remote.
 * I was able to find a way to put an ESP8266-01 inside the remote to make
 * a four-button dash appliance.
 * Each button publishes a single MQTT message.
*/

#include <ESP8266WiFi.h>        // Connect (and reconnect) an ESP8266 to the a WiFi network.
#include <PubSubClient.h>       // connect to a MQTT broker and publish/subscribe messages in topics.

//For setup_wifi()
#define hostPrefix "ENTRY-"     // 6-chars MAX

#include "D:\River Documents\Arduino\libraries\Kaywinnet.h"  \\ WiFi credentials

char macBuffer[24];             // Holds the last three digits of the MAC, in hex.
char hostNamePrefix[] = hostPrefix;
char hostName[12];              // Holds hostNamePrefix + the last three bytes of the MAC address.
IPAddress myIP;                 // Holds the IP address
int rssi;

#define ledPin 2
#define ledON HIGH
#define ledOFF LOW

// ****************************** Globals  ******************************

#define NODENAME "door"
const char *statusTopic = NODENAME "/status";               // Status of the sensor, "open" or undefined

const char *connectName =  NODENAME "sensor";               // Must be unique on the network
const char *mqttServer = mqtt_server;                       // Local broker defined in Kaywinnet.h
//const char *mqttServer = "broker.hivemq.com";
const int mqttPort = 1883;


// Declare an object of class WiFiClient, which allows to establish a connection to a specific IP and port
// Declare an object of class PubSubClient, which receives as input of the constructor the previously defined WiFiClient.
// The constructor MUST be unique on the network.
WiFiClient doorSensorClient;
PubSubClient client(doorSensorClient);

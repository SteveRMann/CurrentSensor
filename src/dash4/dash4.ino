#define sketchName "dash.ino"
#define sketchVersion "Version 1.0 (6/22/2020)"
#define hostPrefix "DASH4-"     // 6-chars MAX. Used by setup_wifi()


/*
   I had a fan that died, but I kept the remote.
   I was able to find a way to put an ESP8266-01 inside the remote to make
   a four-button dash appliance. Each button publishes a single MQTT message.
   Using the EasyButton.h library, this gives us eight different operations.
   Four simple button presses and four long button presses.
*/

#include <ArduinoOTA.h>
#include <ESP8266WiFi.h>        // Connect (and reconnect) an ESP8266 to the a WiFi network.
#include <PubSubClient.h>       // connect to a MQTT broker and publish/subscribe messages in topics.
#include <EasyButton.h>

#include "D:\River Documents\Arduino\libraries\Kaywinnet.h"  \\ WiFi credentials

//Button GPIOs
#define BUTTON_ONE_PIN 0
#define BUTTON_TWO_PIN 2
#define BUTTON_THREE_PIN 1  // Tx
#define BUTTON_FOUR_PIN 3  // Rx

// Define instances of EasyButton
EasyButton button1(BUTTON_ONE_PIN);
EasyButton button2(BUTTON_TWO_PIN);
EasyButton button3(BUTTON_THREE_PIN);
EasyButton button4(BUTTON_FOUR_PIN);

char macBuffer[24];             // Holds the last three digits of the MAC, in hex.
char hostNamePrefix[] = hostPrefix;
char hostName[12];              // Holds hostNamePrefix + the last three bytes of the MAC address.
IPAddress myIP;                 // Holds the IP address
int rssi;


// ********** Globals **********
#define DEBUG false              //Set to true for debug output, false for no debug ouput
#define Serial if(DEBUG)Serial

#define NODENAME "dash4"
const char *statusTopic = NODENAME "/status";               // Status is the most recent button number, 1-8, pressed.
const char *connectName =  NODENAME "sensor";               // Must be unique on the network
const char *mqttServer = mqtt_server;                       // Local broker defined in Kaywinnet.h
//const char *mqttServer = "broker.hivemq.com";
const int mqttPort = 1883;

// Declare an object of class WiFiClient, which allows to establish a connection to a specific IP and port
// Declare an object of class PubSubClient, which receives as input of the constructor the previously defined WiFiClient.
// The constructor MUST be unique on the network.
WiFiClient dash4Client;
PubSubClient client(dash4Client);

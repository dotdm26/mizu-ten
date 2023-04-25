/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.8 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.11.1 or later version;
     - for iOS 1.9.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////
#include <SPI.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <Adafruit_SSD1306.h>


#include "DHTesp.h"
#include <ArduinoJson.h>
#include <PubSubClient.h>
#include <WiFiClientSecure.h>
#include <RemoteXY.h>

#ifdef ESP8266
 #include <ESP8266WiFi.h>
 #else
 #include <WiFi.h>
#endif
/**** DHT11 sensor Settings *******/
#define DHTpin 2   //Set DHT pin as GPIO2
DHTesp dht;

/**** LED Settings *******/
const int led = 5; //Set LED pin as GPIO5

// RemoteXY select connection mode and include library
#define REMOTEXY_MODE__ESP8266_HARDSERIAL_POINT

// RemoteXY connection settings
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 115200
#define REMOTEXY_WIFI_SSID "RemoteXY"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 6377

#define PIN_SWITCH_1 13
#define PIN_SWITCH_2 8
#define AOUT_PIN A0   // Arduino pin that connects to AOUT pin of moisture sensor
#define THRESHOLD 50  // CHANGE YOUR THRESHOLD HERE


#define OLED_RESET 4

/****** WiFi Connection Details *******/
const char* ssid = "your_wifi_ssid";
const char* password = "your_wifi_password";

/******* MQTT Broker Connection Details *******/
const char* mqtt_server = "34bab4bb63014dce9e71f4ad8fb6ffc2.s2.eu.hivemq.cloud";
const char* mqtt_username = "your_mqtt_client_username";
const char* mqtt_password = "your_mqtt_client_password";
const int mqtt_port =8883;

/**** Secure WiFi Connectivity Initialisation *****/
WiFiClientSecure espClient;

/**** MQTT Client Initialisation Using WiFi Connection *****/
PubSubClient client(espClient);

unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE (50)
char msg[MSG_BUFFER_SIZE];


static const char *root_ca PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIFazCCA1OgAwIBAgIRAIIQz7DSQONZRGPgu2OCiwAwDQYJKoZIhvcNAQELBQAw
TzELMAkGA1UEBhMCVVMxKTAnBgNVBAoTIEludGVybmV0IFNlY3VyaXR5IFJlc2Vh
cmNoIEdyb3VwMRUwEwYDVQQDEwxJU1JHIFJvb3QgWDEwHhcNMTUwNjA0MTEwNDM4
WhcNMzUwNjA0MTEwNDM4WjBPMQswCQYDVQQGEwJVUzEpMCcGA1UEChMgSW50ZXJu
ZXQgU2VjdXJpdHkgUmVzZWFyY2ggR3JvdXAxFTATBgNVBAMTDElTUkcgUm9vdCBY
MTCCAiIwDQYJKoZIhvcNAQEBBQADggIPADCCAgoCggIBAK3oJHP0FDfzm54rVygc
h77ct984kIxuPOZXoHj3dcKi/vVqbvYATyjb3miGbESTtrFj/RQSa78f0uoxmyF+
0TM8ukj13Xnfs7j/EvEhmkvBioZxaUpmZmyPfjxwv60pIgbz5MDmgK7iS4+3mX6U
A5/TR5d8mUgjU+g4rk8Kb4Mu0UlXjIB0ttov0DiNewNwIRt18jA8+o+u3dpjq+sW
T8KOEUt+zwvo/7V3LvSye0rgTBIlDHCNAymg4VMk7BPZ7hm/ELNKjD+Jo2FR3qyH
B5T0Y3HsLuJvW5iB4YlcNHlsdu87kGJ55tukmi8mxdAQ4Q7e2RCOFvu396j3x+UC
B5iPNgiV5+I3lg02dZ77DnKxHZu8A/lJBdiB3QW0KtZB6awBdpUKD9jf1b0SHzUv
KBds0pjBqAlkd25HN7rOrFleaJ1/ctaJxQZBKT5ZPt0m9STJEadao0xAH0ahmbWn
OlFuhjuefXKnEgV4We0+UXgVCwOPjdAvBbI+e0ocS3MFEvzG6uBQE3xDk3SzynTn
jh8BCNAw1FtxNrQHusEwMFxIt4I7mKZ9YIqioymCzLq9gwQbooMDQaHWBfEbwrbw
qHyGO0aoSCqI3Haadr8faqU9GY/rOPNk3sgrDQoo//fb4hVC1CLQJ13hef4Y53CI
rU7m2Ys6xt0nUW7/vGT1M0NPAgMBAAGjQjBAMA4GA1UdDwEB/wQEAwIBBjAPBgNV
HRMBAf8EBTADAQH/MB0GA1UdDgQWBBR5tFnme7bl5AFzgAiIyBpY9umbbjANBgkq
hkiG9w0BAQsFAAOCAgEAVR9YqbyyqFDQDLHYGmkgJykIrGF1XIpu+ILlaS/V9lZL
ubhzEFnTIZd+50xx+7LSYK05qAvqFyFWhfFQDlnrzuBZ6brJFe+GnY+EgPbk6ZGQ
3BebYhtF8GaV0nxvwuo77x/Py9auJ/GpsMiu/X1+mvoiBOv/2X/qkSsisRcOj/KK
NFtY2PwByVS5uCbMiogziUwthDyC3+6WVwW6LLv3xLfHTjuCvjHIInNzktHCgKQ5
ORAzI4JMPJ+GslWYHb4phowim57iaztXOoJwTdwJx4nLCgdNbOhdjsnvzqvHu7Ur
TkXWStAmzOVyyghqpZXjFaH3pO3JLF+l+/+sKAIuvtd7u+Nxe5AW0wdeRlN8NwdC
jNPElpzVmbUq4JUagEiuTDkHzsxHpFKVK7q4+63SM1N95R1NbdWhscdCb+ZAJzVc
oyi3B43njTOQ5yOf+1CceWxG1bQVs5ZufpsMljq4Ui0/1lvh+wjChP4kqKOJ2qxq
4RgqsahDYVvTH9w7jXbyLeiNdd8XM2w9U/t7y0Ff/9yi0GE44Za4rF2LN9d11TPA
mRGunUHBcnWEvgJBQl9nJEiU0Zsnvgc/ubhPgXRR4Xq37Z0j4r7g1SgEEzwxA57d
emyPxgcYxn/eR44/KJ4EBs+lVDR3veyJm+kXQ99b21/+jh5Xos1AnX5iItreGCc=
-----END CERTIFICATE-----
)EOF";

// RemoteXY configurate
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =  // 93 bytes
  { 255, 2, 0, 15, 0, 86, 0, 16, 154, 1, 2, 0, 44, 5, 15, 6, 2, 26, 31, 31,
    79, 78, 0, 79, 70, 70, 0, 4, 128, 7, 20, 51, 5, 2, 26, 71, 56, 12, 46, 39,
    39, 0, 2, 24, 135, 0, 0, 0, 0, 0, 0, 200, 66, 0, 0, 160, 65, 0, 0, 32,
    65, 0, 0, 0, 64, 24, 0, 129, 0, 22, 14, 18, 3, 177, 84, 72, 82, 69, 83, 72,
    79, 76, 68, 0, 67, 4, 25, 27, 13, 5, 2, 26, 11 };

// this structure defines all the variables and events of your control interface
struct {

  // input variables
  uint8_t switch_1;  // =1 if switch ON and =0 if OFF
  int8_t slider_1;   // =0..100 slider position

  // output variables
  float instrument_1;  // from 0 to 100
  char text_1[11];     // string UTF8 end zero

  // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////







/************* Connect to WiFi ***********/
void setup_wifi() {
  delay(10);
  Serial.print("\nConnecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  randomSeed(micros());
  Serial.println("\nWiFi connected\nIP address: ");
  Serial.println(WiFi.localIP());
}

/************* Connect to MQTT Broker ***********/
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP8266Client-";   // Create a random client ID
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str(), mqtt_username, mqtt_password)) {
      Serial.println("connected");

      client.subscribe("led_state");   // subscribe the topics here

    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");   // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

/***** Call back Method for Receiving MQTT messages and Switching LED ****/

void callback(char* topic, byte* payload, unsigned int length) {
  String incommingMessage = "";
  for (int i = 0; i < length; i++) incommingMessage+=(char)payload[i];

  Serial.println("Message arrived ["+String(topic)+"]"+incommingMessage);

  //--- check the incomming message
    if( strcmp(topic,"led_state") == 0){
     if (incommingMessage.equals("1")) digitalWrite(led, HIGH);   // Turn the LED on
     else digitalWrite(led, LOW);  // Turn the LED off
  }

}

/**** Method for Publishing MQTT Messages **********/
void publishMessage(const char* topic, String payload , boolean retained){
  if (client.publish(topic, payload.c_str(), true))
      Serial.println("Message publised ["+String(topic)+"]: "+payload);
}


Adafruit_SSD1306 Display(OLED_RESET);
void setup() {
  RemoteXY_Init();

  pinMode(PIN_SWITCH_1, OUTPUT);
  pinMode(PIN_SWITCH_2, OUTPUT);
  // TODO you setup code
  Display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)

  // i'll follow the license agreement and display the Adafruit logo
  // and since they were nice enough to supply the libraries
  Display.clearDisplay();
  Display.display();
  delay(1000);

  DrawTitles();

  dht.setup(DHTpin, DHTesp::DHT11); //Set up DHT11 sensor
  pinMode(led, OUTPUT); //set up LED
  Serial.begin(9600);
  while (!Serial) delay(1);
  setup_wifi();

  #ifdef ESP8266
    espClient.setInsecure();
  #else
    espClient.setCACert(root_ca);     
  #endif

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() {
  RemoteXY_Handler();

  int value = analogRead(AOUT_PIN);        // read the analog value from sensor
  int pre = map(value, 590, 320, 0, 100);  // provide in %
  char state[2][3]={ "Dry", "Wet"};
  int index = pre > 30 ? 1 : 0;
  //strcpy(RemoteXY.text_1, state[index]);
  RemoteXY.instrument_1 = pre;
  digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1 == 0) ? LOW : HIGH);    // Check wifi connection working
  int status = (pre >= (RemoteXY.slider_1 > THRESHOLD ? RemoteXY.slider_1 : THRESHOLD));
  digitalWrite(PIN_SWITCH_2, (status ? LOW : HIGH));  // watering

  Display.setTextSize(1);
  // note set the background color or the old text will still display
  Display.setTextColor(WHITE, BLACK);
  Display.setCursor(0, 15);

  Display.println((pre < 50) ? "Dry" : "Wet");
  Display.setCursor(0, 20);
  //draw the bar graph
  int bar = map(pre, 0, 100, 0, 120);  // provide in %
  Display.fillRect(0, 25, bar, 6, WHITE);
  Display.fillRect(bar, 25, 120, 6, BLACK);
  // now that the display is build, display it...
  Display.display();

  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay()


  if (!client.connected()) reconnect(); // check if client is connected
  client.loop();

  //read DHT11 temperature and humidity reading
  delay(dht.getMinimumSamplingPeriod());
  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();

  DynamicJsonDocument doc(1024);

  doc["deviceId"] = "IOT";
  doc["siteId"] = "TEST1";
  doc["humidity"] = humidity;
  doc["temperature"] = temperature;
  doc["moisture"] = pre;

  char mqtt_message[128];
  serializeJson(doc, mqtt_message);

  publishMessage("esp8266_data", mqtt_message, true);

  //delay(5000);
}

void DrawTitles(void) {
  // displaying   heading
  Display.setTextSize(2);
  Display.setTextColor(WHITE);
  Display.setCursor(0, 0);
  Display.println("Moisture");
  Display.display();
}


String Format(double val, int dec, int dig) {

  // this is my simple way of formatting a number
  // data = Format(number, digits, decimals) when needed
  int addpad = 0;
  char sbuf[20];
  String fdata = (dtostrf(val, dec, dig, sbuf));
  int slen = fdata.length();
  for (addpad = 1; addpad <= dec + dig - slen; addpad++) {
    fdata = " " + fdata;
  }
  return (fdata);
}
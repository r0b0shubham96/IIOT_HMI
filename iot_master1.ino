#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#include <WiFiClient.h>

#include <ESP8266WebServer.h>

#include <Wire.h>
#include <RtcDS3231.h>

RtcDS3231<TwoWire> Rtc(Wire);

#include <EEPROM.h>

#include <SPI.h>
#include <SD.h>

/*************************************** sd card ***********************************/
File myFile;
String fileName = "iiot.txt";
/***********************************************************************************/

/****************************************** hotspot*********************************/
//int led = LED_BUILTIN;

const char *ssid = "ORANGEWOOD (LAST FLOOR)";

const char *password = "orangewood1!";

String page = "";

ESP8266WebServer server(80);
/**********************************************************************************/

/*********************************************firebase**********************************/
// Set these to run example.
#define FIREBASE_HOST "iottest1-e7dfc.firebaseio.com"
#define FIREBASE_AUTH ""
/***************************************************************************************/

/*************************wifi name and psk *******************************************/
//#define WIFI_SSID "ORANGEWOOD (FIRST FLOOR)"
//#define WIFI_PASSWORD "orangewood1!"

char* wifi_ssid     = "D-Link";
char* wifi_password = "capital1";

//#define WIFI_SSID "Design_2"
//#define WIFI_PASSWORD "designteam1!"
/**************************************************************************************/

/*******************************rtc and interrupt************************************/
const int interruptPin = 0; //GPIO 0 (Flash Button) (D3)
int interrupt_flag = 0;
int total_sec = 0;
int diff_sec = 0;

//int led = LED_BUILTIN;
int led = D5;

int int_diff_sec0 = 0;
/************************************************************************************/

int wifiOrHotspot = 0;

char* string2char(String command) {
  if (command.length() != 0) {
    char *p = const_cast<char*>(command.c_str());
    return p;
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("setup");
  
  EEPROM.begin(512);
//  setup_clear_eeprom();

//  setup_sdcard();
//  setup_firebase();
//  setup_rtc();
//  setup_interrupt();

  //  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  ////  Serial.print("connecting");
  //  while (WiFi.status() != WL_CONNECTED) {
  //    Serial.print(".");
  //    delay(500);
  //
  //    wifiOrHotspot++;
  //
  //    if(wifiOrHotspot > 60) {
  //      setup_hotspot();
  //    }
  //  }

  setup_wifi(wifi_ssid, wifi_password);

  //  Serial.println();
  //  Serial.print("connected: ");
  //  Serial.println(WiFi.localIP());

  //  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  //  while((WiFi.status() != WL_CONNECTED)) {
  //    onLed();
  //    setup_hotspot();
  //  }

  //  setup_sdcard();
    setup_firebase();
    setup_rtc();
    pinMode(led, OUTPUT);
    digitalWrite(led, HIGH);
    setup_interrupt();
}

int n = 400;

void loop() {

//  if (interrupt_flag == 2) {
//    interrupt_flag = 0;
//    if (isWifiConnected()) {
//      update_firebase(today_second(), diff_sec);
//      diff_sec = 0;
//    } else if (!isWifiConnected()) {
//      write_eeprom(today_second(), diff_sec);
//      diff_sec = 0;
//    }   
//  }
  
  //  update_firebase();
  //  delay(1000);
  if (interrupt_flag == 2) {
    interrupt_flag = 1;
//    if (isWifiConnected()) {
      update_firebase(now_dateTime(), now_second(), diff_sec);
      diff_sec = 0;
//    } 
//    else if (!isWifiConnected()) {
//      myFile = SD.open(fileName, FILE_WRITE);
//      if (myFile) {
//        myFile.println("testing 1, 2, 3.");
//        myFile.close();
//        Serial.println("done.");
//      } else {
//        // if the file didn't open, print an error:
//        Serial.println("error opening test.txt");
//      }
//    }
  }
}

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <FastLED.h>
#include "index.h"

#define DATA_PIN    3
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS    48
CRGB leds[NUM_LEDS];

int BRIGHTNESS = 255;
long delayTime = 500;
unsigned long previousMillis = 0;

uint8_t gHue = 0;
bool LEDstatus = LOW;

/*Put your SSID & Password*/
const char* ssid = "Adholokam";  // Enter SSID here
const char* password = "asanwifi";  //Enter Password here
ESP8266WebServer server(80);

void setup() {
  Serial.begin(9600);

  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);

  Serial.println("Connecting to ");
  Serial.println(ssid);

  //connect to your local wi-fi network
  WiFi.begin(ssid, password);

  //check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected..!");
  Serial.print("Got IP: ");  Serial.println(WiFi.localIP());

  server.on("/", handle_OnConnect);
  //  server.on("/ledon", handle_ledon);
  //  server.on("/ledoff", handle_ledoff);
  server.on("/setBrightness", handleBrightness);
  server.on("/setDelay", handleDelay);

  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server started");
}
void loop() {
  server.handleClient();
  

  ledHandle();
}

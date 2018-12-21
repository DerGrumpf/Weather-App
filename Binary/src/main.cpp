#include <ESP8266WiFi.h>

char* host = "host";
char* pass = "pass";

void connect_success() {
  Serial.print("Your IP is: ");
  Serial.println(WiFi.localIP());
}

void connect_error() {
  Serial.print("Start Reconnect");
  WiFi.begin(host, pass);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println();

  if (WiFi.status() == WL_CONNECTED) connect_success();
  else connect_error();
}

void connect() {
  WiFi.begin(host, pass);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println();

  if (WiFi.status() == WL_CONNECTED) connect_success();
  else connect_error();
}

//void handle_success() {}

//void handle_error() {}


void setup() {
  Serial.begin(9600);
  Serial.println();
  connect();
}

void loop() {}

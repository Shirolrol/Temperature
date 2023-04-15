/*********
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/vs-code-platformio-ide-esp32-esp8266-arduino/
*********/

#include <Arduino.h>
#include "arduino_secrets.h"
#include <WiFi.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "Led.h"
#include "mqtt.h"







OneWire ds(32u);
DallasTemperature dallasSensors(&ds);
DeviceAddress sensorAddress[2u];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  initWiFi();
  initMqtt();
  int c = add(5, 7);
  Serial.println(c);
  dallasSensors.begin();
  int connectedSensors = dallasSensors.getDeviceCount();
  Serial.println(connectedSensors);
  dallasSensors.getAddress(sensorAddress[0], 0);
  dallasSensors.setResolution(sensorAddress[0], 12u);
}

void loop() {
  dallasSensors.requestTemperatures();
  int t = dallasSensors.getTempC(sensorAddress[0]);
  Serial.println(t);
  if (t > 37) {
    red();
  } else {
    green();
  }
  // call poll() regularly to allow the library to send MQTT keep alive which
  // avoids being disconnected by the broker
  mqttClient.poll();
  // send message, the Print interface can be used to set the message contents
  mqttClient.beginMessage("temperature");
  mqttClient.print(t);
  mqttClient.endMessage();
}

void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin("AndroidAP", "fepv8845");
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, HIGH);
    delay(1000);
    white();
    Serial.print('.');
  }
  Serial.println(WiFi.localIP());
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
}



int add(int a, int b) {
  return a + b;
}
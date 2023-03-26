/*********
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/vs-code-platformio-ide-esp32-esp8266-arduino/
*********/

#include <Arduino.h>
#include <WiFi.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define LED 2
#define RED 12
#define GREEN 14
#define BLUE 27



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
}

void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin("Dim", "Dim2009dim-dim");
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

void white() {
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
}

void red() {
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
}

void blue() {
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, HIGH);
}

void green() {
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, LOW);
}

void yellow() {
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, LOW);
}

void azure() {
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
}

void pink() {
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, HIGH);
}

void dance(int d) {
  white();
  delay(d);
  pink();
  delay(d);
  green();
  delay(d);
  azure();
  delay(d);
  yellow();
  delay(d);
  red();
  delay(d);
  blue();
  delay(d);
  green();
  delay(d);
}

int add(int a, int b) {
  return a + b;
}
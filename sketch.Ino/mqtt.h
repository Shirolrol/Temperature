#include <ArduinoMqttClient.h>

char ssid[] = SECRET_SSID;  // your network SSID (name)
char pass[] = SECRET_PASS;

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

const char broker[] = "perfect-politician.cloudmqtt.com";
int port = 1883;
const char topic[] = "temperature";

void initMqtt() {
  Serial.println(broker);
  Serial.println(port);
  mqttClient.setUsernamePassword(ssid, pass);
  if (!mqttClient.connect(broker, port)) {
    Serial.print("MQTT connection failed! Error code = ");
    Serial.println(mqttClient.connectError());
    while (1);
  }
}
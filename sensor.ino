#include "MessageHandler.h"
#include "Sensor.h"
#include "WifiHandler.h"
#include "Config.h"

Sensor sensor;
WifiHandler wifi(NAME, WIFI_SSID, WIFI_PASS);

MessageHandler messageHandler(SERVER_URL);

void setup()
{
    Serial.begin(BAUD);
    Serial.println("[START] .... Wifi setting");
    wifi.setIp(IP);
    wifi.setGateway(GATEWAY);
    wifi.setSubnet(SUBNET);

    wifi.init();
    wifi.switchOn();

    Serial.println("[END  ] .... Wifi setting");

    Serial.println("[START] .... Load Sensor Data");
    sensor.init();
    sensor.loadNewData();
    Serial.println("[END  ] .... Load Sensor Data");

    Serial.println("[START] .... Send Data to Server");
    messageHandler.sendJson(sensor.getJson());
    Serial.println("[END  ] .... Send Data to Server");

    ESP.deepSleep(INTERVAL*60e6); // convert minutes to usec
}

void loop()
{
  // Do nothing here - everything happens in setup()
}

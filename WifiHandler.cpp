#include "WifiHandler.h"
#include "Config.h"

WifiHandler::WifiHandler(String appName, String ssid, String passwd)
{
    m_appName = appName;
    m_ssid = ssid;
    m_passwd = passwd;

    WiFi.disconnect(true);
    delay(1);
}

void WifiHandler::setIp(int octet1, int octet2, int octet3, int octet4)
{
  m_ip = IPAddress(octet1, octet2, octet3, octet4);
}

void WifiHandler::setGateway(int octet1, int octet2, int octet3, int octet4)
{
  m_gateway = IPAddress(octet1, octet2, octet3, octet4);
}

void WifiHandler::setSubnet(int octet1, int octet2, int octet3, int octet4)
{
  m_subnet = IPAddress(octet1, octet2, octet3, octet4);
}

void WifiHandler::init()
{
    WiFi.mode(WIFI_OFF);
    WiFi.forceSleepBegin();
    delay(1);
}

void WifiHandler::switchOn()
{
    WiFi.forceSleepWake();
    delay(1);

    WiFi.persistent(false);
    WiFi.hostname(m_appName);

    WiFi.mode(WIFI_STA);
    WiFi.config(m_ip, m_gateway, m_subnet);
    WiFi.begin(m_ssid, m_passwd);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(WIFI_CONNECTION_TIMEOUT);
        Serial.println("Not connected yet");
    }

    Serial.print("Connected to: ");
    Serial.println(WiFi.localIP());
}

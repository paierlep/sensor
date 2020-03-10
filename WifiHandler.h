#ifndef WIFI_HANDLER_H
#define WIFI_HANDLER_H

#include "Arduino.h"

#include <ESP8266WiFi.h>

/**
 * WifiHandler
 *
 * a class to seperate the responsibility of connecting
 * in a power saving way to the wifi
 * therefore static ip is used (no DHCP!)
 */

class WifiHandler
{
  public:
    WifiHandler(String appName, String ssid, String passwd);
    void setIp(int octet1, int octet2, int octet3, int octet4);
    void setGateway(int octet1, int octet2, int octet3, int octet4);
    void setSubnet(int octet1, int octet2, int octet3, int octet4);
    void init();
    void switchOn();

  private:
    String m_appName;
    String m_ssid;
    String m_passwd;
    IPAddress m_ip;
    IPAddress m_gateway;
    IPAddress m_subnet;
};

#endif

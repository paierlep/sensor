#include <ESP8266HTTPClient.h>

#include "MessageHandler.h"

MessageHandler::MessageHandler(String baseUrl)
{
  m_baseUrl = baseUrl;
}

void MessageHandler::sendJson(String json)
{
    HTTPClient http;
    http.begin(m_baseUrl);
    http.addHeader("Content-Type", "application/json");
    http.POST(json);
    http.end();
}

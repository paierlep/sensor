#include "Sensor.h"
#include "Config.h"

#include <brzo_i2c.h>

Sensor::Sensor()
  : m_i2c_ack_timeout(I2C_ACK_TIMEOUT),
    m_temperature(NAN),
    m_humidity(NAN),
    m_pressure(NAN),
    m_temperatureUnit(BME280::TempUnit_Celsius),
    m_pressureUnit(BME280::PresUnit_hPa)
{
}

void Sensor::init()
{
    brzo_i2c_setup(SDA, SCL, m_i2c_ack_timeout);

    while(!m_bme.begin())
    {
        Serial.println("Could not find BME280 sensor!");
        delay(SENSOR_CONNECTION_TIMEOUT);
    }
}

void Sensor::loadNewData()
{
    m_bme.read(m_pressure, m_temperature, m_humidity, m_temperatureUnit, m_pressureUnit);
}

float Sensor::getPressure()
{
  return m_pressure;
}

float Sensor::getTemperature()
{
  return m_temperature;
}

float Sensor::getHumidity()
{
  return m_humidity;
}

String Sensor::getJson()
{
  return "{"
    "\"sensor\": " + NAME + ","
    "\"temperature\": " + String(m_temperature) + ","
    "\"humidity\":  " + String(m_humidity) + ","
    "\"pressure\":  " + String(m_pressure) + "}";
}

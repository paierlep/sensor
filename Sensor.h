#ifndef SENSOR_H
#define SENSOR_H

#include <BME280I2C_BRZO.h>
#include <EnvironmentCalculations.h>

/**
 * BME Sensor class
 *
 * wrapper for the BME280 sensor for more
 * convenient usage
 */
class Sensor
{
  public:
    Sensor();
    void init();
    void loadNewData();

    float getPressure();
    float getTemperature();
    float getHumidity();

    String getJson();

  private:
    int m_i2c_ack_timeout;
    float m_temperature;
    float m_humidity;
    float m_pressure;

    BME280::TempUnit m_temperatureUnit;
    BME280::PresUnit m_pressureUnit;

    BME280I2C_BRZO m_bme;
};

#endif

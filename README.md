# Humidity Sensor Project

Connect a ESP8266 with a BME280 to measure temperature, humidity and airpressure.
These measurments are send to a server to be sored within a database.

This program connects to a wifi, reads the sensor's data and sends those measurements
to an API in a json format. Finally the ESP8266 is send to deep sleep for a certain amount
of time

Most of the values (wifi data, interval between measurments etc)
are defined in the Config.h file.

Please refer also to:

- sensor-backend for the API
- sensor-ui for displaying the collected data

- brzo library
- a slightly modified BME280 library

## Components

- ESP 8288 NodeMCU Kit
- BME 280 Sensor
- some jumper wires
- a power source (e.g. a usb mini cable, 9V battery, ...)

### Connecting the components
Connect the BME 280 sensor to the ESP8288:

| BME280 | ESP8288  |
| ------:| -------- |
| VIN    | some VIN |
| GND    | some GND |
| SCL    | D1       |
| SDA    | D2       |

For deepSleep:

| ESP8288 | ESP8288 |
| -------:| ------- |
| D0      | RST     |

For battery/akku power sources:

| Battery                      | ESP8288 |
| ----------------------------:| ------- |
| postive  / red cable         | VIN     |
| negative / GND / black cable | GND     |

# Installing / Compiling

- Install the Arduino IDE
- Add http://arduino.esp8266.com/stable/package_esp8266com_index.json as additional Boards Manger URL under File>Preferences (multiple entries can be separated with a comma)
- Open the Boards Manager (Tools>Board>Boards Manager) and search for `esp8266` and install the resulting package (should show up as `ESP8266 by ESP8266 Community`)
- Select NodeMCU 1.0 under Tools>Board
- Select the correct port (e.g. the USB port) under Tools>Port)
- Install the brzo library by opening the Library Manager (Tools>Library Manager) and searching for brzo (should show up as `Brzo i2c by Pascal Kurtansky`)
- Install the BME280 library: do not use the Library Manager but extract directly the patched version from [...] into your libraries directory (e.g, so that  ~/Arduino/libraries/BME280 contains the source of the package)
- *COPY the Config.h_examples to Config.h and replace the values if necessary* - be aware that this program only supports static ip addresses (no DHCP!)
- Press the upload button - this does not work if the reset cable is connected - so disconnect it first!

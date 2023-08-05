#include <Arduino.h>
#include <SparkFunWeatherShield.h>
#include "thingProperties.h"

#define SERIAL_SPEED 9600

WeatherShield weather;

volatile unsigned int delay_ms = 1000;
unsigned long acum;

void setup() {
  Serial.begin(SERIAL_SPEED);
  delay(1500);

  Debug.setDebugLevel(DBG_VERBOSE);
  Debug.setDebugOutputStream(&Serial);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  
  weather.begin(); // enable I2C & sensors
  
  acum = millis();
}

void loop() {
  ArduinoCloud.update();
  
  weather.loop();

  unsigned long current = millis();
  if (current - acum < delay_ms) return;
  acum = current;

  float hum = weather.readHumidity();
  if (hum == ERROR_I2C_TIMEOUT) Serial.println("I2C error."); // humidty sensor failed to respond
  else {
    humidity = hum;
    pressure = weather.readPressure();
    temperature = weather.readTemperature();
  }

  if (weather.decodeWindDirection(weather.getWindDirection()) == -1) Serial.println("Unconnected external sensors.");
  else wind_speed = weather.getWindSpeedKm() * (3600.0/1000.0); // wind_speed is in m/s, not km/h
  
  rain = weather.getRain();
}
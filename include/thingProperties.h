#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>
#include "arduino_secrets.h"

const char DEVICE_LOGIN_NAME[]  = SECRET_DEVICE_LOGIN_NAME;
const char SSID[]               = SECRET_SSID;
const char PASS[]               = SECRET_SSID_PASS;
const char DEVICE_KEY[]         = SECRET_DEVICE_KEY;


float humidity;
float pressure;
float rain;
CloudTemperatureSensor temperature;
CloudVelocity wind_speed;

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(humidity, READ, ON_CHANGE, NULL, 5);
  ArduinoCloud.addProperty(pressure, READ, ON_CHANGE, NULL, 1);
  ArduinoCloud.addProperty(rain, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(temperature, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(wind_speed, READ, ON_CHANGE, NULL, 1);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);

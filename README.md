# Arduino IoT Cloud Weather Station

This repo adapts the code of my other project [Weather Station - Domótica](https://github.com/rogermiranda1000/Domotica/tree/master#m%C3%B3dulo-estaci%C3%B3n-meteorol%C3%B3gica) to publish the data to [Arduino IoT Cloud](https://cloud.arduino.cc/) instead of MQTT. You'll find [in my original project](https://github.com/rogermiranda1000/Domotica/tree/master#m%C3%B3dulo-estaci%C3%B3n-meteorol%C3%B3gica) the steps to build the Weather Station itself.

### Needed hardware

- Weather Station (discussed in the other repo)
- [Arduino UNO R4 Wifi](https://store.arduino.cc/products/uno-r4-wifi)

### Software setup

- Create a [new IoT thing](https://create.arduino.cc/iot/things). During the creation you'll have to configure (if you haven't done it before) the board, where you'll get the `SECRET_DEVICE_KEY`.
- Add 3 `floats`: `humidity`, `pressure` and `rain`. Also add a `CloudTemperatureSensor` `temperature` and a `CloudVelocity` `wind_speed`. All the properties should be `READ_ONLY`.
- Create a `include/arduino_secrets.h` file that contains the WiFi to be used (`SECRET_SSID`) and its password (`SECRET_SSID_PASS`), the secret IoT key (`SECRET_DEVICE_KEY`), and the device ID (`SECRET_DEVICE_LOGIN_NAME`, found on the IoT thing, on the `ID` section below your board name).
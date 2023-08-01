#pragma one

/*  SparkFun Wind Sensor Library
    By: Nathan Seidle
    Updated: Roger Miranda
    
    Get speed and direction of the wind. */
    
#include <Arduino.h>

#define WSPEED 3
#define WDIR A0

class Wind {
public:
  Wind(uint8_t portSpeed = WSPEED, uint8_t portDirection = WDIR);
  
  /* public variables */
  
  /* public functions */
  void begin(); //Set board's pins
  float getWindSpeed(); //Returns the speed in MPH
  unsigned int getWindDirection();
  int decodeWindDirection(unsigned int adc);

private:
  /* private variables */
  uint8_t _portSpeed;
  uint8_t _portDirection;
  long _lastWindCheck;
  volatile long _lastWindIRQ;
  volatile uint8_t _windClicks;
  static Wind *_instance; //Instance used for interrupt; only the newest object will work
  
  /* private functions */

  // Activated by the magnet in the anemometer (2 ticks per rotation)
  static void wspeedIRQ(){
    if (millis() - Wind::_instance->_lastWindIRQ > 10) // Ignore switch-bounce glitches less than 10ms (142MPH max reading) after the reed switch closes
    {
      Wind::_instance->_lastWindIRQ = millis(); //Grab the current time
      Wind::_instance->_windClicks++; //There is 1.492MPH for each click per second.
    }
  }

  int averageAnalogRead(uint8_t pinToRead);
};

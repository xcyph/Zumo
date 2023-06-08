#ifndef ZUMO_H
#define ZUMO_H

#include <Zumo32U4.h>
#include <Wire.h>

class Zumo {
public:
  Zumo();
  void setup();
  void loop();
  void kleurHerkenning();
  
private:
  Zumo32U4ButtonA buttonA;
  Zumo32U4LineSensors lijnSensor;
  Zumo32U4Motors motors;

  void SensCali();
  void shRead();
};

#endif

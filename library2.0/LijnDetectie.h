#ifndef LijnDetectie_H
#define LijnDetectie_H

#include <Zumo32U4.h>
#include <Wire.h>
#include "motoren.h"
#include "Buttons.h"

class LijnHerkenning {
public:
  LijnHerkenning();
  void calibratie();
  void volgen();
  void SensCali();
  void shRead();
private:
  ButtonA buttonA;
  Zumo32U4LineSensors lijnSensor;
  motoren motorslijn;
};

#endif

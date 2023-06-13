#ifndef LijnDetectie_H
#define LijnDetectie_H

#include <Zumo32U4.h>
#include <Wire.h>

class LijnHerkenning {
public:
  LijnHerkenning();
  void calibratie();
  void volgen();
  void SensCali();
  void shRead();
private:

};

#endif

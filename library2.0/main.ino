#include <BlokDetectie.h>
#include <Buttons.h>
#include <LijnDetectie.h>

#include <Besturing.h>
#include <Gyro.h>

Balanceren Balanceren;
motoren rijden;
Zumo32U4ButtonA buttonA;



void setup() {
  //gyro initializeren 
  Balanceren.init();
  Balanceren.averageYOffset();
  while(!buttonA.getSingleDebouncedPress()) {
    Balanceren.updateGyroAngle();
    Balanceren.correctWithAccelAngle();
  }
  //lijndetectie initializeren
  

}

void loop() {
 

}
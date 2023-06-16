#include "Besturing.h"

#include "BlokDetectie.h"

#include "Buttons.h"

#include "Gyro.h"

#include "LijnDetectie.h"

#include "XBEE.h"

#include "KleurHerkenning.h"

LijnHerkenning lijn;
Balanceren Balanceren;
motoren motors1;
ButtonA knopa;
ButtonB knopb;
BlokDetectie blok;
KleurHerkenning kl1;

bool primer = false;
bool naarlinks = false;
bool naarrechts = false;
int forgem = 0;

#define NUM_SENSORS 5
uint16_t drieSensors1[NUM_SENSORS];

void setup() {

  //Gyro initializeren
  Balanceren.init();
  Balanceren.averageYOffset();

  //LijnDetectie initializeren              
  lijn.calibratie();

  //BlokDetectie initializeren
  blok.init();

}

void loop() {
    int forgem1 = 0;
    const int d = drieSensors1[0];
    const int e = drieSensors1[4];
    int gemi = (d + e) / 2;

    Balanceren.updateGyroAngle();
    Balanceren.correctWithAccelAngle();
    Balanceren.printAngles();

    //lijn volgen
    if (!kl1.grijs() || !kl1.bruin() || !primer) {
      lijn.volgen();

      if (kl1.bruin()) { //blokje wegduwen
        motors1.setMotorSpeed(100, 100);
        delay(1000);
        motors1.setMotorSpeed(0, 0);
        blok.read();
        blok.rijden();

      }

      if (gemi > 300 && !primer) {
        for (int i = 0; i < 50; i++) {
          if ((d > 400) && (d < 700)) {
            naarlinks = true;
            naarrechts = false;
            primer = true;
            forgem += d;
          } else if ((e > 400) && (e < 700)) {
            naarrechts = true;
            naarlinks = false;
            primer = true;
            forgem += e;
          }
        }
        forgem /= 50;
        if (forgem1 > 700) {
          naarlinks = false;
          naarrechts = false;
          primer = false;
        }

      }
      if (primer) {
        if (d > 800 && naarlinks) {
          motors1.setMotorSpeed(-200, 200);
          delay(500);
          motors1.setMotorSpeed(0, 0);
          delay(1000);
          naarlinks = false;
          naarrechts = false;
          primer = false;
        } else if (e > 800 && naarrechts) {
          motors1.setMotorSpeed(200, -200);
          delay(500);
          motors1.setMotorSpeed(0, 0);
          delay(1000);
          naarlinks = false;
          naarrechts = false;
          primer = false;
        }

      }
      if (kl1.grijsl()) {
        motors1.setMotorSpeed(200, 200);
        delay(1500);
        motors1.setMotorSpeed(-200, 200);
        delay(1500);
        motors1.setMotorSpeed(0, 0);
      }
      if (kl1.grijsr()) {
        motors1.setMotorSpeed(200, 200);
        delay(1500);
        motors1.setMotorSpeed(200, -200);
        delay(1500);
        motors1.setMotorSpeed(0, 0);
      }

      Serial.println(kl1.grijs());
      Serial.println(kl1.bruin());

      if (kl1.grijs()) { //wipwap
        if (Balanceren.testAngle(-80)) {
          motors1.setMotorSpeed(200, 200);
        } else {
          motors1.setMotorSpeed(0, 0);
        }
      }
    }

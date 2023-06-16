#include "motoren.h"
#include "BlokDetectie.h"
#include "Buttons.h"
#include "Balanceren.h"
#include "LijnDetectie.h"
#include "XBEE.h"
#include "KleurHerkenning.h"

LijnHerkenning lijn;
Balanceren balanceren;
motoren motors1;
ButtonA knopA;
ButtonB knopB;
BlokDetectie blok;
KleurHerkenning kl1;

bool primer = false;         // Boolean voor de grijs waardes
bool naarlinks = false;      // Boolean om de richting naar links bij te houden
bool naarrechts = false;     // Boolean om de richting naar rechts bij te houden
int forgem = 0;              // Variabele voor het gemiddelde van de sensoren

#define NUM_SENSORS 5
uint16_t drieSensors1[NUM_SENSORS];

void setup() {
  // Gyro initialiseren
  balanceren.init();         
  balanceren.averageYOffset();

  // LijnDetectie initialiseren
  lijn.calibratie();

  // BlokDetectie initialiseren
  blok.init();
}

void loop() {
  int forgem1 = 0;
  const int d = drieSensors1[0];
  const int e = drieSensors1[4];
  int gemi = (d + e) / 2;
  //methode voor de gyro
  balanceren.updateGyroAngle();         
  balanceren.correctWithAccelAngle();
  balanceren.printAngles();

  // Lijn volgen
  if (!kl1.grijs() || !kl1.bruin() || !primer) {
    lijn.volgen();

    if (kl1.bruin()) { // Blokje wegduwen
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
  }
}

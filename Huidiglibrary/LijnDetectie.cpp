#include "LijnDetectie.h"
#include "KleurHerkenning.h"

#define NUM_SENSORS 5
uint16_t lineSensorValues[NUM_SENSORS];

int maxSnel = 0;

Zumo32U4ButtonA buttonA;      // Button object voor het bedienen van de ZUMO-knop
Zumo32U4LineSensors lijnSensor;      // LineSensors object voor het lezen van de lijnsensoren
Zumo32U4Motors motors;      // Motors object voor het aansturen van de motoren
KleurHerkenning kl;      // KleurHerkenning object voor het herkennen van kleuren

int16_t laatsteError = 0;      // Variabele voor het bijhouden van de laatste foutwaarde

LijnHerkenning::LijnHerkenning() {
  // Constructor
}

void LijnHerkenning::SensCali() {
  // Kalibreert de lijnsensoren door de robot naar links en rechts te bewegen
  for (uint16_t i = 0; i < 120; i++) {
    if (i > 30 && i <= 90) {
      motors.setSpeeds(-150, 150);
    } else {
      motors.setSpeeds(150, -150);
    }
    lijnSensor.calibrate();
  }
  motors.setSpeeds(0, 0);      // Stopt de motoren na kalibratie
}

void LijnHerkenning::shRead() {
  // Leest de gekalibreerde waarden van de lijnsensoren totdat de ZUMO-knop wordt ingedrukt
  while (!buttonA.getSingleDebouncedPress()) {
    lijnSensor.readCalibrated(lineSensorValues);
  }
}

void LijnHerkenning::calibratie() {
  // Initialiseert de vijf lijnsensoren en wacht op de ZUMO-knop
  lijnSensor.initFiveSensors();
  buttonA.waitForButton();
  SensCali();      // Voert de kalibratie van de lijnsensoren uit
  shRead();      // Leest de gekalibreerde waarden van de lijnsensoren
}

void LijnHerkenning::volgen() {
  kl.leesWaardes();      // Leest de kleurwaarden
  bool f = kl.groen();      // Controleert of de gedetecteerde kleur groen is

  int16_t positie = lijnSensor.readLine(lineSensorValues);      // Leest de positie van de zwarte lijn
  Serial.println(positie);      // Geeft de positie weer in de seriële monitor
  int16_t error = positie - 1100;      // Berekent de foutwaarde

  int16_t snelheidVerschil = error / 4 + 6 * (error - laatsteError);      // Berekent het snelheidsverschil op basis van de foutwaarde

  Serial.println(f);      // Geeft de kleurwaarde (true/false) weer in de seriële monitor

  if (f) {
    maxSnel = 150;      // Stelt de maximale snelheid in op 150 als de gedetecteerde kleur groen is
  }
  else {
    maxSnel = 300;      // Stelt de maximale snelheid in op 300 als de gedetecteerde kleur niet groen is
  }

  laatsteError = error;      // Slaat de huidige foutwaarde op voor gebruik in de volgende iteratie

  int16_t linksSpeed = maxSnel + snelheidVerschil;      // Berekent de motorsnelheid voor de linker motor
  int16_t rechtsSpeed = maxSnel - snelheidVerschil;      // Berekent de motorsnelheid voor de rechter motor

  linksSpeed = constrain(linksSpeed, -250, maxSnel);      // Beperkt de motorsnelheid binnen een bepaald bereik
  rechtsSpeed = constrain(rechtsSpeed, -250, maxSnel);      // Beperkt de motorsnelheid binnen een bepaald bereik

  motors.setSpeeds(linksSpeed, rechtsSpeed);      // Stelt de motorsnelheden in
}

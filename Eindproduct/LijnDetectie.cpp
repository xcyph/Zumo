#include "LijnDetectie.h"  // Inclusie van een headerbestand 
#define NUM_SENSORS 5  // Definitie van het aantal lijnsensoren
uint16_t lineSensorValues[NUM_SENSORS];  // Array om lijnsensorwaarden op te slaan

const uint16_t maxSnelheid = 300;  // Maximale snelheid van de motoren
int16_t laatsteError = 0;  // Variabele om de vorige foutwaarde bij te houden

LijnHerkenning::LijnHerkenning() {
  // Constructor voor de klasse LijnHerkenning
}

void LijnHerkenning::SensCali() {
  for (uint16_t i = 0; i < 120; i++) {
    if (i > 30 && i <= 90) {
      motorslijn.setMotorSpeed(-150, 150);  // Instellen van de motorsnelheid
    } else {
      motorslijn.setMotorSpeed(150, -150);  // Instellen van de motorsnelheid
    }
    lijnSensor.calibrate();  // Kalibreren van de lijnsensor
  }
  motorslijn.setMotorSpeed(0, 0);  // Stoppen van de motoren
}

void LijnHerkenning::shRead() {
  while (!buttonA.getSingleDebouncedPress()) {
    lijnSensor.readCalibrated(lineSensorValues);  // Uitlezen van gekalibreerde lijnsensorwaarden
  }
}

void LijnHerkenning::calibratie() {
  lijnSensor.initFiveSensors();  // Initialiseren van vijf lijnsensoren
  buttonA.waitForButton();  // Wachten op een knopdruk van buttonA
  SensCali();  // Uitvoeren van de kalibratieprocedure
  shRead();  // Uitvoeren van de leesprocedure van de lijnsensor
}

void LijnHerkenning::volgen() {
  int16_t positie = lijnSensor.readLine(lineSensorValues);  // Uitlezen van lijnsensorwaarden en bepalen van de positie
  Serial.println(positie);  // Afdrukken van de positie naar de seriële monitor
  int16_t error = positie - 1100;  // Bepalen van de foutwaarde

  int16_t snelheidVerschil = error / 4 + 6 * (error - laatsteError);  // Bepalen van het snelheidsverschil

  laatsteError = error;  // Bijwerken van de vorige foutwaarde

  int16_t linksSpeed = (int16_t)maxSnelheid + snelheidVerschil;  // Berekenen van de motorsnelheid voor de linker motor
  int16_t rechtsSpeed = (int16_t)maxSnelheid - snelheidVerschil;  // Berekenen van de motorsnelheid voor de rechter motor

  linksSpeed = constrain(linksSpeed, -250, (int16_t)maxSnelheid);  // Beperken van de linker motorsnelheid binnen een bepaald bereik
  rechtsSpeed = constrain(rechtsSpeed, -250, (int16_t)maxSnelheid);  // Beperken van de rechter motorsnelheid binnen een bepaald bereik

  motorslijn.setMotorSpeed(linksSpeed, rechtsSpeed);  // Instellen van de motorsnelheden
}

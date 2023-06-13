#include "LijnDetectie.h"
#include "Besturing.h"
#include "Buttons.h"
#define NUM_SENSORS 5
uint16_t lineSensorValues[NUM_SENSORS];

ButtonA buttonA;
Zumo32U4LineSensors lijnSensor;
motoren motorslijn;

const uint16_t maxSnelheid = 300;
int16_t laatsteError = 0;

LijnHerkenning::LijnHerkenning() {
  // Constructor
}

void LijnHerkenning::SensCali() {
  for (uint16_t i = 0; i < 120; i++) {
    if (i > 30 && i <= 90) {
      motorslijn.setMotorSpeed(-150, 150);
    } else {
      motorslijn.setMotorSpeed(150, -150);
    }
    lijnSensor.calibrate();
  }
  motorslijn.setMotorSpeed(0, 0);
}

void LijnHerkenning::shRead() {
  while (!buttonA.getSingleDebouncedPress()) {
    lijnSensor.readCalibrated(lineSensorValues);
  }
}

void LijnHerkenning::calibratie() {
  lijnSensor.initFiveSensors();
  buttonA.waitForButton();
  SensCali();
  shRead();
}

void LijnHerkenning::volgen() {
  int16_t positie = lijnSensor.readLine(lineSensorValues);
  Serial.println(positie);
  int16_t error = positie - 1100;

  int16_t snelheidVerschil = error / 4 + 6 * (error - laatsteError);

  laatsteError = error;

  int16_t linksSpeed = (int16_t)maxSnelheid + snelheidVerschil;
  int16_t rechtsSpeed = (int16_t)maxSnelheid - snelheidVerschil;

  linksSpeed = constrain(linksSpeed, -250, (int16_t)maxSnelheid);
  rechtsSpeed = constrain(rechtsSpeed, -250, (int16_t)maxSnelheid);

  motorslijn.setMotorSpeed(linksSpeed, rechtsSpeed);
}

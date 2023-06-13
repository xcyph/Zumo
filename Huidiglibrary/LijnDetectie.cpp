#include "LijnDetectie.h"
#include "KleurHerkenning.h"

#define NUM_SENSORS 5
uint16_t lineSensorValues[NUM_SENSORS];

int maxSnel = 0;

Zumo32U4ButtonA buttonA;
Zumo32U4LineSensors lijnSensor;
Zumo32U4Motors motors;
KleurHerkenning kl;

int16_t laatsteError = 0;

LijnHerkenning::LijnHerkenning() {
  // Constructor
}

void LijnHerkenning::SensCali() {
  for (uint16_t i = 0; i < 120; i++) {
    if (i > 30 && i <= 90) {
      motors.setSpeeds(-150, 150);
    } else {
      motors.setSpeeds(150, -150);
    }
    lijnSensor.calibrate();
  }
  motors.setSpeeds(0, 0);
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
  // lijnSensor.read(lineSensorValues);
  // const int a = lineSensorValues[1];
  // const int b = lineSensorValues[2];
  // const int c = lineSensorValues[3];
  // const int gem = (a+b+c);
  kl.leesWaardes();
  bool f = kl.groen();

  int16_t positie = lijnSensor.readLine(lineSensorValues);
  Serial.println(positie);
  int16_t error = positie - 1100;

  int16_t snelheidVerschil = error / 4 + 6 * (error - laatsteError);

  Serial.println(f);

  if (f) {
    maxSnel = 150;
  }
  else {
    maxSnel = 300;
  }

  laatsteError = error;

  int16_t linksSpeed = maxSnel + snelheidVerschil;
  int16_t rechtsSpeed = maxSnel - snelheidVerschil;

  linksSpeed = constrain(linksSpeed, -250, maxSnel);
  rechtsSpeed = constrain(rechtsSpeed, -250, maxSnel);

  motors.setSpeeds(linksSpeed, rechtsSpeed);
}

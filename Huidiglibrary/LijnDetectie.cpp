#include "LijnDetectie.h"

#define NUM_SENSORS 5
unsigned int lineSensorValues[NUM_SENSORS];

const uint16_t maxSnelheid = 300;
int16_t laatsteError = 0;

Zumo::Zumo() {
  // Constructor
}

void Zumo::SensCali() {
  for (uint16_t i = 0; i < 120; i++) {
    if (i > 30 && i <= 90) {
      motors.setSpeeds(-200, 200);
    } else {
      motors.setSpeeds(200, -200);
    }
    lijnSensor.calibrate();
  }
  motors.setSpeeds(0, 0);
}

void Zumo::shRead() {
  while (!buttonA.getSingleDebouncedPress()) {
    lijnSensor.readCalibrated(lineSensorValues);
  }
}

void Zumo::kleurHerkenning() {
    lijnSensor.read(lineSensorValues);
    const int a = lineSensorValues[1];
    const int b = lineSensorValues[2];
    const int c = lineSensorValues[3];
    const int gem = (a+b+c)/3;

    Serial.println(gem);

    // Return kleur voor later zodat we alles kunnen koppelen
    if ((gem < 230) && (gem > 170)) { // groen
        Serial.println("groen");
    }
    else if ((gem < 330) && (gem > 230)) { // bruin
        Serial.println("bruin");
    }
    else if ((gem < 500) && (gem > 330)) { // zwart
        Serial.println("zwart");
    }
};

void Zumo::setup() {
  lijnSensor.initFiveSensors();
  buttonA.waitForButton();
  SensCali();
  shRead();
}

void Zumo::loop() {
  int16_t positie = lijnSensor.readLine(lineSensorValues);

  int16_t error = positie - 1000;

  int16_t snelheidVerschil = error / 4 + 6 * (error - laatsteError);

  laatsteError = error;

  int16_t linksSpeed = (int16_t)maxSnelheid + snelheidVerschil;
  int16_t rechtsSpeed = (int16_t)maxSnelheid - snelheidVerschil;

  linksSpeed = constrain(linksSpeed, 0, (int16_t)maxSnelheid);
  rechtsSpeed = constrain(rechtsSpeed, 0, (int16_t)maxSnelheid);

  motors.setSpeeds(linksSpeed, rechtsSpeed);
}

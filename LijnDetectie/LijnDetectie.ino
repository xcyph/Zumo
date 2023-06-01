#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4ButtonA buttonA;
Zumo32U4Motors motors;
Zumo32U4LineSensors lineSensors;

#define NUM_SENSORS 5
uint16_t lineSensorValues[NUM_SENSORS];

void setup()
{
  lineSensors.initFiveSensors();
  buttonA.waitForButton();
  lineSensors.calibrate();
}

void printReadingsToSerial()
{
  char buffer[80];
  sprintf(buffer, "%4d %4d %4d %4d %4d %c\n",
    lineSensorValues[0],
    lineSensorValues[1],
    lineSensorValues[2],
    lineSensorValues[3],
    lineSensorValues[4]
);

  const int a = lineSensorValues[1];
  const int b = lineSensorValues[2];
  const int c = lineSensorValues[3];
  const int gem = (a+b+c)/3;
  
  const int d = lineSensorValues[0];
  const int e = lineSensorValues[4];
  const int gemi = (a+b)/2;

  lineSensors.read(lineSensorValues);
  
  if ((gem < 210) && (gem > 170)) { // groen
    Serial.println("groen");
  }
  else if ((gem < 260) && (gem > 230)) { // bruin
    Serial.println("bruin");
  }
  else if ((gem < 500) && (gem > 330)) { // zwart
    Serial.println("zwart");
  }
}

void loop()
{
  static uint16_t lastSampleTime = 0;
  if ((uint16_t)(millis() - lastSampleTime) >= 100)
  {
    lastSampleTime = millis();
    lineSensors.read(lineSensorValues);
    printReadingsToSerial();
  }
}

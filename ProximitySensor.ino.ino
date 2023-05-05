#include <Zumo32U4.h> 
#include <Wire.h>

Zumo32U4ProximitySensors sensor;
Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;

//Kijkt of we rijden of niet
bool drive = false;

void setup()
{
  //Init de proximity sensors
  sensor.initFrontSensor();
  buttonA.waitForButton();
}

void stop()
{
  motors.setSpeeds(0, 0);
}

void loop()
{
  //Als buttonA wordt ingedrukt, dan gaan we rijden
  if (buttonA.isPressed()) {
    drive = true;
  }

  if (drive = true) {
    motors.setSpeeds(400,400);
  }

  sensor.read();
  bool front = sensor.readBasicFront();
  
  if (front) {
    drive = false;
    stop();
  }
}

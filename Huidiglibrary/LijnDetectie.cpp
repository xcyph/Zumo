#include <LijnDetectie.h>
#include <Zumo32U4.h>
#include <Wire.h>

Zumo32U4LineSensors lol;
Zumo32U4Motors motors;

using namespace std;
#define NUM_SENSORS 5
uint16_t lineSensorValues[NUM_SENSORS];

const uint16_t maxSnelheid = 200;
int16_t laatsteError = 0;

void LijnDet::starter() {
    lol.initFiveSensors();
    lol.readCalibrated(lineSensorValues);
};

LijnDet::kleurHerkenning() {
    lol.read(lineSensorValues);
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


void LijnDet::calibreren(){
  for (uint16_t i = 0; i < 120; i++){
    if(i > 30 && i <= 90){
      motors.setSpeeds(-200,200);
    }else{
      motors.setSpeeds(200,-200);
    }
    lol.calibrate();
  }
  motors.setSpeeds(0,0);
}

void LijnDet::zelfRijden() {
  // put your main code here, to run repeatedly:
  int16_t positie = lol.readLine(lineSensorValues);
  //error
  int16_t error = positie - 1000;
  // verschilspeed
  int16_t snelheidVerschil = error / 4 + 6 * (error - laatsteError);

  laatsteError = error;

  //bepaal wnr de robot naar links en rechts draait 
  int16_t linksSpeed = (int16_t)maxSnelheid + snelheidVerschil;
  int16_t rechtsSpeed = (int16_t)maxSnelheid - snelheidVerschil;

  linksSpeed = constrain(linksSpeed, 0, (int16_t)maxSnelheid);
  rechtsSpeed = constrain(rechtsSpeed,0, (int16_t)maxSnelheid);

  motors.setSpeeds(linksSpeed, rechtsSpeed);
}

// lol

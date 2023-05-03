//Zumo class 
#include <Zumo32U4.h>
#include <Wire.h>

//snelheid
const uint16_t maxSnelheid = 300;

//initializatie van button A
Zumo32U4ButtonA buttonA;
Zumo32U4LineSensors lijnSensor;
Zumo32U4Motors motors;

int16_t laatsteError = 0;

//def pnr sensor
#define NUM_SENSORS 5
unsigned int lineSensorValues[NUM_SENSORS];

//SensorCalibreren

void SensCali(){
  for (uint16_t i = 0; i < 120; i++){
    if(i > 30 && i <= 90){
      motors.setSpeeds(-200,200);
    }else{
      motors.setSpeeds(200,-200);
    }

    lijnSensor.calibrate();
  }
  motors.setSpeeds(0,0);
}





void shRead(){
  while(!buttonA.getSingleDebouncedPress()){
    lijnSensor.readCalibrated(lineSensorValues);
  }
}


void setup() {
  // put your setup code here, to run once:
  lijnSensor.initFiveSensors();

  //wacht zodat die buttonA is geklikt
  buttonA.waitForButton();

  SensCali();

  shRead();


}

void loop() {
  // put your main code here, to run repeatedly:
  int16_t positie = lijnSensor.readLine(lineSensorValues);
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


  // Serial.print(error);


}

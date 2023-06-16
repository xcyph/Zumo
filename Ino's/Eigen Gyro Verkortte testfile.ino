#include <motoren.h>
#include <Gyro.h>

Balanceren Balanceren;
motoren rijden;
Zumo32U4ButtonA buttonA;

void setup() {
  Balanceren.init();
  Balanceren.averageYOffset();
  
  while(!buttonA.getSingleDebouncedPress()) {
    Balanceren.updateGyroAngle();    
    Balanceren.correctWithAccelAngle();
  }
  
}

void loop() {
  Balanceren.updateGyroAngle();
  Balanceren.correctWithAccelAngle();
  //Balanceren.printAngles();

  if (Balanceren.testAngle(-84)) {    //Als de Zumo horizontaal staat met de batterijen naar beneden, heeft dit een Gyro-angle van -90
    rijden.vooruit(200);
  }
  else {
    rijden.stop();
  }

}

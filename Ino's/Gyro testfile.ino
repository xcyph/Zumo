#include <motoren.h>
#include <Balanceren.h>

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

  if (Balanceren.testAngle(-84, -40)) {    //Als de Zumo horizontaal staat met de batterijen naar beneden, heeft dit een Gyro-angle van -90. Ik heb in deze testfile -84 als waarde gebruikt om te zorgen dat de Zumo niet de hele tijd weg probeert te rijden.
    rijden.vooruit(200);
  }
  else {
    rijden.stop();
  }

}

#include <motoren.h>
#include <XBEE.h>

XBEE XBEE1(9600);
motoren rijden;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  if (XBEE1.available()) {
    char ontvangen = XBEE1.read();
    if(ontvangen == 'w') {
      rijden.vooruit(200);
    }
    else if (ontvangen == 'a') {
      rijden.linksomDraaien(200);
    }
    else if (ontvangen == 's') {
      rijden.achteruit(200);
    }
    else if (ontvangen == 'd') {
      rijden.rechtsomDraaien(200);
    }
    else if (ontvangen == 'q') {
      rijden.setMotorSpeed(100, 200);
    }
    else if (ontvangen == 'e') {
      rijden.setMotorSpeed(200, 100);
    }
    else {
      rijden.stop();
    }
  }
}

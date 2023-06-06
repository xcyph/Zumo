#include <BlokDetectie.h>
Zumo32U4Motors motors;                                                          //het object motors wordt gemaakt
Zumo32U4ProximitySensors prox;                                                  //het object prox wordt gemaakt
BlokDetectie :: BlokDetectie (): leftValue(0), rightValue(0), gevonden(false)   //constructor van blokdetectie
{ 

}

BlokDetectie :: ~BlokDetectie()                                                 //destructor van blokdetectie
{

}


void BlokDetectie :: init() {                                                   //hier wordt de proximitysensor geinitialiseerd                                            
prox.initFrontSensor();

}

void BlokDetectie :: read()                                                    //hier worden de waardes vanuit de linker en rechter gelezen
{
  prox.read();
  leftValue = prox.countsFrontWithLeftLeds();
  rightValue = prox.countsFrontWithRightLeds();

}

void BlokDetectie :: rijden(){                                                  //deze methode wordt weg gegooit 
   

    if (gevonden == false) 
{
    motors.setSpeeds(200,-200);
}
    if ( (leftValue + rightValue) >= 9 )
{
    gevonden = true; 
    motors.setSpeeds(200,200);


    if (leftValue > rightValue) 
{
    motors.setSpeeds(200, 250);
}
    else if (rightValue > leftValue) 
{
    motors.setSpeeds(250, 200);
}
}
}

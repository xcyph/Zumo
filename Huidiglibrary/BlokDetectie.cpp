#include <BlokDetectie.h>
Zumo32U4Motors motors; 
Zumo32U4ProximitySensors prox;
BlokDetectie :: BlokDetectie (): leftValue(0), rightValue(0), gevonden(false)
{ 

}

BlokDetectie :: ~BlokDetectie() 
{

}


void BlokDetectie :: init() {
prox.initFrontSensor();

}

void BlokDetectie :: read()
{
  prox.read();
  leftValue = prox.countsFrontWithLeftLeds();
  rightValue = prox.countsFrontWithRightLeds();

}

void BlokDetectie :: rijden(){
   

    if (gevonden == false) 
{
    motors.setSpeeds(200,-200);
}
    if ( (leftValue + rightValue) >= 9 )
{
    evonden = true; 
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

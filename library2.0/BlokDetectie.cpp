#include <BlokDetectie.h>
#include "Besturing.h"

BlokDetectie :: BlokDetectie (): leftValue(0), rightValue(0), gevonden(false)   //constructor van blokdetectie
{ 

}

BlokDetectie :: ~BlokDetectie()                                                 //destructor van blokdetectie
{

}


void BlokDetectie :: init() {                                                   //hier wordt de proximitysensor geinitialiseerd                                            
prox.initFrontSensor();

}

void BlokDetectie :: read()                                                     //hier worden de waardes vanuit de linker en rechter gelezen
{
  prox.read();
  leftValue = prox.countsFrontWithLeftLeds();
  rightValue = prox.countsFrontWithRightLeds();
  Serial1.print(leftValue);
  Serial1.print("\t");
  Serial1.println(rightValue);

}

void BlokDetectie :: rijden(){                                                  //deze methode wordt weg gegooit 
   

    if (gevonden == false) 
{
    motorsblok.setMotorSpeed(200,-200);
}
    if ( (leftValue + rightValue) >= 9 )
{
    gevonden = true; 
    motorsblok.setMotorSpeed(300,300);

}
else {
    gevonden = false;
}
    if (leftValue > rightValue) 
{
    motorsblok.setMotorSpeed(300, 350);
}
    else if (rightValue > leftValue) 
{
    motorsblok.setMotorSpeed(350, 300);
}

}

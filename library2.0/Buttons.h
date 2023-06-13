
#include <Pushbutton.h>
#include <FastGPIO.h>
#include <USBPause.h>

#define ZUMO_32U4_BUTTON_A 14              //de knoppen worden hier aan een pin gekoppeld
#define ZUMO_32U4_BUTTON_B IO_D5
#define ZUMO_32U4_BUTTON_C 17



class ButtonA : public PushbuttonBase       //dit is de klasse van de knop A 
{ 
public: 
virtual bool isPressed();                  

};

class ButtonB : public PushbuttonBase       //dit is de klasse van de knop B
{
public:
virtual bool isPressed();
  
};

class ButtonC : public PushbuttonBase       //dit is de klasse van de knop C
{
public:
virtual bool isPressed();
};




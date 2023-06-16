#include <Pushbutton.h>
#include <FastGPIO.h>
#include <USBPause.h>

#define ZUMO_32U4_BUTTON_A 14              // De knoppen worden hier aan een pin gekoppeld
#define ZUMO_32U4_BUTTON_B IO_D5
#define ZUMO_32U4_BUTTON_C 17

class ButtonA : public PushbuttonBase       // Dit is de klasse voor knop A
{ 
public: 
    virtual bool isPressed();                   // Methode om te controleren of knop A is ingedrukt
};

class ButtonB : public PushbuttonBase       // Dit is de klasse voor knop B
{
public:
    virtual bool isPressed();                 // Methode om te controleren of knop B is ingedrukt
};

class ButtonC : public PushbuttonBase       // Dit is de klasse voor knop C
{
public:
    virtual bool isPressed();                 // Methode om te controleren of knop C is ingedrukt
};

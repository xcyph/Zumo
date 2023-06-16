#include <Buttons.h>



bool ButtonA :: isPressed() //methode van knop A
    {
        /*deze methode zorgt er voor dat je de knop A kan indrukken en dat hij niet debounced
        dit geldt ook voor de andere methodes */

        USBPause usbPause; //dit object zorgt er voor dat alle usb onderbrekingen uit wordt gezet
        FastGPIO::PinLoan<ZUMO_32U4_BUTTON_A> loan; 
        FastGPIO::Pin<ZUMO_32U4_BUTTON_A>::setInputPulledUp();
        _delay_us(3);
        return !FastGPIO::Pin<ZUMO_32U4_BUTTON_A>::isInputHigh();
    }
bool ButtonB :: isPressed() //methode van knop B
{
        USBPause usbPause;
        FastGPIO::PinLoan<ZUMO_32U4_BUTTON_B> loan;
        FastGPIO::Pin<ZUMO_32U4_BUTTON_B>::setInputPulledUp();
        _delay_us(3);
        return !FastGPIO::Pin<ZUMO_32U4_BUTTON_B>::isInputHigh();
    }


bool ButtonC :: isPressed() //methode van knop C
{
        USBPause usbPause;
        FastGPIO::PinLoan<ZUMO_32U4_BUTTON_C> loan;
        FastGPIO::Pin<ZUMO_32U4_BUTTON_C>::setInputPulledUp();
        _delay_us(3);
        return !FastGPIO::Pin<ZUMO_32U4_BUTTON_C>::isInputHigh();
    }
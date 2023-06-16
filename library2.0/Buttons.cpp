#include <Buttons.h>

// Klasse voor knop A
bool ButtonA::isPressed()
{
    /*
    Deze methode zorgt ervoor dat je de knop A kunt indrukken zonder debounce.
    Dit geldt ook voor de andere methoden.
    */
   // Klasse voor knop B

    USBPause usbPause; // Dit object zorgt ervoor dat alle USB-onderbrekingen worden uitgeschakeld
    FastGPIO::PinLoan<ZUMO_32U4_BUTTON_B> loan; // Hier wordt een PinLoan-object gemaakt voor knop B
    FastGPIO::Pin<ZUMO_32U4_BUTTON_B>::setInputPulledUp(); // De knop B-pin wordt geconfigureerd als een ingang met pull-up weerstand
    _delay_us(3); // Een kleine vertraging van 3 microseconden om stabiele metingen te garanderen
    return !FastGPIO::Pin<ZUMO_32U4_BUTTON_B>::isInputHigh(); // Geeft de logische inverse van de huidige toestand van knop B terug (ingedrukt of niet)
}

}

// Klasse voor knop B
bool ButtonB::isPressed()
{
    USBPause usbPause;
    FastGPIO::PinLoan<ZUMO_32U4_BUTTON_B> loan;
    FastGPIO::Pin<ZUMO_32U4_BUTTON_B>::setInputPulledUp();
    _delay_us(3);
    return !FastGPIO::Pin<ZUMO_32U4_BUTTON_B>::isInputHigh();
}

// Klasse voor knop C
bool ButtonC::isPressed()
{
    USBPause usbPause;
    FastGPIO::PinLoan<ZUMO_32U4_BUTTON_C> loan;
    FastGPIO::Pin<ZUMO_32U4_BUTTON_C>::setInputPulledUp();
    _delay_us(3);
    return !FastGPIO::Pin<ZUMO_32U4_BUTTON_C>::isInputHigh();
}

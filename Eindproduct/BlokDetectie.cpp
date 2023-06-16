#include <BlokDetectie.h>

BlokDetectie::BlokDetectie(): leftValue(0), rightValue(0), gevonden(false)
{
    // Constructor van BlokDetectie
    // Initialiseert de objectvariabelen
}

BlokDetectie::~BlokDetectie()
{
    // Destructor van BlokDetectie
    // Wordt gebruikt om geheugen op te ruimen of bronnen vrij te geven
}

void BlokDetectie::init()
{
    // Initialiseert de proximitysensor
    prox.initFrontSensor();
}

void BlokDetectie::read()
{
    // Leest de waardes van de linker- en rechterzijde
    prox.read();
    leftValue = prox.countsFrontWithLeftLeds();
    rightValue = prox.countsFrontWithRightLeds();
}

void BlokDetectie::rijden()
{
    // Methode om de Zumo achter het blokje te laten rijden

    if (gevonden == false)
    {
        // Als het blokje nog niet is gevonden, draai naar links
        motorsblok.setMotorSpeed(200, -200);
    }

    if ((leftValue + rightValue) >= 9)
    {
        // Als de som van linker- en rechterwaarde groter of gelijk aan 9 is, is het blokje gevonden
        gevonden = true;
        motorsblok.setMotorSpeed(300, 300);
    }
    else
    {
        // Reset gevonden naar false als het blokje niet is gevonden
        gevonden = false;
    }

    if (leftValue > rightValue)
    {
        // Als linkerwaarde groter is dan rechterwaarde, draai naar rechts
        motorsblok.setMotorSpeed(300, 350);
    }
    else if (rightValue > leftValue)
    {
        // Als rechterwaarde groter is dan linkerwaarde, draai naar links
        motorsblok.setMotorSpeed(350, 300);
    }
}

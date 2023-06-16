#pragma once

#include <Wire.h>
#include <Zumo32U4.h>
#include "motoren.h"

// Deze code zorgt ervoor dat de Zumo het blokje vindt en deze uit de cirkel duwt
using namespace std;

class BlokDetectie
{ 
public: 
    BlokDetectie();             // Constructor van de klasse BlokDetectie
    ~BlokDetectie();            // Destructor van de klasse BlokDetectie 
    void init();                // Initialiseert de proximity sensor
    void read();                // Leest de waardes vanuit de proximitysensoren
    void rijden();              // Zorgt ervoor dat de Zumo het blokje volgt

private: 
    uint8_t leftValue;          // Wanneer de sensor iets ziet aan de linkerkant, wordt deze waarde verhoogd
    uint8_t rightValue;         // Wanneer de sensor iets ziet aan de rechterkant, wordt deze waarde verhoogd
    bool gevonden;              // Geeft aan of de sensor iets heeft gevonden (true) of niet (false)
    motoren motorsblok;         // Het object motors wordt aangemaakt
    Zumo32U4ProximitySensors prox;  // Het object prox wordt aangemaakt
};

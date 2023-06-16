 #pragma once

#include <Wire.h>
#include <Zumo32U4.h>
#include "motoren.h"

//deze code zorgt er voor dat de Zumo het blokje vindt en deze uit de cirkel duwt
using namespace std;

class BlokDetectie
{ 
public: 

BlokDetectie();                 //constructor klasse BlokDetectie
~BlokDetectie();                //destructor klasse BlokDetectie 
void init();                    //initializeren van de proximity sensor
void read();                    //het lezen van de waardes vanuit de proximitysensors
void rijden();                  //deze zorgt er voor dat de zumo het blokje volgt

private: 
uint8_t leftValue;              //wanneer de sensor iets ziet op links, dan gaat deze waarde omhoog
uint8_t rightValue;             //wanneer de sensor iets ziet op rechts, dan gaat deze waarde omhoog
bool gevonden;                  //wanneer de sensor iets gevonden heb dan gaat "gevonden" op true
motoren motorsblok;             //het object motors wordt gemaakt
Zumo32U4ProximitySensors prox;  //het object prox wordt gemaakt



};

 #pragma once

#include <Wire.h>
#include <Zumo32U4.h>


using namespace std;

class BlokDetectie : public Zumo32U4Motors, public Zumo32U4ProximitySensors 
{ 
public: 

BlokDetectie();
~BlokDetectie();
void init();
void read(); 
void rijden(); 

private: 
uint8_t leftValue;
uint8_t rightValue;
bool gevonden;



};
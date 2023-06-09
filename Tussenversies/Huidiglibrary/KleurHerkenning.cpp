#include "KleurHerkenning.h"
#include "LijnDetectie.h"

#define NUM_SENSORS 5
uint16_t drieSensors[NUM_SENSORS];

LijnHerkenning lijn;

int groenWaarde = 190;
int bruinWaarde = 0;

int range = 100;

KleurHerkenning::KleurHerkenning() {
  // Constructor
}

void KleurHerkenning::leesWaardes() {
  const int a = drieSensors[1];
  const int b = drieSensors[2];
  const int c = drieSensors[3];
  const int gem = (a+b+c)/3;
}

bool KleurHerkenning::groen() {
  if ((gem < (groenWaarde + range)) && (gem > (groenWaarde - range))) { // groen
    Serial.println("groen");
    return true;
  }
  else {
    return false;
  }
}

bool KleurHerkenning::bruin() {
  if ((gem < (bruinWaarde + range)) && (gem > (bruinWaarde - range))) { // groen
    Serial.println("bruin");
    return true;
  }
  else {
    return false;
  }
}

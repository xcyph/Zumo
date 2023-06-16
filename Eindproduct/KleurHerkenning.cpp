#include "KleurHerkenning.h"

#define NUM_SENSORS 5
uint16_t drieSensors[NUM_SENSORS];

// Hier worden de waardes van de gelezen kleuren gezet
int groenWaarde = 0; 
int grijsWaarde = 0;
int bruinWaarde = 0;

// Hier wordt de gevoeligheid aangepast. Hoe lager het getal, hoe speciefieker de waardes moeten zijn van de lijnsensoren.
int range = 0;

KleurHerkenning::KleurHerkenning() {
  // Constructor
}

// Hier worden de waardes van de middelste drie lijnsensoren uitgelezen. Hiervan wordt het gemiddelde berekend.
// Dit is ervoor bedoeld om ervoor te zorgen dat als de ZUMO schuin of niet perfect op de lijn staat,
// Nogsteeds een accurate waarde wordt uitgelezen die kan gebruikt worden om de kleuren de herkennen.
void KleurHerkenning::leesWaardes() {
  // Bedoeld voor de groene lijn
  const int a = drieSensors[1];
  const int b = drieSensors[2];
  const int c = drieSensors[3];
  const int gem = (a+b+c)/3;

  // Bedoeld om de grijze lijn te herkennen, die aan de buitenkanten staan van de lijnen.
  const int d = drieSensors[0];
  const int e = drieSensors[4];
  const int buiten = (d+e)/2;
}

// Kleuren worden hier herkent. Wat er gebeurt is dat eerst de gecalibreerde lijnsensor wordt uitgelezen.
// Daarna worden er gekeken of de waardes binnen de range vallen van die kleur
// Als dat zo is, wordt er true gereturned, die vervolgens gebruikt kan worden om andere functies te laten werken
// Die te maken hebben met kleuren.
bool KleurHerkenning::groen() {
  LijnHer.shRead();
  if ((gem < (groenWaarde + range)) && (gem > (groenWaarde - range))) { // groen
    Serial.println("groen");
    return true;
  }
  else {
    return false;
  }
}

bool KleurHerkenning::grijs() {
  LijnHer.shRead();
  if ((buiten < (grijsWaarde + range)) && (buiten > (grijsWaarde - range))) { // grijs
    Serial.println("grijs");
    return true;
  }
  else {
    return false;
  }
}

bool KleurHerkenning::bruin() {
  LijnHer.shRead();
  if ((gem < (bruinWaarde + range)) && (gem > (bruinWaarde - range))) { // groen
    Serial.println("bruin");
    return true;
  }
  else {
    return false;
  }
}

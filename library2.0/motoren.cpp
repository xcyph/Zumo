#include "motoren.h"

/*De constructor van de klasse motoren. Deze krijgt 2 private variabelen
mee die allebei geinitialiseerd worden met de waarde 0.*/
motoren::motoren():snelheidL(0), snelheidR(0) {
}
/*De destructor van de klasse motoren.*/
motoren::~motoren() {
}
/*In deze functie wordt de functie setSpeeds(int, int) van de ZUMO32U4Motors
library aangeroepen om de motoren te laten rijden. Er worden 2 int's
meegegeven, die opgeslagen worden in de desbetreffende variabelen en in de 
functie setSpeeds(int, int) worden gebruikt om de motoren mee aan te sturen.*/
void motoren::setMotorSpeed(int l, int r) {
    snelheidL = l;
    snelheidR = r;
    ZumoMotor.setSpeeds(l, r);
}
/*In deze functie wordt de functie setMotorSpeed(int, int) aangeroepen met
de meegegeven snelheid.*/
void motoren::vooruit(int s) {
    setMotorSpeed(s, s);
}
/*In deze functie wordt de functie setMotorSpeed(int, int) aangeroepen met
de meegegeven snelheid, maar de snelheid wordt negatief gemaakt om te
zorgen dat er achteruit gereden wordt.*/
void motoren::achteruit(int s) {
    setMotorSpeed(-1 * s, -1 * s);
}
/*In deze functie wordt de functie setMotorSpeed(int, int) aangeroepen met
de meegegeven snelheid, maar de snelheid van de rechter motor wordt negatief
gemaakt zodat de ZUMO rechtsom om zijn as draait.*/
void motoren::rechtsomDraaien(int s) {
    setMotorSpeed(s, -1 * s);
}
/*In deze functie wordt de functie setMotorSpeed(int, int) aangeroepen met
de meegegeven snelheid, maar de snelheid van de linker motor wordt negatief
gemaakt zodat de ZUMO linksom om zijn as draait*/
void motoren::linksomDraaien(int s) {
    setMotorSpeed(-1 * s, s);
}
/*In deze functie wordt de functie setMotorSpeed(int, int) aangeroepen met
de vaste waardes 0 om de motoren uit te zetten.*/
void motoren::stop() {
    setMotorSpeed(0, 0);
}
/*In deze functie wordt de huidige snelheid uitgeprint naar de Serial monitor*/
void motoren::printSnelheid() {
    Serial.print(snelheidL);
    Serial.print("\t");
    Serial.println(snelheidR);
}

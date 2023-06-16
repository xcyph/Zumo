#include "XBEE.h"

/*De constructor van de klasse XBEE. Hier wordt de baudrate aan meegegeven
en de functie setBaudrate(baudrate) wordt direct uitgevoerd.*/
XBEE::XBEE(int b):baudrate(b) {
    setBaudrate(b);
}
/*De destructor van de klasse XBEE.*/
XBEE::~XBEE() {
}
/*Hier wordt de baudrate van de Serial verbinding verandert naar de 
meegegeven waarde.*/
void XBEE::setBaudrate(int a) {     
    Serial1.begin(a);
}
/*In deze functie wordt er gekeken of er een bericht is binnengekomen over
de XBEE verbinding. Hier komt een true of een false uit.*/
bool XBEE::available() {
    if(Serial1.available()) {
        return true;
    }
    else {
        return false;
    }
}
/*In deze functie wordt het laatst binnengekomen bericht teruggegeven.*/
char XBEE::read() {
    return Serial1.read();
}
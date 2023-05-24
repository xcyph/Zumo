#include "XBEE.h"

XBEE::XBEE() {
}
XBEE::~XBEE() {
}
void XBEE::setBaudrate(int a) {
    Serial1.begin(a);
}
bool XBEE::available() {
    if(Serial1.available()) {
        return true;
    }
    else {
        return false;
    }
}
char XBEE::read() {
    return Serial1.read();
}
#include "XBEE_test.h"

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
void XBEE::vooruit(int ms) {
    setSpeeds(ms, ms);
}
void XBEE::achteruit(int ms) {
    setSpeeds(-1 * ms, -1 * ms);
}
void XBEE::linksomDraaien(int ms) {
    setSpeeds(-1 * ms, ms);
}
void XBEE::rechtsomDraaien(int ms) {
    setSpeeds(ms, -1 * ms);
}
void XBEE::bochtLinks(int ms) {
    setSpeeds(ms / 2, ms);
}
void XBEE::bochtRechts(int ms) {
    setSpeeds(ms, ms / 2);
}
void XBEE::stop() {
    setSpeeds(0, 0);
}
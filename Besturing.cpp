#include "Besturing.h"

motoren::motoren() {
}
motoren::~motoren() {
}
void motoren::setMotorSpeed(int l, int r) {
    setSpeeds(l, r);
}
void motoren::vooruit(int s) {
    setMotorSpeed(s, s);
}
void motoren::achteruit(int s) {
    setMotorSpeed(-1 * s, -1 * s);
}
void motoren::rechtsomDraaien(int s) {
    setMotorSpeed(s, -1 * s);
}
void motoren::linksomDraaien(int s) {
    setMotorSpeed(-1 * s, s);
}
void motoren::stop() {  
    setMotorSpeed(0, 0);
}
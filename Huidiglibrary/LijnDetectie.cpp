#include <LijnDetectie.h>
#include <Zumo32U4.h>

Zumo32U4LineSensors lol;

using namespace std;
#define NUM_SENSORS 5
uint16_t lineSensorValues[NUM_SENSORS];

void LijnDet::starter() {
    lol.initFiveSensors();
    lol.calibrate();
};

LijnDet::kleurHerkenning() {
        lol.read(lineSensorValues);
        const int a = lineSensorValues[1];
        const int b = lineSensorValues[2];
        const int c = lineSensorValues[3];
        const int gem = (a+b+c)/3;

        Serial.println(gem);

        // Return kleur voor later zodat we alles kunnen koppelen
        if ((gem < 230) && (gem > 170)) { // groen
            Serial.println("groen");
        }
        else if ((gem < 330) && (gem > 230)) { // bruin
            Serial.println("bruin");
        }
        else if ((gem < 500) && (gem > 330)) { // zwart
            Serial.println("zwart");
        }
};

// lol
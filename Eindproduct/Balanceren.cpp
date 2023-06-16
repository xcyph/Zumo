#include <Balanceren.h>

/*De constructor van de klasse Balanceren. Deze krijgt de 3 private variabelen
mee die allemaal geinitialiseerd worden met de waarde 0.*/
Balanceren::Balanceren():GyroAngle(0), AccelAngle(0), Gyro_OffsetY(0){
}
/*De destructor van de klasse Balanceren.*/
Balanceren::~Balanceren(){
}
/*In deze functie worden de initialisatie-functies van de klassen Wire en 
Zumo32U4IMU aangeroepen.*/
void Balanceren::init() {
    Wire.begin();
    ZumoIMU.init();
    ZumoIMU.enableDefault();
    ZumoIMU.configureForBalancing();
}
/*In deze functie wordt de Gyro-sensor gecalibreerd door te wachten tot er 
data van de Gyro-sensor beschikbaar is, om vervolgens de data te lezen en toe
te voegen aan de variabele Gyro_OffsetY en als laatste wordt het gemiddelde
van die variabele berekend.*/
void Balanceren::averageYOffset() {
    for (uint16_t i = 0; i < 1024; i++) {
        while (!ZumoIMU.gyroDataReady()) {
        }
        Gyro_OffsetY += ZumoIMU.g.y;
    }
    Gyro_OffsetY /= 1024;
}
/*In deze functie worden de GyroAngle en AccelAngle waarde uitgeprint*/
void Balanceren::printAngles() {
    Serial.print(GyroAngle);
    Serial.print("\t");
    Serial.println(AccelAngle);
}
/*In deze functie wordt de Gyro-sensor waarde uitgelezen en de hoek van de Zumo
wordt geupdate. Eerst wordt de tijd sinds de laatste update berekend, dan wordt
de Gyro-sensor waarde uitgelezen en als laatste wordt de GyroAngle berekend.*/
void Balanceren::updateGyroAngle() {
    static uint16_t lastUpdate = 0;
    uint16_t m = micros();
    uint16_t dt = m - lastUpdate;
    lastUpdate = m;

    ZumoIMU.readGyro();

    GyroAngle += ((float)ZumoIMU.g.y - Gyro_OffsetY) * 70 * dt / 1000000000;
}
/*In deze functie wordt de Accelerometer uitgelezen en hiermee wordt de
GyroAngle gecorrigeerd. Eerst wordt de hoek berekend met behulp van de
Accelerometer, vervolgens wordt acceleratie berekend, waarna de hoek van
de Gyro aangepast wordt, op basis van de hoeveelheid acceleratie.*/
void Balanceren::correctWithAccelAngle() {
    ZumoIMU.readAcc();

    AccelAngle = -atan2(ZumoIMU.a.z, -ZumoIMU.a.x) * 180 / M_PI;

    Zumo32U4IMU::vector<float> const aInG = {
        (float)ZumoIMU.a.x / 4096,
        (float)ZumoIMU.a.y / 4096,
        (float)ZumoIMU.a.z / 4096}
    ;
    float mag = sqrt(vector_dot(&aInG, &aInG));
    float weight = 1 - 5 * abs(1 - mag);
    weight = constrain(weight, 0, 1);
    weight /= 10;
    GyroAngle = weight * AccelAngle + (1 - weight) * GyroAngle;
}
/*In deze functie wordt getest of de huidige hoek tussen de meegegeven waardes 
ligt. Hier komt een true of een false uit.*/
bool Balanceren::testAngle(int x, int y) {
    if (GyroAngle >= x && GyroAngle <= y) {
        return true;
    }
    else {
        return false;
    }
}

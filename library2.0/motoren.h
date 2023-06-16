#include <Zumo32U4.h>
#include <Zumo32U4Motors.h>

using namespace std;

class motoren
{
    public:
        motoren();
        ~motoren();
        void setMotorSpeed(int, int);
        void vooruit(int);
        void achteruit(int);
        void rechtsomDraaien(int);
        void linksomDraaien(int);
        void stop();
        void printSnelheid();

    private:
        int snelheidL;
        int snelheidR;
        Zumo32U4Motors ZumoMotor;
};

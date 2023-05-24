#include <Zumo32U4.h>
#include <Zumo32U4Motors.h>

using namespace std;

class motoren : public Zumo32U4Motors
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

    private:
        int snelheid;
};
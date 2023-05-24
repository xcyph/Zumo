#include <Zumo32U4.h>
#include <Zumo32U4Motors.h>

using namespace std;

class XBEE : public Zumo32U4Motors
{
    public:
        XBEE();
        ~XBEE();
        void setBaudrate(int);
        bool available();
        char read();
        void vooruit(int);
        void achteruit(int);
        void linksomDraaien(int);
        void rechtsomDraaien(int);
        void bochtLinks(int);
        void bochtRechts(int);
        void stop();

    private:
        int baudrate;
        char instruction;
        int motorSpeed;
};
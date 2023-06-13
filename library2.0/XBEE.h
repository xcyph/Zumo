using namespace std;
#include "HardwareSerial.h"
#include "HardwareSerial_private.h"
class XBEE
{
    public:
        XBEE(int);
        ~XBEE();
        void setBaudrate(int);
        bool available();
        char read();

    private:
        int baudrate;
};

#include <Zumo32U4.h>
#include <Zumo32U4Motors.h>

using namespace std;

class XBEE
{
    public:
        XBEE();
        ~XBEE();
        void setBaudrate(int);
        bool available();
        char read();

    private:
        int baudrate;
        char instruction;
};
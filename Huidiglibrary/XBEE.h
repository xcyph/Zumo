using namespace std;

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

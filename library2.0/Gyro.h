#include <Wire.h>
#include <Zumo32U4.h>

class Balanceren
{
    public:
    Balanceren();
    ~Balanceren();
    void init();
    void averageYOffset();
    void printAngles();
    void updateGyroAngle();
    void correctWithAccelAngle();
    bool testAngle(int, int);
    template <typename Ta, typename Tb> float vector_dot(const Zumo32U4IMU::vector<Ta> *a, const Zumo32U4IMU::vector<Tb> *b)
    {
        return (a->x * b->x) + (a->y * b->y) + (a->z * b->z);
    }


    private:
    float GyroAngle;
    float AccelAngle;
    float Gyro_OffsetY;
    Zumo32U4IMU ZumoIMU;
};

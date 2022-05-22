#ifndef Rain_sensor_h
#define Rain_sensor_h

class Rain_sensor
{
private:
    int RAIN_PIN;
    int DRY_VAL;
    int WET_VAL;
    int RAIN_VAL;

public:
    Rain_sensor();
    String rain_chk();
};
#endif

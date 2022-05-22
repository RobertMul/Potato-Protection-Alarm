#ifndef sms_h
#define sms_h
#include <Arduino.h>
#include <DFRobot_sim808.h>//must change User/Documents/Arduino/libraries/DFRobot_SIM808-master/DFRobot_sim808.h line 41 from closed to close

class sms
{
public:
    sms();
    void smsSetup();
    void sms_chk(float humid, float temp, String rain,String soil);
};
#endif

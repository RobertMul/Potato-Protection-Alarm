#ifndef Soil_Moisture_h
#define Soil_Moisture_h
#include <Arduino.h>

class Soil_Moisture
{ 
  private:
    int SMOISTURE_PIN = 0;
    int WATER_VAL = 54;
    int AIR_VAL = 570;

  public:
    Soil_Moisture();
    String soil_chk();

};
#endif

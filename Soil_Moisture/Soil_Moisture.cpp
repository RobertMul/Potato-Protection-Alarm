#include <Arduino.h>
#include "Soil_Moisture.h"
Soil_Moisture::Soil_Moisture()
{
  SMOISTURE_PIN = 0;
  WATER_VAL = 54;//Value when placed in water
  AIR_VAL = 570;//Value when in the open air

}

String Soil_Moisture::soil_chk()//Depending on the value from the circuit a String describing the soil status will be sent
{
  int increment = (AIR_VAL - WATER_VAL)/6;//increment to get values in between dry and wet
  int smoisture = analogRead(SMOISTURE_PIN);
  String stat;
  if (smoisture < (WATER_VAL + increment))// By using theses increments a more accurate represtation of the soil is given
  {
    stat = "Very Wet";
    return(stat);
  }

  else if (smoisture > (WATER_VAL + increment) && smoisture < (AIR_VAL-(increment*2)))
  {
    stat = "Wet";
    return(stat);
  }

  else if (smoisture < (AIR_VAL - increment) && smoisture > (AIR_VAL - (increment*2)))
  {
    stat = "Dry";
    return(stat);
  }
  else if(smoisture > (AIR_VAL - increment))
  {
    stat = "Very Dry";
    return(stat);
   }
}

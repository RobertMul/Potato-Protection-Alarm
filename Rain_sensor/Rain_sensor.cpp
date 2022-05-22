#include <Arduino.h>
#include "Rain_sensor.h"
Rain_sensor::Rain_sensor()

{
    RAIN_PIN = 1;
    DRY_VAL = 750;//value collected by testing sensor with different levels of water
    WET_VAL = 500;
    RAIN_VAL = 250;
  
}

String Rain_sensor::rain_chk()//Depending on the value from the rain sensor in a voltage divider circuit a String describing the rain status will be sent
{
  int rainlev = analogRead(RAIN_PIN);
  String stat;
  if (rainlev >= DRY_VAL)//no rain
  {
    stat = "Clear day";
    return (stat);
  }

  else if (rainlev < DRY_VAL && rainlev >WET_VAL )//a little water
  {
    stat = "Wet";
    return (stat);
  }

  else if (rainlev < WET_VAL && rainlev > RAIN_VAL)//a decent amount of water
  {
    stat = "Raining";
    return (stat);
  }
  else if(rainlev < RAIN_VAL)//nearly completly submerged
  {
    stat = "Heavy rain";
    return (stat);
   }
}

#include <Arduino.h>
#include "LDR.h"
LDR::LDR()
{
  _pin = 2;
}
int LDR::contrast_control(){//Depending on the value from the LDR in a voltage divider circuit a PWM value will be sent to the LCD
 
  int ldr_val = analogRead(_pin);
  if(ldr_val > 700)//not very bright
  {
   return (90);//low cotrast
  }

  else if(ldr_val > 500 && ldr_val < 700)
  {
   return (70);
  }

  else if(ldr_val > 90 && ldr_val < 500)
  {
   return (50);
  }

  else if (ldr_val < 90)//very bright /Direct Sunlight
  {
  return (10);//high contrast
}
}
                                                                                      

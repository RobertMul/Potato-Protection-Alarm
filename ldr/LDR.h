#ifndef LDR_h
#define LDR_h

#include <Arduino.h>

class LDR
{
  private:
    int _pin;

  public:
    LDR();
    int contrast_control();
};

#endif

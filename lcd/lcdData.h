#ifndef lcdData_h
#define lcdData_h

#include <Arduino.h>
#include <LiquidCrystal.h>
#include <LDR.h>
class lcdData
{
public:
    void lcdBegin();
    void lcdDisplay(float humidity, float temperature, String rain, String soil, int count, LDR ldr);
}; 
#endif


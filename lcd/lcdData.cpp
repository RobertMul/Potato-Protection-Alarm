#include <Arduino.h>
#include "lcdData.h"
#include <LiquidCrystal.h>
#include <LDR.h>

const int RS = 13, EN = 11, D4 = 5, D5 = 4, D6 = 3, D7 = 2, CONT = 9;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void lcdData::lcdBegin()
{
	lcd.begin(16, 2);
}

void lcdData::lcdDisplay( float humidity,float temperature,String rain,String soil,int count,LDR ldr)
{
  analogWrite(CONT,ldr.contrast_control());
  if (count <= 1000){
  if(count ==0){lcd.clear();}
 
 //sets the cursor to the first line
 lcd.setCursor(0, 0);
 //prints the humidity value passed from the dht11
 lcd.print("Humidity(%):");
 lcd.print(humidity);
 //sets the cursor to the second line
 lcd.setCursor(0, 1);
 //prints the temperature value passed from the dht11 
 lcd.print("Temp(C):");
 lcd.print(temperature);
}
 else if(count <=2000){
 if(count ==1001){lcd.clear();}
 lcd.setCursor(0, 0);
 //prints the rain status passed from the rain sensor
 lcd.print("Rain Status:");
 lcd.setCursor(0, 1);
 lcd.print(rain);
  for(int i = 0;i <16;i++)
  {lcd.print(' ');}
 }

 else if(count <= 3000){
 if(count ==2001){lcd.clear();}

 lcd.setCursor(0, 0);
 //prints the soil status passed from the soil moisture sensor
 lcd.print("Soil Status:");
 lcd.setCursor(0, 1);
 lcd.print(soil);
 for(int i = 0;i <16;i++)
  {lcd.print(' ');}
 }
}

#include "sms.h"
#include <Arduino.h>
#include <DFRobot_sim808.h>//must change User/Documents/Arduino/libraries/DFRobot_SIM808-master/DFRobot_sim808.h line 41 from closed to close
//Mobile phone number, need to change
#define PHONE_NUMBER "353877178072"
DFRobot_SIM808 sim808(&Serial);
sms::sms()
{
  
}

void sms::smsSetup()
{
   while(!sim808.init()) {
       delay(1000);
       Serial.print(F("Sim808 init error\r\n"));
   }
   Serial.println(F("Sim808 init success"));
   Serial.println(F("Start to send message ..."));
}

void sms::sms_chk(float humid,float temp,String rain,String soil)
{
   //if blight conditions are met will send out text (humid condition lowered for testing)
  if(humid > 10 && temp > 10) {
    if(rain == "Wet" || rain == "Raining" || rain == "Heavy rain"){
      Serial.println("Start to send message ...");
      String mes = "WARNING!!!\nHumidity: "+ (String)humid + " Temperature: " + (String)temp  + " Rain: " + rain + " Soil: "+ soil;
      char m[mes.length()+1];
      strcpy(m, mes.c_str());
      sim808.sendSMS(PHONE_NUMBER,m);  
    }
  }
}

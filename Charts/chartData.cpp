#include "chartData.h"
#include  <Arduino.h>
#include <ThingSpeak.h>
#include "WiFiEsp.h"
chartData::chartData()
{

}

void chartData::chartSetup()
{
  ThingSpeak.begin(client);  // Initialize ThingSpeak
}

void chartData::chart_data(float temp,float humid,String rain,String soil)
{
    //converts rain and soil results into values to turn widget on thingspeak on or off
    int rAlarm, sAlarm;
    if (rain == "Wet") {
        rAlarm = 1;
    }
    else if (rain == "Raining") {
        rAlarm = 2;
    }
    else if (rain == "Heavy rain") {
        rAlarm = 3;
    }
    else {
        rAlarm = 0;
    }

    if (soil == "Dry") {
        sAlarm = 1;
    }
    else if (soil == "Wet")
    {
        sAlarm = 2;
    }
    else if (soil == "Very Wet")
    {
        sAlarm = 3;
    }
    else
    {
        sAlarm = 0;
    }

    ThingSpeak.setField(1, temp);
    ThingSpeak.setField(2, humid);
    ThingSpeak.setField(3, rAlarm);
    ThingSpeak.setField(4, sAlarm);
    //updates thingspeak charts
    ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
}

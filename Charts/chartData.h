#pragma once
#ifndef CHART_DATA_h
#define CHART_DATA_h
#include <ThingSpeak.h>
#include "WiFiEsp.h"

#define myChannelNumber 1649404
#define myWriteAPIKey "ZFTQL0SOA46RTLE2"

class chartData
{
private:

  WiFiEspClient  client;
  int rAlarm;
  int sAlarm;


public:
  chartData();
  void chartSetup();
  void chart_data(float temp,float humid,String rain,String soil);
};
#endif

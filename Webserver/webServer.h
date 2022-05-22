#ifndef webServer_h
#define webServer_h
#include <Arduino.h>
#include "WiFiEsp.h"

class webServer
{
  public:
    webServer();
    void web_server(float humid,float temp,String rain,String soil);
    void webSetup();
};
#endif

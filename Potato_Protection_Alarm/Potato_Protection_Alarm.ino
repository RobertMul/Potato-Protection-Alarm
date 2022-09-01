#include <sms.h>
#include <webServer.h>
#include <Rain_sensor.h>
#include <Soil_Moisture.h>
#include <LDR.h>
#include <lcdData.h>
#include <chartData.h>
#include <DHT.h>
#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);

int count = 0;

LDR ldr;
lcdData l;
Soil_Moisture soilSensor;
Rain_sensor rainSensor;
chartData chart;
webServer wserver;
sms text;

void setup() {
  Serial.begin(115200);
  Serial1.begin(9600);
  text.smsSetup();
  wserver.webSetup();
  chart.chartSetup();// Initialize ThingSpeak
  l.lcdBegin();
  dht.begin();
}

void loop() {
  //reads the rain and soil moisture levels and stores as strings
  String rain = rainSensor.rain_chk();
  String soil = soilSensor.soil_chk();
  //reads the humidity and temperature and stores as float variables
  float humid = dht.readHumidity();
  float temp = dht.readTemperature();

  //sends the humidity,temperature,rain and soil moisture readings to the lcd display function
  l.lcdDisplay(humid,temp,rain,soil,count,ldr);
  
  wserver.web_server(humid,temp,rain,soil);//sends the data to the server

  count++;
  if (count > 3000){//when count reaches value resets it and calls sms and thingspeak chart functions
    count = 0;
    text.sms_chk(humid, temp,rain,soil);//checks if threshold is met to send text
    chart.chart_data(temp,humid,rain,soil);//send data to thingspeak
  }
  delay(1);
}

#include "webServer.h"
#include  <Arduino.h>
#include "WiFiEsp.h"
WiFiEspServer server(80);
char ssid[] = "Hotspot";            // your network SSID (name)
char pass[] = "IotProject";        // your network password
int status = WL_IDLE_STATUS;     // the Wifi radio's status

webServer::webServer()
{
  
}

void webServer::webSetup()
{
    WiFi.init(&Serial1);
  
   // check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println(F("WiFi shield not present"));
    // don't continue
    while (true);
  }

  // attempt to connect to WiFi network
  while ( status != WL_CONNECTED) {
    Serial.print(F("Attempting to connect to WPA SSID: "));
    Serial.println(ssid);
    //Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
  }

  Serial.println(F("You're connected to the network"));
  
   // print the SSID of the network you're attached to
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print where to go in the browser
  Serial.println();
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);
  Serial.println();



  // start the web server on port 80
  server.begin();
}



void webServer::web_server(float humid,float temp,String rain,String soil)
{
  
 // listen for incoming clients
  WiFiEspClient client = server.available();
  if (client) {
    Serial.println("New client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          Serial.println("Sending response");
   
         // client.print(homePageHtml);
          client.println(F(R"=====(

         <!DOCTYPE html>
     
<html>
<head>
          
<style>
.hidden{
    display:none;
}

.unhidden{
    display:block;
}

.humid {
  position: absolute;
  top: 25%;
  left: 20%;
  font-size: 18px;
}

.temp {
  position: absolute;
  top: 25%;
  left: 70%;
  font-size: 18px;
}
.change {
position: relative;
display: inline-block;
}

.change .img1 {
  display: none;
        position: absolute;
        top: 0;
        left: 0;    
}
.change:hover .img1{
 display: inline;
}

.rain {
  position: absolute;
  top: 75%;
  left: 20%;
  font-size: 18px;
}

.soil {
  position: absolute;
  top: 75%;
  left: 70%;
  font-size: 18px;
}
.container {
   position: absolute;
    overflow: hidden;
    top:110%;
    left: -100%
}
.ref {
  position: absolute;
  top:100%;
  left:50%;
  }
  .button {background-color: yellow;}



body {background-color: rgb(92,64,51);}
h1 {background-color: green; text-align:center;}
p {color:yellow}
</style>
</style>
<script type="text/javascript">
function unhide(clickedButton, divID) {
var item = document.getElementById(divID);
if (item) {
    if(item.className=='hidden'){
        item.className = 'unhidden' ;
        clickedButton.value = 'hide'
    }else{
        item.className = 'hidden';
        clickedButton.value = 'icons'
    }
}}

</script>
</head>
 <body >
<h1>Potato Protection Alarm</h1>
 
<div class = "humid"> 
<div class ="change">
<a href = "https://thingspeak.com/channels/1649404/charts/2?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line&update=15" target ="_blank">
<img src="https://img.icons8.com/ios/100/ffffff/humidity.png"/ alt = "Humidity icon">
<img class = "img1" src="https://img.icons8.com/ios-filled/100/000000/humidity.png"/>
</a>
</div>
<p>Humidity:</p>)=====")); 
client.println(humid);
client.println(F(R"=====(
<iframe class = "container" width="450" height="230" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/1649404/charts/1?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line&update=15"></iframe>
</div>        


<div class = "temp"> 
<div class= "change">
<a href = "https://thingspeak.com/channels/1649404/charts/1?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line&update=15" target ="_blank">
<img src="https://img.icons8.com/ios-filled/100/ffffff/temperature--v1.png"/ alt = "Temperature icon">
<img class = "img1" src="https://img.icons8.com/ios-filled/100/000000/temperature--v1.png" >
</a>

</div>
<p>Temperature:</p>)====="));
client.println(temp);
client.println(F(R"=====(
<iframe class = "container" width="450" height="230" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/1649404/charts/2?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line&update=15"></iframe>
</div> 

<div class = "rain">
<div class= "change">
<a href = "https://thingspeak.com/channels/1649404" target = "_blank">
<img src="https://img.icons8.com/ios/100/ffffff/rain--v1.png"/ alt = "Rain icon">
<img class = "img1" src="https://img.icons8.com/ios/100/000000/rain--v1.png"/>
</a>
</div>
<p>Rain Level:</p>)====="));
client.println(rain);
client.println(F(R"=====(      
</div>        

  
<div class = "soil">
<div class= "change">
<a href = "https://thingspeak.com/channels/1649404" target = "_blank">
<img src="https://img.icons8.com/ios/100/ffffff/soil.png"/ alt = "Soil icon">
<img class = "img1" src="https://img.icons8.com/ios/100/000000/soil.png"/>
</a>
</div>
<p>Soil Moisture:</p>)====="));
client.println(soil);
client.println(F(R"=====(
</div>   
<div class = "ref">
<div id="about" class="hidden">
<a href="https://icons8.com/icon/1414/temperature">Temperature</a>      
<a href="https://icons8.com/icon/1690/humidity">Humidity</a>      
<a href="https://icons8.com/icon/656/rain">Rain</a>     
<a href="https://icons8.com/icon/25780/soil">Soil</a>
</div>

<input type="button" class = "button" onclick="unhide(this, 'about') " value="icons">


</body>
</html>
         
          
          )====="));
          client.println();
          
 
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        }
        else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(10);

    // close the connection:
    client.stop();
    Serial.println("Client disconnected");
  }
  
}

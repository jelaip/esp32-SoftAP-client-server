#include "WiFi.h"
#include "ESPAsyncWebServer.h"

 
const char *ssid = "name";
const char *password = "123456789";
 
AsyncWebServer server(80);



String state = "off";
String oldState = "off";



void setup(){
  Serial.begin(115200);


  WiFi.softAP(ssid, password);

  
  
  Serial.println();
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());
 
  server.on("/red", HTTP_GET, [](AsyncWebServerRequest *request){
    state = "red";
    request->send(200, "text/plain", "red");
  });
  server.on("/blue", HTTP_GET, [](AsyncWebServerRequest *request){
    state = "blue";
    request->send(200, "text/plain", "blue");
  });
  server.on("/green", HTTP_GET, [](AsyncWebServerRequest *request){
    state = "green";
    request->send(200, "text/plain", "green");
  });
  server.on("/cyan", HTTP_GET, [](AsyncWebServerRequest *request){
    state = "cyan";
    request->send(200, "text/plain", "cyan");
  });
  server.on("/magenta", HTTP_GET, [](AsyncWebServerRequest *request){
    state = "magenta";
    request->send(200, "text/plain", "cyan");
  });
  server.on("/yellow", HTTP_GET, [](AsyncWebServerRequest *request){
    state = "yellow";
    request->send(200, "text/plain", "cyan");
  });
  server.on("/white", HTTP_GET, [](AsyncWebServerRequest *request){
    state = "white";
    request->send(200, "text/plain", "cyan");
  });


 
  server.begin();
}

 
void loop(){
    if(state != oldState){
        if(state == "red"){
        
        }
    }
}

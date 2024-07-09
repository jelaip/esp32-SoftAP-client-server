
#include <WiFi.h>
#include <HTTPClient.h>


const char* ssid = "name";
const char* password = "123456789";
const char* serverName = "http://192.168.4.1/";
unsigned long lastTime = 0;
unsigned long timerDelay = 3000;


//--------------------------------------------------------------------------------------------

int state = 0;

void setup() {

  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {

  if ((millis() - lastTime) > timerDelay) {
    if(WiFi.status()== WL_CONNECTED){         
      const char* s =  "http://192.168.4.1/red";
      Serial.println(httpGETRequest(s));
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}

String httpGETRequest(const char* serverName) {
  WiFiClient client;
  HTTPClient http;
  http.begin(client, serverName);
  int httpResponseCode = http.GET(); 
  String payload = "{}";  
  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  http.end();
  return payload;
}




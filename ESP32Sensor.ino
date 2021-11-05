#include <WiFi.h>
#include <HTTPClient.h>
#include <WebServer.h>

const char* ssid = "SSID";  //replace SSID with you WiFi SSID
const char* password =  "PASSWORD"; //replace PASSWORD with you WiFi password
const char* sensor_id = "1A2B3C4D5E"; //replace 1A2B3C4D5E with your sensor ID

long REFRESH_INTERVAL = 10000;
long lastRefreshTime = 0;

WebServer server(80);
String HTML = "<!DOCTYPE html><html><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\"><style>body{background: #131315; padding:0; margin:0;}h1{font-family: sans-serif;color:#ffffff;text-align: center; margin: 0;}div{font-size: 1.5em;font-family: monospace;color: white;}</style></head><body>    <div style=\"background-color: #393939; padding:10px;\"> <h1>SENSOR DEBUGGING</h1> </div>   <div id=\"sensorDebugging\"></div> <script>        setInterval(function ( ) {var xhttp = new XMLHttpRequest();    xhttp.onload = function() {console.log(this.responseText);     var data = document.createElement(\"div\");   data.innerHTML = this.responseText;   document.getElementById(\"sensorDebugging\").appendChild(data);    };    xhttp.open(\"GET\", \"/data\", true);xhttp.send();}, "+String(REFRESH_INTERVAL)+" ) ;                   </script></body><html>";
String sensorData = "";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  delay(10000);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }  
  Serial.println("Connected to the WiFi network");
  Serial.print("IP address of sensor: ");
  Serial.println(WiFi.localIP());

  server.on("/", sendHTML);
  server.on("/data", sendData);
  server.onNotFound(sendHTML);
  server.begin();
  Serial.println("Server started");
  Serial.println();
  randomSeed(analogRead(0));
}


int getSensorReading(){
  //this function is called evey 10 seconds
  //the return of this function is the data that will be added to the database
  //replace the body of this function with whatever logic that gets and returns the sensor value
  return random(100);
}

void sendHTML(){
      server.send(200, "text/html", HTML);   
}

void sendData(){
      server.send(200, "text/html", sensorData);
  }

void sendGet(String url){
      HTTPClient http;
      int httpCode;
      Serial.print("GET URL: " + url);
      http.begin( url.c_str());
      int httpResponseCode = http.GET();
      Serial.println("\tAFS REPSONSE CODE: " + String(httpResponseCode));
      sensorData = url + "        AFS REPSONSE CODE" +  String(httpResponseCode);
      http.end();
      return;      
}

void loop() {
      if(millis() - lastRefreshTime >= REFRESH_INTERVAL){
          lastRefreshTime += REFRESH_INTERVAL;
          sendGet("https://web.njit.edu/~mb822/aguaclaranjit/submitdata.php?id=" + String(sensor_id) + "&value=" + String(getSensorReading())    );
      }
      server.handleClient();
}

#include <WiFi.h>
#include <HTTPClient.h>
#include <Preferences.h>

String ssid;
String password;
String sensor_id;

long REFRESH_INTERVAL = 10000;
long lastRefreshTime = 0;

String sensorData;

Preferences preferences;

void setup() {
  Serial.begin(115200);
  preferences.begin("aguaclara", false);
  ssid = preferences.getString("ssid", "");
  password = preferences.getString("password", "");
  sensor_id = preferences.getString("sensor_id", ""); sensor_id.trim();
   
  if (ssid == "" || password == ""){
    Serial.println("WiFi credentials not set");
  }
  else {
    char ssid_char[32];
    char password_char[64];
    ssid.toCharArray(ssid_char, ssid.length());
    password.toCharArray(password_char, password.length());
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid_char, password_char);
    Serial.print("Connecting to WiFi..");
    while (WiFi.status() != WL_CONNECTED) {
      Serial.print('.');
      delay(1000);
    }
    Serial.print("\nWiFI Connected; IP: ");
    Serial.println(WiFi.localIP());  
  }
 
  randomSeed(analogRead(0));
}

int getSensorReading(){
  //this function is called evey 10 seconds
  //the return of this function is the data that will be added to the database
  //replace the body of this function with whatever logic that gets and returns the sensor value
  return random(100);
}

void sendGet(String url){
  HTTPClient http;
  Serial.println("\tGet Url: " + url);
  http.begin(url.c_str());
  int status = http.GET();
  Serial.print("\t\tResponse status: "); Serial.println(status);
  http.end();
}

void setPreference(String key, String value){
  preferences.putString(key.c_str(), value);
}

String getPreference(String key){
  return preferences.getString(key.c_str(), "");
}

void loop() {
  if(ssid == "" || password == "" || sensor_id == ""){
  }
  else if(millis() - lastRefreshTime >= REFRESH_INTERVAL){
    lastRefreshTime += REFRESH_INTERVAL;
    sendGet("https://web.njit.edu/~mb822/aguaclaranjit/submitdata.php?id=" + String(sensor_id) + "&value=" + String(getSensorReading()));
}
  if(Serial.available()){
    String serial_input = Serial.readString();
    int keyIndex = serial_input.indexOf("--");
    int valueIndex = serial_input.indexOf("=");
    if(keyIndex!=-1 && valueIndex!=-1 && keyIndex<valueIndex){
      String key = serial_input.substring(keyIndex+2, valueIndex);
      String value = serial_input.substring(valueIndex+1, serial_input.length());
      setPreference(key, value);
      Serial.println(key + " preference set.");
    }
    else{
      Serial.println("Invalid command.");
    }
  }
}

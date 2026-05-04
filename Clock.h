// Clock.h
#include <WiFi.h>
#include "time.h"
#include "Config.h"

void setUpClock() {
  // Modem-Sleep (for energy saving)
  WiFi.setSleep(true); 
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

// Function to verify the status of Wi-Fi connection.
void verifyConnection() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Wi-Fi connection lost. Trying to reconnect...");
    WiFi.disconnect();
    WiFi.begin(SSID, password);
    
    // Tries to reconnect 20 times
    int trials = 0;
    while (WiFi.status() != WL_CONNECTED && trials < 20) {
      delay(500); //This will freeze the whole code, but shouldn't be an issue since the leds only need to be on or off.
      trials++;
    }
  }
}

bool verifyNightTime() {
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    return false; 
  }
  //This is an average of the place I live, change values here to the time it usually gets dark and light where you live.
  /*(You can probably add some API for this to be more precise,
  but I wanted to avoid relying on Internet connection for this project.)*/
  return (timeinfo.tm_hour >= 18 || timeinfo.tm_hour < 6); 
}

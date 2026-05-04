#include <WiFi.h>
#include "Config.h"
#include "Clock.h"

// Variables to avoid time oscilation.
unsigned long lastVerification = 0;
const int waittime = 5000; // After 5 seconds, the time is verified.

void setup() {
  Serial.begin(115200);
  setCpuFrequencyMhz(80); //This function reduces the ESP processor's frequency to save energy, disable it if you plan to add other functions to it.
  //Below is the pin setup, pin values can be set at the config.h file.
  pinMode(LED1, OUTPUT); 
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LDR, INPUT);

  WiFi.begin(SSID, password);
  while (WiFi.status() != WL_CONNECTED) { delay(500); }
  
  setUpClock();
}

void loop() {
  // 1. This guarantees Wi-Fi is available.
  verificarConexao();

  // 2. The logic is only executed after the time set in the waittime variable (Avoids unnecessary processing).
  if (millis() - lastVerification > waittime) {
    lastVerification = millis();

    int sensor_state = digitalRead(LDR);
    bool isNight = verifyNightTime();

    if (sensor_state == 1 && isNight) {
      digitalWrite(LED1, HIGH); 
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      Serial.println("Status: Night and Dark. LEDs are on.");
    } 
    else {
      digitalWrite(LED1, LOW); 
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      Serial.println("Status: Light detected. LEDs off.");
    }
  }
}
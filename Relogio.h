// Relogio.h
#include <WiFi.h>
#include "time.h"
#include "Config.h"

void configurarRelogio() {
  // Modem-Sleep para economizar energia
  WiFi.setSleep(true); 
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

// Função vital para projetos que ficam ligados direto
void verificarConexao() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Wi-Fi perdido. Tentando reconectar...");
    WiFi.disconnect();
    WiFi.begin(SSID, password);
    
    // Tenta reconectar por 10 segundos sem travar o loop
    int tentativas = 0;
    while (WiFi.status() != WL_CONNECTED && tentativas < 20) {
      delay(500);
      tentativas++;
    }
  }
}

bool verificarHorarioNoturno() {
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    return false; 
  }
  return (timeinfo.tm_hour >= 18 || timeinfo.tm_hour < 7);
}
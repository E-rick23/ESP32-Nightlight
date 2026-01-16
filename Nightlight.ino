#include <WiFi.h>
#include "Config.h"
#include "Relogio.h"

// Variáveis para evitar oscilação (Histerese)
unsigned long ultimaVerificacao = 0;
const int intervalo = 5000; // Verifica a cada 5 segundos

void setup() {
  Serial.begin(115200);
  setCpuFrequencyMhz(80); //reduz a frequência do processador para diminuir o consumo energético
  pinMode(PINO_LED, OUTPUT); 
  pinMode(PINO_LED2, OUTPUT);
  pinMode(PINO_LED3, OUTPUT);
  pinMode(PINO_LDR, INPUT);

  WiFi.begin(SSID, password);
  while (WiFi.status() != WL_CONNECTED) { delay(500); }
  
  configurarRelogio();
}

void loop() {
  // 1. Garante que o Wi-Fi esteja sempre vivo
  verificarConexao();

  // 2. Executa a lógica apenas a cada 'intervalo' (evita processamento desnecessário)
  if (millis() - ultimaVerificacao > intervalo) {
    ultimaVerificacao = millis();

    int sensor_state = digitalRead(PINO_LDR);
    bool eNoite = verificarHorarioNoturno();

    if (sensor_state == 1 && eNoite) {
      digitalWrite(PINO_LED, HIGH); 
      digitalWrite(PINO_LED2, HIGH);
      digitalWrite(PINO_LED3, HIGH);
      Serial.println("Status: Noite e Escuro. LEDs Ligados.");
    } 
    else {
      digitalWrite(PINO_LED, LOW); 
      digitalWrite(PINO_LED2, LOW);
      digitalWrite(PINO_LED3, LOW);
      Serial.println("Status: Dia ou Luz detectada. LEDs Desligados.");
    }
  }
}
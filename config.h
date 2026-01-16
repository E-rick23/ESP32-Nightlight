#ifndef CONFIG_H
#define CONFIG_H

// Pinos
const int PINO_LED = 12; 
const int PINO_LED2 = 13;
const int PINO_LED3 = 14;
const int PINO_LDR = 27;

// Wi-Fi
const char* SSID = "your-wifi-ssid";
const char* password = "your-wifi-password";

// NTP
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 0; // Define the offset of your residence
const int   daylightOffset_sec = 0;


#endif

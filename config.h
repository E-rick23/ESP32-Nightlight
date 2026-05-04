#ifndef CONFIG_H
#define CONFIG_H

// Pinos
const int LED1 = 12; 
const int LED2 = 13;
const int LED3 = 14;
const int LDR = 27;

// Wi-Fi
const char* SSID = "your-wifi-ssid";
const char* password = "your-wifi-password";

// NTP
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 0; // Define the offset of your residence
const int   daylightOffset_sec = 0;

#endif

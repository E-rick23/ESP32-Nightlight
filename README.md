# ESP32-Nightlight
A simple esp32 project that turns on a light at a specific time and condition.

This project uses Wi-Fi to automatically deactivate the lights if it's morning, based on an online clock, and a light sensor to deactivate the led's if the room has lights on.

## How to setup:
	- In the config.h file, set the pins you're using on your ESP32 board as the LED const variables, and the light sensor (ldr) pin.
	- Also set wifi settings and the NTP server you're using in the config.h
	- You may also configurate the time the lights should turn off in the clock.h's verifyNightTime() function. (default is lights on between 18 and 6 in the 24-hour format).
	
## How to use it:
	- After setup is complete, compile the code and upload it to your ESP32 board, I personally used ArduinoIDE for it.
	
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// The common LCD1602 I2C backpack address is 0x27.
LiquidCrystal_I2C lcd(0x27, 16, 2);

unsigned long lastTickMillis = 0;
int hours = 0;
int minutes = 0;
int seconds = 0;

// Seeds the clock from the sketch's compile time (__TIME__ is "HH:MM:SS").
void seedTimeFromCompileTime() {
	sscanf(__TIME__, "%d:%d:%d", &hours, &minutes, &seconds);
}

void printTime() {
	char buf[9];
	sprintf(buf, "%02d:%02d:%02d", hours, minutes, seconds);
	lcd.setCursor(0, 1);
	lcd.print(buf);
}

void setup() {
	lcd.init();
	lcd.backlight();
	lcd.setCursor(0, 0);
	lcd.print("tOMa MaanGOOo");
	seedTimeFromCompileTime();
	printTime();
	lastTickMillis = millis();
}

void loop() {
	if (millis() - lastTickMillis >= 1000) {
		lastTickMillis += 1000;

		seconds++;
		if (seconds >= 60) {
			seconds = 0;
			minutes++;
			if (minutes >= 60) {
				minutes = 0;
				hours = (hours + 1) % 24;
			}
		}

		printTime();
	}
}

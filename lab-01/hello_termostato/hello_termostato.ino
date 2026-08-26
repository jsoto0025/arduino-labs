#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// The common LCD1602 I2C backpack address is 0x27.
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

unsigned long lastReadMillis = 0;
const unsigned long readInterval = 2000; // DHT11 needs >=1s between reads

void setup() {
	Serial.begin(9600);
	lcd.init();
	lcd.backlight();
	lcd.setCursor(0, 0);
	lcd.print("Temp:");
	lcd.setCursor(0, 1);
	lcd.print("Humidity:");
	dht.begin();
	delay(2000); // DHT11 needs time to stabilize after power-up
}

void loop() {
	if (millis() - lastReadMillis >= readInterval) {
		lastReadMillis = millis();

		float temperature = dht.readTemperature();
		float humidity = dht.readHumidity();

		if (isnan(temperature) || isnan(humidity)) {
			Serial.println("DHT11 read failed - check wiring/power (5V recommended)");
			lcd.setCursor(6, 0);
			lcd.print("Err  ");
			lcd.setCursor(10, 1);
			lcd.print("Err  ");
			return;
		}

		Serial.print("Temp: ");
		Serial.print(temperature);
		Serial.print(" C, Humidity: ");
		Serial.print(humidity);
		Serial.println(" %");

		lcd.setCursor(6, 0);
		lcd.print(temperature, 1);
		lcd.print((char)223);
		lcd.print("C ");

		lcd.setCursor(10, 1);
		lcd.print(humidity, 1);
		lcd.print("% ");
	}
}

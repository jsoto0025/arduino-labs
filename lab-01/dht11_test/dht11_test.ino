#include <DHT.h>

// Minimal isolation test: DHT11 only, no LCD/I2C involved.
#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
	Serial.begin(9600);
	dht.begin();
	delay(2000);
}

void loop() {
	float temperature = dht.readTemperature();
	float humidity = dht.readHumidity();

	if (isnan(temperature) || isnan(humidity)) {
		Serial.println("DHT11 read failed");
	} else {
		Serial.print("Temp: ");
		Serial.print(temperature);
		Serial.print(" C, Humidity: ");
		Serial.print(humidity);
		Serial.println(" %");
	}

	delay(2000);
}

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Change these values before uploading.
const char WIFI_SSID[] = "YOUR_WIFI_NAME";
const char WIFI_PASSWORD[] = "YOUR_WIFI_PASSWORD";

const unsigned long ESP_BAUD = 115200;
const unsigned long COMMAND_TIMEOUT = 8000;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void showMessage(const char *line1, const char *line2) {
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print(line1);
	lcd.setCursor(0, 1);
	lcd.print(line2);
}

bool waitForResponse(const char *expected, unsigned long timeout) {
	String response;
	unsigned long started = millis();

	while (millis() - started < timeout) {
		while (Serial1.available()) {
			response += static_cast<char>(Serial1.read());
			if (response.indexOf(expected) >= 0) {
				return true;
			}
		}
	}

	return false;
}

bool sendCommand(const char *command, const char *expected, unsigned long timeout) {
	while (Serial1.available()) {
		Serial1.read();
	}
	Serial1.println(command);
	return waitForResponse(expected, timeout);
}

bool connectToWifi() {
	if (!sendCommand("AT", "OK", 2000)) {
		return false;
	}

	sendCommand("ATE0", "OK", 2000);
	sendCommand("AT+CWMODE=1", "OK", 3000);

	String joinCommand = "AT+CWJAP=\"";
	joinCommand += WIFI_SSID;
	joinCommand += "\",\"";
	joinCommand += WIFI_PASSWORD;
	joinCommand += "\"";

	return sendCommand(joinCommand.c_str(), "OK", 20000);
}

void showIpAddress() {
	while (Serial1.available()) {
		Serial1.read();
	}
	Serial1.println("AT+CIFSR");

	String response;
	unsigned long started = millis();
	while (millis() - started < 5000) {
		while (Serial1.available()) {
			response += static_cast<char>(Serial1.read());
		}
	}

	int ipStart = response.indexOf("STAIP,\"");
	if (ipStart < 0) {
		showMessage("WiFi connected", "IP unavailable");
		return;
	}

	ipStart += 7;
	int ipEnd = response.indexOf('"', ipStart);
	String ipAddress = response.substring(ipStart, ipEnd);
	showMessage("WiFi connected", ipAddress.c_str());
}

void setup() {
	Serial.begin(9600);
	Serial1.begin(ESP_BAUD);

	lcd.init();
	lcd.backlight();
	showMessage("Connecting WiFi", WIFI_SSID);

	if (!connectToWifi()) {
		showMessage("WiFi failed", "Check ESP/power");
		return;
	}

	showIpAddress();
}

void loop() {
	// Keep the Wi-Fi connection open and show ESP responses in the Serial Monitor.
	while (Serial1.available()) {
		Serial.write(Serial1.read());
	}
}

# Hello WiFi

This project uses an Arduino Mega, an ESP-01 Wi-Fi module, and a 16x2 LCD with an I2C backpack.

## LCD connections

| LCD pin | Arduino Mega |
| --- | --- |
| VCC | 5V |
| GND | GND |
| SDA | Digital pin 20 (SDA) |
| SCL | Digital pin 21 (SCL) |

The sketch uses LCD I2C address `0x27`. Some backpacks use `0x3F` instead.

## ESP-01 connections

| ESP-01 pin | Connect to |
| --- | --- |
| VCC | Regulated 3.3V supply |
| GND | Arduino Mega GND |
| TX | Mega RX1, digital pin 19 |
| RX | Mega TX1, digital pin 18 through a voltage divider |
| EN / CH_PD | 3.3V |
| GPIO0 | 3.3V for normal operation |
| RST | 3.3V through a pull-up, or leave it pulled high by the module |

For the voltage divider, connect:

```text
Mega TX1 (pin 18) --- 1k resistor --- ESP-01 RX
									  |
									  2k resistor
									  |
									 GND
```

The divider reduces the Mega's 5V TX signal to approximately 3.3V. The ESP-01 TX output can connect directly to the Mega RX1 input.

## Power

- Power the Arduino Mega from USB or, optionally, the 9V battery through its barrel jack.
- Do not connect the 9V battery directly to the ESP-01 or LCD.
- Use a stable external 3.3V regulator for the ESP-01, capable of at least 300mA.
- Connect the external regulator GND to Arduino Mega GND.

## Before uploading

Set the Wi-Fi credentials in `hello_wifi.ino`:

```cpp
const char WIFI_SSID[] = "YOUR_WIFI_NAME";
const char WIFI_PASSWORD[] = "YOUR_WIFI_PASSWORD";
```

The ESP-01 must have AT firmware installed and configured for `115200` baud.

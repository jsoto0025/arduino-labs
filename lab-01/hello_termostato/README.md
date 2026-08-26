## Hello Termostato

Reads temperature and humidity from a DHT11 sensor and displays them on a 16x2 I2C LCD.

### Wiring (Arduino Mega 2560)

**LCD1602 I2C backpack**

| LCD I2C backpack pin | Arduino Mega 2560 pin |
|-----------------------|------------------------|
| GND                    | GND                    |
| VCC                    | 5V                     |
| SDA                    | 20 (SDA)               |
| SCL                    | 21 (SCL)               |

**DHT11 module**

| DHT11 pin | Arduino Mega 2560 pin |
|-----------|------------------------|
| GND       | GND                    |
| VCC       | 5V                     |
| S (data)  | 7                      |

> The Mega 2560 uses dedicated pins 20/21 for I2C, not A4/A5 like the Uno. The DHT11 only needs a couple of seconds between reads, so the sketch polls it every 2 seconds.

### Sketch
See [hello_termostato.ino](hello_termostato.ino).

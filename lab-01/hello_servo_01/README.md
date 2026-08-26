## Hello Servo

Sweeps a Futaba S3003 servo back and forth using the Arduino `Servo` library.

### Wiring (easiest way — single servo powered from the Mega itself)

The Futaba S3003 has 3 wires:

| Servo wire   | Arduino Mega 2560 pin |
|--------------|------------------------|
| Red (VCC)    | 5V                     |
| Brown/Black (GND) | GND               |
| Orange (Signal) | 9 (PWM)             |

> A single S3003 draws little enough current at idle/light load that the Mega's 5V pin can power it directly for testing. If the servo jitters/resets or you're driving more than one, power it from an external 5-6V supply instead and tie its GND to the Mega's GND.

### Sketch
See [hello_servo_01.ino](hello_servo_01.ino).

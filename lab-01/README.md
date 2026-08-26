## Hellow Word Arduino

Simple "Hello World" sketch for the **Arduino Mega 2560 R3**, built with **VS Code** on **Mac**. It blinks the onboard LED and prints "Hello, World!" to the Serial Monitor.

### Hardware
- Arduino Mega 2560 R3
- USB-B cable (native USB, no FTDI adapter needed)

### Setup (VS Code on Mac)
1. Install the **Arduino IDE** (needed for the CLI/core files) and the **Arduino** extension in VS Code.

- [Arduino IDE](https://www.arduino.cc/en/software/)

2. Connect the Mega 2560 to the Mac via USB-B.
3. Open this folder (`lab-01/hello_world`) in VS Code.
4. In the Arduino extension: select **Board: Arduino Mega 2560**, and select the **Port** (`/dev/cu.usbmodemXXXX`).
5. Open `hello_world.ino`, then **Verify** (compile) and **Upload**.
6. Open the **Serial Monitor** at 9600 baud to see "Hello, World!" printed once per second, and watch the onboard LED (pin 13) blink.

### Sketch
See [hello_world/hello_world.ino](hello_world/hello_world.ino).


#  9 V battery.

Yes, that is a **9 V battery**. It powers small electronics and hobby circuits, but it is not ideal for driving motors because it provides limited current.
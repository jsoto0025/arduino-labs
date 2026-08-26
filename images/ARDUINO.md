# Arduino Hardware Summary

## Boards identified

### 1. Arduino Mega 2560 R3

![Arduino Mega 2560 front](./WhatsApp%20Image%202026-08-24%20at%202.16.59%20PM%20(1).jpeg)
![Arduino Mega 2560 back](./WhatsApp%20Image%202026-08-24%20at%202.16.59%20PM%20(2).jpeg)

A microcontroller board based on the ATmega2560, with 54 digital I/O pins, 16 analog inputs, 4 UARTs, and a native USB-B port.

**Used for:** projects needing many I/O pins, interrupts, or serial ports (e.g., multi-sensor robotics, 3D printer controllers, CNC machines).

**Connecting to a Mac:**
1. Connect via USB-B cable to a USB-A/USB-C port on the Mac (use a hub/adapter if only USB-C ports are available).
2. Install/open Arduino IDE, select **Tools > Board > Arduino Mega 2560**.
3. Select **Tools > Port > /dev/cu.usbmodemXXXX** (the Mega 2560 uses native USB, so macOS should recognize it without extra drivers).

### 2. FTDI Basic Breakout (red, 6-pin header)

![FTDI breakout board](./WhatsApp%20Image%202026-08-24%20at%202.17.00%20PM.jpeg)

A USB-to-serial (UART) adapter labeled `DTR RXD TXD 5V CTS GND`, typically for boards without a native USB port.

### 3. Funduino FTDI USB-to-Serial adapter (mini-USB)

![Funduino FTDI adapter](./WhatsApp%20Image%202026-08-24%20at%202.16.59%20PM.jpeg)

Same purpose as the breakout above: converts USB to TTL serial, with a jumper to select 3.3V or 5V logic level.

**Used for:** programming/communicating with boards that lack built-in USB-to-serial circuitry (e.g., bare ATmega chips, Arduino Pro Mini, Arduino Mini). Not needed for the Mega 2560 itself since it already has native USB.

**Connecting to a Mac:**
1. Connect via mini-USB, or wire the 6-pin header to the target board's serial pins (match TX↔RX, RX↔TX, GND↔GND, 5V/3.3V, and DTR to reset if auto-reset is needed).
2. macOS needs the **FTDI VCP driver** (from FTDI's website) unless it's a CH340/CP2102 clone — check the chip on the board and install the matching driver if the Mac doesn't show a `/dev/cu.usbserial-XXXX` port after plugging in.
3. Select that port in Arduino IDE's **Tools > Port** menu, and set the jumper to 5V or 3.3V matching the target board before connecting power.

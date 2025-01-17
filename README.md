# Caution: this is a fork.

Original at [/sqfmi/Watchy](//github.com/sqfmi/Watchy)

Forked for:
- experimentation
- esp-rtc workaround (my rtc is broken, see branch [esp-rtc-workaround](//github.com/hn3000/Watchy/tree/esp-rtc-workaround) )
- analog clock (I love a very plain analog clock style, see branch [plain-analog-clock](//github.com/hn3000/Watchy/tree/plain-analog-clock) )

# Watchy - Fully Open Source E-Paper Watch

![Watchy](https://watchy.sqfmi.com/img/watchy_render.png)

[**Pre-order Watchy!**](https://www.crowdsupply.com/sqfmi/watchy)
Now with injection molded or CNC'd aluminum case

Visit [**https://watchy.sqfmi.com**](https://watchy.sqfmi.com) for documentation, hardware design files, and more!

## Setup
1. In the Arduino IDE Boards Manager, install support for the ESP32. You can find instructions here: https://github.com/espressif/arduino-esp32/blob/master/docs/arduino-ide/boards_manager.md
2. Install this library (search for **Watchy** in the library manager), and any other depdencies when prompted
3. Check out the examples under ```Examples``` -> ```Watchy```
4. Compile & Upload with these board settings:
    * Board: "ESP32 Dev Module"
    * Partition Scheme: "Minimal SPIFFS"
    * All Other Settings: leave to default

You may also have to install the [CP2104 USB to Serial drivers](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers) if the port is not automatically detected

### Have Fun! :)
    
    

# Sensor Node Sources #

This directory contains the source codes for the sensor nodes consisting of (mainly) self-written ANSI-C libraries and the respective main applications for our sensor node fault detection approach.
The build system is makefile-based and requires only a minimum number of other libraries and tools.


## Prerequisites ##

In the following, the software requirements for Debian/Ubuntu and Windows machines are listed.

### Debian/Ubuntu ###

To compile the code, you need to have `avr-gcc`, `AVR Libc`, and `AVRDUDE` installed:  
  `sudo apt install gcc-avr avr-libc avrdude`  
That's basically it :)


### Windows ###

For Windows-based machines, the `WinAVR` tool can be used. Just download it from [Sourceforge](https://sourceforge.net/projects/winavr/) and install it; it includes `gcc-avr`, `avr-libc`, and `avrdude`. After installing it, you can use the tools from the [windows command prompt](https://www.makeuseof.com/tag/a-beginners-guide-to-the-windows-command-line/).


## AVRDUDE Basic Usage ##

Flashing the MCU and setting its fuses is done with [AVRDUDE](https://www.nongnu.org/avrdude/).
The basic commands are:
* **Flashing**:  
  `avrdude -p atmega1284p -c avrispv2 -P /dev/ttyACM0 -v -U flash:w:BINARY.hex`  
  The same can be achieved via the makefile by executing:  
  `make flash`
* **Erasing**:  
  `avrdude -p atmega1284p -c avrispv2 -P /dev/ttyACM0 -v -e`  
  The same can be achieved via the makefile by executing:  
  `make erase`
* **Write fuses**:
    * *Low fuses*:  
      `avrdude -p atmega1284p -c avrispv2 -P /dev/ttyACM0 -v -U lfuse:w:0xXX:m`
    * *High fuses*:  
      `avrdude -p atmega1284p -c avrispv2 -P /dev/ttyACM0 -v -U hfuse:w:0xXX:m`
    * *Extended fuses*:  
      `avrdude -p atmega1284p -c avrispv2 -P /dev/ttyACM0 -v -U efuse:w:0xXX:m`
    * The default fuse setings for our sensor nodes are:  
      `avrdude -p atmega1284p -c avrispv2 -P /dev/ttyACM0 -v -U lfuse:w:0xED:m -U hfuse:w:0xD9:m -U efuse:w:0xFF:m`  
      The same can be achieved via the makefile by executing:  
      `make defaultfuses`


## XBee 3 Zigbee ##

The XBee 3 is a powerful radio offering a wide range of functions.
In addition to Zigbee, 802.15.4 and Digimesh support (selectable by writing the appropriate firmware), it also has a BLE interface (disabled by default).
Using the BLE interface, you can configure the module using a smartphone in combination with the _Digi XBee Mobile_ app.
However, if you use the XBee for the first time and/or want to configure fresh modules, it is advisable to use Digi's [XCTU](https://www.digi.com/products/embedded-systems/digi-xbee/digi-xbee-tools/xctu) tool on a PC (Windows, Linux, Mac).
For that purpose, you will need to use a XBee to serial adapter such as the [Wavexhare XBee USB Adapter](https://www.waveshare.com/wiki/XBee_USB_Adapter).
Alternatively, the configuration can also be done via the UART interface and AT commands.

There is a [list of libraries](https://www.digi.com/resources/documentation/Digidocs/90001456-13/concepts/c_xbee_libraries_api_mode.htm?TocPath=XBee%20API%20mode%7C_____6) available to interface with the XBee modules.
In addition, you can simply use the module in transparent mode (tunnel UART) or program your own API function (e.g., as shown for [ATmega32](https://www.electronicwings.com/avr-atmega/xbee-interfacing-with-atmega32)).


### Configuration for our Testbed ###

In the following, the basic configuration of the XBee 3 modules for the use with our sensor nodes is described.
Depending on your application, requirements, etc. you may need to adapt certain parameters.
The explanation of the particular parameters and example configurations can be found in the [XBee 3 User Manual](https://www.digi.com/resources/documentation/digidocs/pdfs/90001539.pdf).
If you use the [XCTU](https://www.digi.com/products/embedded-systems/digi-xbee/digi-xbee-tools/xctu) tool for the configuration, the parameters are grouped to categories; the same as we use below.
Parameters not mentioned in the list below are left at their initial/default value.

* **Networking**
    * `CE` (_device role_)  
        set to `0` (join network).
    * `ID` (_extended PAN ID_)  
        set to a defined address, e.g., `FEDCBA9876543210`.

* **Discovery Options**
    * `NI` (_node identifier_)  
        you can set a user-defined name; we use `SNx` for our devices where `x` is a consecutive number.

* **RF Interfacing**
    * `PL` (_TX power level_)  
        to save energy, we use the lowest value `0` (-5 dBm).

* **Sleep Settings**
    * `SM` (_sleep mode_)  
        to enable the sleep mode, set this value to `1` (pin hibernate).  
        Be careful to have the sleep-request pin at the right logic level; otherwise the XBee goes to sleep and will not be accessible anymore!

* **Bluetooth Options**
    * We use the BLE interface during development to have an easy access to the XBee's setting via the [Digi XBee mobile app](https://www.digi.com/products/embedded-systems/digi-xbee/digi-xbee-tools/digi-xbee-mobile-app).  
        However, in the actual deployment, the BLE interface is deactivated to save energy and for security reasons.
    * `BT` (_Bluetooth enable_)  
        activate the BLE interface by setting this parameter to `1` (you will be asked to set a BLE password).
    * `BI` (_Bluetooth identifier_)  
        optionally, a user-defined BLE identifier can be set to easily identify the single XBees in the mobile app.  
        We use `XBee SNx` where the `SNx` part matches the _NI_ described above.  
        The prefix `XBee` is used to filter the available Bluetooth devices in the mobile app (i.e., only show Bluetooth devices whose identifier starts with `XBee`).
    * `BP` (_Bluetooth power_)  
        to save energy, we use the lowest value `0` (-20 dBm).

* **API Configuration**
    * `AP` (_API enable_)  
        we use the XBee in API mode, therefore, set this parameter to `1` (API mode without escapes).

* **UART Interface**
    * We use the default setting of the UART interface (i.e., 9600 8N1).
    * `BD` (_UART baud rate_)  
        set to `3` (9600 b/s)
    * `NB` (_UART parity_)  
        set to `0` (no parity)
    * `SB` (_UART stop bits_)  
        set to `0` (one stop bit)

* **I/O Settings**
    * To save energy, we deactivate the GPIOs usually used for status information.  
        However, be careful to leave the sleep request and asleep indicator assigned, especially when using pin hibernation!
    * `D5` (_DIO5/Associate Configuration_)  
        set to `0` (disabled)
    * `D8` (_DIO8/Sleep_Rq_)  
        set to `1` (DTR/Sleep_Rq)
    * `D9` (_DIO9/Sleep Indicator_)  
        set to `1` (Awake/Asleep indicator)
    * `P0` (_DIO10/RSSI Configuration_)  
        set to `0` (disabled)


## Program Execution

The general flow of program execution of our sensor node software is as follows:  
![Sensor Node Flowchart](../../media/flowchart/ftdca_flowchart-sn.svg)
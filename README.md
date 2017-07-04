# ArduinoDmxRelay
Arduino Sketch to control a (low-active) Relay Card via the DMX bus

## Equipment
* Arduino Uno or Mega
* CTC-DRA-10-R2 DMX Shield (https://www.dfrobot.com/product-984.html)
* Arduino 2-/4-/8-Channel Relay Card (https://www.sainsmart.com/8-channel-dc-5v-relay-module-for-arduino-pic-arm-dsp-avr-msp430-ttl-logic.html)
* A Computer with the Arduino IDE installed
* The Conceptinetics DMX Shield libary installed to your IDE
## Usage
1. Put the DMX Shield on top of the Arduino.
2. Connect the Relays (IN1 - IN8) to the Arduinos Digital Outputs (e.g. 12 to 5) [Attention! Pins 0 to 4 are used by the shield].
3. Connect the Power Supply Pins on the Relay Card to a 5V power source (the Arduino 5V supply may not be enough and can get hot, especially on large relay cards).
4. Adjust the `#define` variables to your needs.
  1. `DMX_ADDRESS` is the first address on the DMX bus to use
  2. `NUM_OF_RELAYS` is the number of relay connected to the board
  3. `FIRST_RELAY_OUTPUT` is the (lowest) output where the relay is connected
  4. `SWITCHING_THRESHOLD` is the value where the relay should toggle
5. Control your relays by DMX!

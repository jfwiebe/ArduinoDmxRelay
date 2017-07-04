/*
 * ArduinoDmxRelay
 * https://github.com/jfwiebe/ArduinoDmxRelay
 * Licensed under MIT License
 * 
 * This sketch uses the "DMX Libary for Arduino"
 * (https://sourceforge.net/projects/dmxlibraryforar/)
 * and a CTC-DRA-10-R2 DMX Shield to control a default 
 * Arduino Relay Card. For more Information, please
 * visit https://github.com/jfwiebe/ArduinoDmxRelay.
 */

#include <Conceptinetics.h>

#define DMX_ADDRESS 1
#define NUM_OF_RELAYS 8
#define FIRST_RELAY_OUTPUT 5
#define SWITCHING_THRESHOLD 127

DMX_Slave dmx_slave(NUM_OF_RELAYS);
const int lastRelayOutput = FIRST_RELAY_OUTPUT + (NUM_OF_RELAYS - 1);

void setup() {
  dmx_slave.enable();
  dmx_slave.setStartAddress(DMX_ADDRESS);

  for (int i = FIRST_RELAY_OUTPUT; i <= lastRelayOutput; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }
}

void loop() {
  int currentChannel = 1;
  for (int currentOutput = lastRelayOutput; currentOutput >= FIRST_RELAY_OUTPUT; currentOutput--) {
    if (dmx_slave.getChannelValue(currentChannel) > SWITCHING_THRESHOLD) {
      digitalWrite(currentOutput, LOW);
    } else {
      digitalWrite(currentOutput, HIGH);
    }
    currentChannel++;
    delay(10);
  }
}

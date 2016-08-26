// relay.cpp

#include "Configuration.h"

#include <Arduino.h>

#include "relay.h"

#define NUM_RELAYS  4
int relay_pins[NUM_RELAYS] = {RELAY_1_PIN, RELAY_2_PIN, RELAY_3_PIN, RELAY_4_PIN};
bool relay_inversion[NUM_RELAYS] = {true, true, true, true};

uint8_t lightingLevel = 0;

// gamma mapping table for LED lighting
const uint8_t PROGMEM gamma[] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
    2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
    5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
   10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
   17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
   25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
   37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
   51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
   69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
   90, 92, 93, 95, 96, 98, 99,101,102,104,105,107,109,110,112,114,
  115,117,119,120,122,124,126,127,129,131,133,135,137,138,140,142,
  144,146,148,150,152,154,156,158,160,162,164,167,169,171,173,175,
  177,180,182,184,186,189,191,193,196,198,200,203,205,208,210,213,
  215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255 };


void relay_init() {
	// ensure all control outputs are off, and set as outputs
    // relay control is active LOW
    for (int i =0; i<NUM_RELAYS; i++) {
        digitalWrite(relay_pins[i], relay_inversion[i] ? HIGH : LOW);
        pinMode(relay_pins[i], OUTPUT);
    }

    SET_OUTPUT(LIGHTS_PIN);
    analogWrite(LIGHTS_PIN, lightingLevel);
}

void turnRelayOn(int relay) {
    if (relay > 0 && relay <= NUM_RELAYS) {
        digitalWrite(relay_pins[relay-1], !relay_inversion[relay-1] ? HIGH : LOW);
    }
}

void turnRelayOff(int relay) {
	if (relay > 0 && relay <= NUM_RELAYS) {
        digitalWrite(relay_pins[relay-1], relay_inversion[relay-1] ? HIGH : LOW);
    }
}


void setLighting(int level) {
    if (level >=0 && level <=255) {
        lightingLevel = level;
        analogWrite(LIGHTS_PIN, pgm_read_byte(&gamma[level]));
    }
}

void fadeLighting(int level, int dur) {
    bool dir = true;
    int startLevel = lightingLevel;

    for (int j=0; j<dur; j++) {
        setLighting(j * 1.0 * (level-startLevel) / dur + startLevel);
        delay(1);
    }

    // make sure we get to target
    setLighting(level);
}

// laser.cpp

#include "Configuration.h"

#ifdef LASER
#include <avr/interrupt.h>
#include <Arduino.h>

#include "Laser.h"
#include "relay.h"

/*

Laser pin mapping
D6 - laser power (PWM) (to IN pin on laser PSU)
D7 - laser on/off (active high, to TH pin on laser PSU)

// POWER TESTS
// On 40W laser from cncsigntech on ebay

// 50% = 14.46mA
// 25% = 9.94 mA
// 75% = 19.26 mA   -  Max rating for tube!

*/

#define LASER_POWERLEVEL_PIN 	6   // PWM controlled
#define LASER_FIRE_PIN    	58       // toggled to actually fire

#define LASER_MAX_PWM_DUTYCYCLE 41   // max duty cycle as a percentage in range 0-100 - calibrate to max current level for laser tube

bool _laserIsArmed = false;
bool _laserIsOn    = false;
float _laserPower  = 0.0;

// laser_init - configures timers, etc
void laser_init() {
	// configure timer4 for Fast PWM on pin 6
	TCCR4A = _BV(WGM40) | _BV(COM4A1);     // FAST PWM, 8-bit, top is 0xFF | enable output on channel A (pin 6)
	TCCR4B = _BV(CS40) | _BV(WGM42);     // no prescaler | FAST PWM, 8-bit, top is 0xFF

	// ensure all control outputs are off
	//digitalWrite(LASER_PSU_ON_PIN, HIGH);
	digitalWrite(LASER_FIRE_PIN, LOW);

	// set control pins as outputs
	pinMode(LASER_POWERLEVEL_PIN, OUTPUT);
	pinMode(LASER_FIRE_PIN, OUTPUT);
	//pinMode(LASER_PSU_ON_PIN, OUTPUT);
}

// setLaserPower
// pwr in range 0.0 - 100.0 (represents percentage power output)
void setLaserPower(float pwr) {
	if (pwr > 100) pwr = 100;
	if (pwr < 0) pwr = 0;

	_laserPower = pwr;

	OCR4A = (int) ((pwr/100.0)*(LASER_MAX_PWM_DUTYCYCLE/100.0)*255);
}

// getLaserPower
// returns value in range 0.0 - 100.0 (represents percentage power output)
float getLaserPower() {
	return _laserPower;
}

// armLaser - enable 240v power to laser PSU
void armLaser() {
	turnLaserOff();

	turnRelayOn(1); // laser PSU
	turnRelayOn(2); // compressor

	_laserIsArmed = true;
}

// disarmLaser - disable 240v power to laser PSU
void disarmLaser() {
	turnRelayOff(1);  // laser PSU
	turnRelayOff(2); // compressor

	_laserIsArmed = false;

	turnLaserOff();
}

// isLaserArmed  - returns true if armed, false if not
bool isLaserArmed() {
	return _laserIsArmed;
}

// turnLaserOn - turn laser on, uses pre-specified power
void turnLaserOn() {
	if (isLaserArmed()) {
		digitalWrite(LASER_FIRE_PIN, HIGH);
		_laserIsOn = true;
	}
}

// turnLaserOff - turn laser off
void turnLaserOff() {
	digitalWrite(LASER_FIRE_PIN, LOW);
	_laserIsOn = false;
}

// isLaserOn - returns true if laser on
bool isLaserOn() {
	return _laserIsOn;
}

#endif

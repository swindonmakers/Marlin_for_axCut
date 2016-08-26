// laser.h

#ifndef Laser_h
#define Laser_h

// laser_init - configures timers, etc
void laser_init();

// setLaserPower
// pwr in range 0.0 - 100.0 (represents percentage power output)
void setLaserPower(float pwr);

// getLaserPower
// returns value in range 0.0 - 100.0 (represents percentage power output)
float getLaserPower();

// armLaser - enable 240v power to laser PSU
void armLaser();

// disarmLaser - disable 240v power to laser PSU
void disarmLaser();

// isLaserArmed  - returns true if armed, false if not
bool isLaserArmed();

// turnLaserOn - turn laser on, uses pre-specified power
void turnLaserOn();

// turnLaserOff - turn laser off
void turnLaserOff();

// isLaserOn - returns true if laser on
bool isLaserOn();

#endif
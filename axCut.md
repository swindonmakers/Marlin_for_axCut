=====
axCut
=====


New G-Codes
===========

*G5*
Bezier curve to X Y via I J K L at F mm/min



New M-Codes
===========

*M4*
Turn laser on at S<power>

*M5*
Turn laser off

*M666*
Set endstop adjustment factor for Y hall sensor (store with M500)

*M667*
Report endstop adjustment values

*M668*
Report laser status and settings

*M669*
Arm laser

*M690*
Disarm laser

*M671*
Testfire laser at S<power> for P<milliseconds>

*M680*
Turn on relay P<1-4>

*M681*
Turn off relay P<1-4>

*M682*
Set lighting level to S<0-255>

*M683*
Fade lighting level to S<0-255> over P<milliseconds>



Major file changes/additions
============================

* Configuration.h - general config (bed size, endstops) and watercooling defines
* CRC16.h CRC16.cpp - CRC16 routines
* laser.h / laser.cpp - laser control (init, set power, arm, on/off, etc)
* Marlin_main.cpp - tweaks to include additional libraries, CRC16 and custom G/M codes
* Marlin.h - extern statements for additional global vars (dual y homing)
* motion_control.h / motion_control.cpp - bezier routines
* PID_v1.h / PID_v1.cpp - generic PID library, used for water cooling fan speed control
* pins.h - updated pin defines for axCut (everything else stripped out)
* planner.h / planner.cpp - tweak to incorporate laser firing into block system
* relay.h / relay.cpp - generic relay control (and PWM driving lighting)
* stepper.cpp - additions for laser firing control, dual Y homing
* temperature.h / temperature.cpp - water cooling and laser temp monitoring

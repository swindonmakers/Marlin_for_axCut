=====
axCut
=====


Major file changes/additions:

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

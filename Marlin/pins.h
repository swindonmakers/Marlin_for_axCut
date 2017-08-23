#ifndef PINS_H
#define PINS_H

#define X_MS1_PIN -1
#define X_MS2_PIN -1
#define Y_MS1_PIN -1
#define Y_MS2_PIN -1
#define Z_MS1_PIN -1
#define Z_MS2_PIN -1
#define E0_MS1_PIN -1
#define E0_MS2_PIN -1
#define E1_MS1_PIN -1
#define E1_MS2_PIN -1
#define DIGIPOTSS_PIN -1


/****************************************************************************************
* Arduino Mega pin assignment
*
* Completely trashed by axCut overrides!
*
****************************************************************************************/
#define KNOWN_BOARD 1

//////////////////FIX THIS//////////////
#ifndef __AVR_ATmega1280__
 #ifndef __AVR_ATmega2560__
 #error Oops!  Make sure you have 'Arduino Mega' selected from the 'Tools -> Boards' menu.
 #endif
#endif


// uncomment one of the following lines for RAMPS v1.3 or v1.0, comment both for v1.2 or 1.1
#define RAMPS_V_1_3
// #define RAMPS_V_1_0

  #define LARGE_FLASH true


    #define X_STEP_PIN         54
    #define X_DIR_PIN          55
    #define X_ENABLE_PIN       38
    //#define X_MIN_PIN           3
    #define X_MIN_PIN           -1
    #define X_MAX_PIN           2

    #define Y_STEP_PIN         60
    #define Y_DIR_PIN          61
    #define Y_ENABLE_PIN       56
    //#define Y_MIN_PIN          14
    #define Y_MIN_PIN          -1
    #define Y_MAX_PIN          14

    // Y2 uses the E1 driver on the RAMPS1.4 board
    #define Y2_STEP_PIN        36
    #define Y2_DIR_PIN         34
    #define Y2_ENABLE_PIN      30
    #define Y2_MAX_PIN         15  // wired to Y_Min on RAMPS

    // the normal Z driver on the RAMPS board isn't used
    #define Z_STEP_PIN         46
    //#define Z_DIR_PIN          48
    //#define Z_ENABLE_PIN       62
    //#define Z_MIN_PIN          18
    #define Z_MIN_PIN          -1
    //#define Z_MAX_PIN          19

// then: 16&17 to 31&33
// 23,25,27,29 to 43,45,47,32

    // special Z driver connections for each of the four corner motors:
    #define Z_DIR_PIN          17
    #define Z_ENABLE_PIN       16

    #define Z_STEP_TL_PIN      23
    #define Z_STEP_BL_PIN      25
    #define Z_STEP_BR_PIN      27
    #define Z_STEP_TR_PIN      29

    #define Z_MAX_PIN          47 // TR used for default limit checking
    #define Z_MAX_TL_PIN       41
    #define Z_MAX_BL_PIN       43
    #define Z_MAX_BR_PIN       45
    #define Z_MAX_TR_PIN       47

    //#define Z2_STEP_PIN        36
    //#define Z2_DIR_PIN         34
    //#define Z2_ENABLE_PIN      30

    #define E0_STEP_PIN        26
    #define E0_DIR_PIN         28
    #define E0_ENABLE_PIN      24

    //#define E1_STEP_PIN        36
    //#define E1_DIR_PIN         34
    //#define E1_ENABLE_PIN      30

    #define SDPOWER            -1
    #define SDSS               53
    #define LED_PIN            13


    #define FAN_PIN			-1      // dummy setting, to avoid conflict with water cooling

  #define PS_ON_PIN          12

  #define KILL_PIN           -1

  #define HEATER_0_PIN       -1

  #define HEATER_2_PIN       -1

  #define TEMP_0_PIN         13   // ambient
  #define TEMP_1_PIN         14   // inlet
  #define TEMP_2_PIN         15   // outlet

  #define HEATER_BED_PIN     -1    // NO BED
  #define TEMP_BED_PIN       -1   // ANALOG NUMBERING

  // relay control
  #define RELAY_1_PIN        65  // laser
  #define RELAY_2_PIN        42  // compressor
  #define RELAY_3_PIN        40  // spare
  #define RELAY_4_PIN        63  // extractor

  #define LIGHTS_PIN            8  // LED lighting, on D8 terminal block!


  #ifdef NUM_SERVOS
    #define SERVO0_PIN         11

    #if NUM_SERVOS > 1
      #define SERVO1_PIN         6
    #endif

    #if NUM_SERVOS > 2
      #define SERVO2_PIN         5
    #endif

    #if NUM_SERVOS > 3
      #define SERVO3_PIN         4
    #endif
  #endif

  #ifdef TEMP_STAT_LEDS
    #if MOTHERBOARD == 67
      #define STAT_LED_RED       6
      #define STAT_LED_BLUE     11
    #endif
  #endif

  #ifdef ULTRA_LCD

    #ifdef NEWPANEL
      #define LCD_PINS_RS 16
      #define LCD_PINS_ENABLE 17
      #define LCD_PINS_D4 23
      #define LCD_PINS_D5 25
      #define LCD_PINS_D6 27
      #define LCD_PINS_D7 29

      #ifdef REPRAP_DISCOUNT_SMART_CONTROLLER
        #define BEEPER 37

        #define BTN_EN1 31
        #define BTN_EN2 33
        #define BTN_ENC 35

        #define SDCARDDETECT 49
      #elif defined(LCD_I2C_PANELOLU2)
        #define BTN_EN1 47  //reverse if the encoder turns the wrong way.
        #define BTN_EN2 43
        #define BTN_ENC 32
        #define SDSS 53
        #define SDCARDDETECT -1
        #define KILL_PIN 41
      #elif defined(LCD_I2C_VIKI)
        #define BTN_EN1 22  //reverse if the encoder turns the wrong way.
        #define BTN_EN2 7
        #define BTN_ENC -1
        #define SDSS 53
        #define SDCARDDETECT 49
      #else
        //arduino pin which triggers an piezzo beeper
        #define BEEPER 33  // Beeper on AUX-4

        //buttons are directly attached using AUX-2
        #ifdef REPRAPWORLD_KEYPAD
          #define BTN_EN1 64 // encoder
          #define BTN_EN2 59 // encoder
          #define BTN_ENC 63 // enter button
          #define SHIFT_OUT 40 // shift register
          #define SHIFT_CLK 44 // shift register
          #define SHIFT_LD 42 // shift register
        #else
          #define BTN_EN1 37
          #define BTN_EN2 35
          #define BTN_ENC 31  //the click
        #endif

        #ifdef G3D_PANEL
          #define SDCARDDETECT 49
        #else
          #define SDCARDDETECT -1  // Ramps does not use this port
        #endif

      #endif

      #if MOTHERBOARD == 77
        #define BEEPER -1

        #define LCD_PINS_RS 27
        #define LCD_PINS_ENABLE 29
        #define LCD_PINS_D4 37
        #define LCD_PINS_D5 35
        #define LCD_PINS_D6 33
        #define LCD_PINS_D7 31

       //buttons
       #define BTN_EN1 16
       #define BTN_EN2 17
       #define BTN_ENC 23 //the click

    #endif
    #else //old style panel with shift register
      //arduino pin witch triggers an piezzo beeper
      #define BEEPER 33		//No Beeper added

      //buttons are attached to a shift register
	// Not wired this yet
      //#define SHIFT_CLK 38
      //#define SHIFT_LD 42
      //#define SHIFT_OUT 40
      //#define SHIFT_EN 17

      #define LCD_PINS_RS 16
      #define LCD_PINS_ENABLE 17
      #define LCD_PINS_D4 23
      #define LCD_PINS_D5 25
      #define LCD_PINS_D6 27
      #define LCD_PINS_D7 29
    #endif
  #endif //ULTRA_LCD


// SPI for Max6675 Thermocouple

#ifndef SDSUPPORT
// these pins are defined in the SD library if building with SD support
  #define MAX_SCK_PIN          52
  #define MAX_MISO_PIN         50
  #define MAX_MOSI_PIN         51
  #define MAX6675_SS       53
#else
  #define MAX6675_SS       49
#endif





#ifndef KNOWN_BOARD
#error Unknown MOTHERBOARD value in configuration.h
#endif

//List of pins which to ignore when asked to change by gcode, 0 and 1 are RX and TX, do not mess with those!
#define _E0_PINS E0_STEP_PIN, E0_DIR_PIN, E0_ENABLE_PIN, HEATER_0_PIN,
#if EXTRUDERS > 1
  #define _E1_PINS E1_STEP_PIN, E1_DIR_PIN, E1_ENABLE_PIN, HEATER_1_PIN,
#else
  #define _E1_PINS
#endif
#if EXTRUDERS > 2
  #define _E2_PINS E2_STEP_PIN, E2_DIR_PIN, E2_ENABLE_PIN, HEATER_2_PIN,
#else
  #define _E2_PINS
#endif

#ifdef X_STOP_PIN
  #if X_HOME_DIR < 0
    #define X_MIN_PIN X_STOP_PIN
    #define X_MAX_PIN -1
  #else
    #define X_MIN_PIN -1
    #define X_MAX_PIN X_STOP_PIN
  #endif
#endif

#ifdef Y_STOP_PIN
  #if Y_HOME_DIR < 0
    #define Y_MIN_PIN Y_STOP_PIN
    #define Y_MAX_PIN -1
  #else
    #define Y_MIN_PIN -1
    #define Y_MAX_PIN Y_STOP_PIN
  #endif
#endif

#ifdef Z_STOP_PIN
  #if Z_HOME_DIR < 0
    #define Z_MIN_PIN Z_STOP_PIN
    #define Z_MAX_PIN -1
  #else
    #define Z_MIN_PIN -1
    #define Z_MAX_PIN Z_STOP_PIN
  #endif
#endif

#ifdef DISABLE_MAX_ENDSTOPS
#define X_MAX_PIN          -1
#define Y_MAX_PIN          -1
#define Z_MAX_PIN          -1
#endif

#ifdef DISABLE_MIN_ENDSTOPS
#define X_MIN_PIN          -1
#define Y_MIN_PIN          -1
#define Z_MIN_PIN          -1
#endif

#define SENSITIVE_PINS {0, 1, X_STEP_PIN, X_DIR_PIN, X_ENABLE_PIN, X_MIN_PIN, X_MAX_PIN, Y_STEP_PIN, Y_DIR_PIN, Y_ENABLE_PIN, Y_MIN_PIN, Y_MAX_PIN, Z_STEP_PIN, Z_DIR_PIN, Z_ENABLE_PIN, Z_MIN_PIN, Z_MAX_PIN, PS_ON_PIN, \
                        HEATER_BED_PIN, FAN_PIN,                  \
                        _E0_PINS _E1_PINS _E2_PINS             \
                        Z_STEP_TL_PIN, Z_STEP_BL_PIN, Z_STEP_BR_PIN, Z_STEP_TR_PIN, \
                        Z_MAX_TL_PIN, Z_MAX_TR_PIN, Z_MAX_BL_PIN, Z_MAX_BR_PIN, \
                        analogInputToDigitalPin(TEMP_0_PIN), analogInputToDigitalPin(TEMP_1_PIN), analogInputToDigitalPin(TEMP_2_PIN), analogInputToDigitalPin(TEMP_BED_PIN) }
#endif

// #define DEV_MODE
#define PROD_MODE

#define MOTORS_COUNT 9

#ifndef settings_h
#define settings_h

  #ifdef DEV_MODE
    #define DEBUG(x) Serial.println(x)
  #else
    #define DEBUG(x)
  #endif
  
  #ifdef PROD_MODE
    #define SERIAL_SPEED 7200
  #else
    #define SERIAL_SPEED 115200
  #endif

#endif

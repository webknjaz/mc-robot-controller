#ifndef peripheral_h
#define peripheral_h

#include <Arduino.h>

namespace peripheral {
  class Peripheral {
    public:
      Peripheral();
      void init();
      
      byte getMotorAngle(byte);
      void setMotorAngle(byte motor, byte angle);
  };
}


#endif

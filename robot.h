#ifndef robot_h
#define robot_h

#include <Arduino.h>

#include "protocol.h"
#include "peripheral.h"

namespace robot {
  class Robot {
    public:
      void init();
      Robot(protocol::Protocol *, peripheral::Peripheral *);
      
      byte getAngle(byte motor);
      void setAngle(byte motor, byte angle);
    private:
      protocol::Protocol *proto;
      peripheral::Peripheral *hw;
  };
}


#endif

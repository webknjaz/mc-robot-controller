#ifndef protocol_h
#define protocol_h

#include <Arduino.h>

namespace protocol {
  class Protocol {
    public:
      Protocol();

      void init();
      byte requestAngle(byte motor, byte angle);
  };
}


#endif

#include "settings.h"
#include "protocol.h"

protocol::Protocol::Protocol() {
  Serial.begin(SERIAL_SPEED);
  DEBUG();
  DEBUG("[debug] Protocol constructed.");
}

void protocol::Protocol::init() {
  Serial.write((byte)0x00);
  DEBUG();
  DEBUG("[debug] Protocol initialized.");
}

byte protocol::Protocol::requestAngle(byte motor, byte angle) {
  DEBUG();
  DEBUG("[debug] Requesting new angle.");
  Serial.write(motor);
  Serial.write(angle);
  
  while (1) {
    if (Serial.available() > 0) {
      DEBUG("[debug] Got new angle.");
      angle = Serial.read();
      DEBUG(angle);
      return angle;
    }
    
    delay(1);
  }
}

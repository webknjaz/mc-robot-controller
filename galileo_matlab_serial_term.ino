#include "settings.h"
#include "protocol.h"
#include "peripheral.h"
#include "robot.h"

using namespace protocol;
using namespace peripheral;
using namespace robot;

byte angle;
Robot *r;
Protocol *p;
String st;

void setup() {
  Peripheral *hw = new Peripheral();
  p = new Protocol();
  r = new Robot(p, hw);
}

void loop() {
  // == Reference ==
  // Serial.print()      == print out a string
  // Serial.println()    == print + LineNew
  // Serial.write()      == print out a byte
  // Serial.available()  == returns number of bytes available for reading
  // Serial.read()       == returns one byte read
  // Serial.parseInt() && Serial.parseFloat() read Serial characters and return their numeric representation
  // http://stackoverflow.com/questions/5697047/convert-serial-read-into-a-useable-string-using-arduino : 
  // Serial.readString() and Serial.readStringUntil() to parse strings from Serial on arduino
  
  for (byte motorNum = 1; motorNum <= MOTORS_COUNT; motorNum++) {
    angle = r->getAngle(motorNum);
    angle = p->requestAngle(motorNum, angle);  // requesting new angle
    r->setAngle(motorNum, angle);  // setting new angle
  }

  if (Serial.available() > 0) {
    st = Serial.readStringUntil('\n');
    Serial.println(st);
    Serial.println(st.length());
  }
}

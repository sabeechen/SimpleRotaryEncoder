#ifndef ROTARY_ENCODER_H
#define ROTARY_ENCODER_H

#include "Arduino.h"

class RotaryEncoder {
  private:
  const int pattern[4] = {2, 0, 3, 1};
  int rotarypin1;
  int rotarypin2;
  int buttonpin;
  void (*buttondowncb)();
  void (*buttonupcb)();
  void (*cwcb)();
  void (*ccwcb)();
  bool buttonWasDown;
  int encoderLastState;
  int lastReportedState;
  
  public:
  RotaryEncoder(int rotaryPin1, int rotaryPin2, int buttonPin);
  void setup() ;
  void setButtonDownCallback(void (*cb)());
  void setButtonUpCallback(void (*cb)());
  void setRotateCWCallback(void (*cb)());
  void setRotateCCWCallback(void (*cb)());
  void loop();
};

#endif // ROTARY_ENCODER_H
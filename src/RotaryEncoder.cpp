#include "RotaryEncoder.h"

RotaryEncoder* theEncoder;

void rotaryEncoderIsr() {
  theEncoder->loop();
}

RotaryEncoder::RotaryEncoder(int rotaryPin1, int rotaryPin2, int buttonPin) {
  rotarypin1 = rotaryPin1;
  rotarypin2 = rotaryPin2;
  buttonpin = buttonPin;
}

void RotaryEncoder::setup() {
  pinMode(rotarypin1, INPUT_PULLUP);
  pinMode(rotarypin2, INPUT_PULLUP);
  pinMode(buttonpin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(rotarypin1), rotaryEncoderIsr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(rotarypin2), rotaryEncoderIsr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(buttonpin), rotaryEncoderIsr, CHANGE);
  buttonWasDown = digitalRead(buttonpin) == LOW;
  encoderLastState = (digitalRead(rotarypin1) << 1) | digitalRead(rotarypin2);
  theEncoder = this;
}

void RotaryEncoder::setButtonDownCallback(void (*cb)()) {
  buttondowncb = cb;
}

void RotaryEncoder::setButtonUpCallback(void (*cb)()) {
  buttonupcb = cb;
}

void RotaryEncoder::setRotateCWCallback(void (*cb)()) {
  cwcb = cb;
}

void RotaryEncoder::setRotateCCWCallback(void (*cb)()) {
  ccwcb = cb;
}

void RotaryEncoder::loop() {
  if ((digitalRead(buttonpin) == LOW) != buttonWasDown) {
    if (buttonWasDown && buttonupcb != NULL) buttonupcb();
    else if (buttondowncb != NULL) buttondowncb();
    buttonWasDown = !buttonWasDown;
  }

  int rotaryState = (digitalRead(rotarypin1) << 1) | digitalRead(rotarypin2);
  if (encoderLastState != rotaryState) {
    if (pattern[encoderLastState] == rotaryState 
        && cwcb != NULL 
        && (rotaryState == 0 || rotaryState == 3)
        && lastReportedState != rotaryState)  {
          cwcb();
          lastReportedState = rotaryState;
        }
    else if (pattern[3-encoderLastState] == rotaryState 
        && ccwcb != NULL 
        && (rotaryState == 0 || rotaryState == 3)
        && lastReportedState != rotaryState) {
          ccwcb();
          lastReportedState = rotaryState;
        }
    encoderLastState = rotaryState;
  }
}

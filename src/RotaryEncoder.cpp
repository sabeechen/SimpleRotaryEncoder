#include "RotaryEncoder.h"

RotaryEncoder* theEncoder;

void veryHackyRotaryEncoderIsr() {
  theEncoder->loop();
}

RotaryEncoder::RotaryEncoder(int rotaryPin1, int rotaryPin2, int buttonPin) {
  rotarypin1 = rotaryPin1;
  rotarypin2 = rotaryPin2;
  buttonpin = buttonPin;
}

RotaryEncoder::RotaryEncoder(int rotaryPin1, int rotaryPin2) {
  rotarypin1 = rotaryPin1;
  rotarypin2 = rotaryPin2;
  buttonpin = -1;
}

void RotaryEncoder::setup() {
  pinMode(rotarypin1, INPUT_PULLUP);
  pinMode(rotarypin2, INPUT_PULLUP);
  pinMode(buttonpin, INPUT_PULLUP);
  if (buttonpin >= 0) {
    buttonWasDown = digitalRead(buttonpin) == LOW;
  }
  if (rotarypin1 >=0 && rotarypin2 >= 0) {
    encoderLastState = (digitalRead(rotarypin1) << 1) | digitalRead(rotarypin2);
  }
}

void RotaryEncoder::setupInterrupts() {
  setupInterrupts(veryHackyRotaryEncoderIsr);
  theEncoder = this;
}

void RotaryEncoder::setupInterrupts(void (*cb)()) {
  if (rotarypin1 >=0 && rotarypin2 >= 0) {
  	attachInterrupt(digitalPinToInterrupt(rotarypin1), cb, CHANGE);
  	attachInterrupt(digitalPinToInterrupt(rotarypin2), cb, CHANGE);
  }
  if (buttonpin >= 0) {
  	attachInterrupt(digitalPinToInterrupt(buttonpin), cb, CHANGE);
  }
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

bool RotaryEncoder::buttonIsDown() {
  return buttonWasDown;
}

void RotaryEncoder::loop() {
  if (buttonpin >= 0 && (digitalRead(buttonpin) == LOW) != buttonWasDown) {
    if (buttonWasDown && buttonupcb != NULL) buttonupcb();
    else if (buttondowncb != NULL) buttondowncb();
    buttonWasDown = !buttonWasDown;
  }

  if (rotarypin1 < 0 || rotarypin2 < 0) return;
  int rotaryState = (digitalRead(rotarypin1) << 1) | digitalRead(rotarypin2);
  if (encoderLastState != rotaryState) {
    if (pattern[encoderLastState] == rotaryState 
        && cwcb != NULL 
        && (rotaryState == 0 || rotaryState == 3)
        && lastReportedState != rotaryState)  {
          cwcb();
          lastReportedState = rotaryState;
          lastWasClockwise = true;
    }
    else if (pattern[3-encoderLastState] == rotaryState 
        && ccwcb != NULL 
        && (rotaryState == 0 || rotaryState == 3)
        && lastReportedState != rotaryState) {
          ccwcb();
          lastReportedState = rotaryState;
          lastWasClockwise = false;
    } else if (rotaryState == 0 || rotaryState == 3) {
    	// Either the switch malfunctioned or we didn't get updates fast enough to catch the 
    	// transitions, so do our best to infer what the rotation direction was from the last 
    	// rotation.
    	if (lastWasClockwise) cwcb();
    	else ccwcb();
    }

    encoderLastState = rotaryState;
  }
}

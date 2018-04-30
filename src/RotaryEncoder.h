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
  bool lastWasClockwise = true;
  
  public:
  /* Configures this to use a rotary encoder with an additional button. */
  RotaryEncoder(int rotaryPin1, int rotaryPin2, int buttonPin);

  /* Configures this to use a rotary encoder without a button. */
  RotaryEncoder(int rotaryPin1, int rotaryPin2);

  /* Must be called before other methods, sets up pullup mode for each pin. */
  void setup();

  /* 
   * Configures the encoder to use interrupts.  Using interrupts mitigates the need to call 
   * loop() periodically.
   */
  void setupInterrupts();

  /* 
   * Configures the encoder to use interrupts.  The passed in callback must call this->loop().
   */
  void setupInterrupts(void (*cb)());

  /* 
   * Sets the callback to be called when the button is pushed down.  
   * Expects a no argument method returning void. 
   */
  void setButtonDownCallback(void (*cb)());

  /* 
   * Sets the callback to be called when the button is released.  
   * Expects a no argument method returning void. 
   */
  void setButtonUpCallback(void (*cb)());

  /* 
   * Sets the callback to be called when the encoder is rotated clockwise.  
   * Expects a no argument method returning void. 
   */
  void setRotateCWCallback(void (*cb)());

  /* 
   * Sets the callback to be called when the encoder is counter-rotated clockwise.
   * Expects a no argument method returning void. 
   */
  void setRotateCCWCallback(void (*cb)());

  /* 
   * Returns true if the button ahs been pressed. 
   */
  bool buttonIsDown();

  /* 
   * If using interrupts, this method can be ignored.  If not, call this method very frequently 
   * from your loop to decet the encoder state and handle events.
   */
  void loop();
};

#endif // ROTARY_ENCODER_H
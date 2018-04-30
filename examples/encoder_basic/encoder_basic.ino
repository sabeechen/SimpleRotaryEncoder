#include <RotaryEncoder.h>

#define ENCODER_PIN1 13
#define ENCODER_PIN2 14
#define BUTTON_PIN 12

RotaryEncoder encoder(ENCODER_PIN1, ENCODER_PIN2, BUTTON_PIN);

void buttonDown() {
  Serial.println("button down");
}

void buttonUp() {
  Serial.println("button up");
}

void movedClockwise() {
  Serial.println("moved clockwise");
}

void movedCounterClockwise() {
  Serial.println("moved counter-clockwise");
}

void setup() {
  Serial.begin(115200);
  encoder.setup();
  encoder.setupInterrupts();
  encoder.setButtonDownCallback(buttonDown);
  encoder.setButtonUpCallback(buttonUp);
  encoder.setRotateCWCallback(movedClockwise);
  encoder.setRotateCCWCallback(movedCounterClockwise);
}

void loop() {
}
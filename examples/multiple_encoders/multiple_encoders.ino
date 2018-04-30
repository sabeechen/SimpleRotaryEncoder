#include <RotaryEncoder.h>

#define ENCODER1_PIN1 13
#define ENCODER1_PIN2 14

#define ENCODER2_PIN1 12
#define ENCODER2_PIN2 11

RotaryEncoder encoder1(ENCODER1_PIN1, ENCODER1_PIN2);
RotaryEncoder encoder2(ENCODER2_PIN1, ENCODER2_PIN2);

void movedClockwise() {
  Serial.println("moved clockwise");
}

void movedCounterClockwise() {
  Serial.println("moved counter-clockwise");
}

void encoder1Interrupt() {
  encoder1.loop();
}

void encoder2Interrupt() {
  encoder2.loop();
}

void setup() {
  Serial.begin(115200);
  
  encoder1.setup();
  encoder1.setupInterrupts(encoder1Interrupt);
  encoder1.setRotateCWCallback(movedClockwise);
  encoder1.setRotateCCWCallback(movedCounterClockwise);

  encoder2.setup();
  encoder2.setupInterrupts(encoder2Interrupt);
  encoder2.setRotateCWCallback(movedClockwise);
  encoder2.setRotateCCWCallback(movedCounterClockwise);
}

void loop() {
}
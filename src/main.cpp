#include <Arduino.h>
#include <Stepper.h>

Stepper alt_stepper(200, 2, 3, 4, 5);
Stepper az_stepper(200, 6, 7, 8, 9);

int alt_steps = 0;
bool going_up = true;

void moveAzStepper();

void setup() {
  alt_stepper.setSpeed(1);
  az_stepper.setSpeed(1);
}

void moveAltStepper() {
  if (going_up) {
    alt_stepper.step(3);
    alt_steps += 3;
    delay(10000); // 10 seconds

    if (alt_steps >= 201) {
      moveAzStepper();
      going_up = false;
    }
  } else {
    alt_stepper.step(-3);
    alt_steps -= 3;
    delay(10000); // 10 seconds

    if (alt_steps <= 0) {
      going_up = true;
    }
  }
}

void moveAzStepper() {
  az_stepper.step(6); // Move the second motor 6 degrees
}

void loop() {
  moveAltStepper();
}
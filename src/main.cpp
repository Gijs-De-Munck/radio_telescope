#include <Arduino.h>
#include <Stepper.h>

Stepper alt_stepper(200, 2, 3, 4, 5);
Stepper az_stepper(200, 6, 7, 8, 9);

int alt_steps = 0;
bool going_up = true;

void setup() {
  Serial.begin(9600);
  alt_stepper.setSpeed(1);
  az_stepper.setSpeed(1);
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    int commaIndex = input.indexOf(',');
    int alt_step_value = input.substring(0, commaIndex).toInt();
    int az_step_value = input.substring(commaIndex + 1).toInt();

    if (going_up) {
      alt_stepper.step(alt_step_value);
      alt_steps += alt_step_value;
      delay(10000); // 10 seconds

      if (alt_steps >= 201) {
        az_stepper.step(az_step_value); // Move the second motor
        going_up = false;
      }
    } else {
      alt_stepper.step(-alt_step_value);
      alt_steps -= alt_step_value;
      delay(10000); // 10 seconds

      if (alt_steps <= 0) {
        going_up = true;
      }
    }
  }
}
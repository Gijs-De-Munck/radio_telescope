#include <Arduino.h>
#include <Stepper.h>

Stepper alt_stepper(200, 2, 3, 4, 5);
Stepper az_stepper(200, 6, 7, 8, 9);

int current_alt_position = 0;
int current_az_position = 0;

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

    int alt_steps_to_move = alt_step_value - current_alt_position;
    int az_steps_to_move = az_step_value - current_az_position;

    alt_stepper.step(alt_steps_to_move);
    az_stepper.step(az_steps_to_move);

    current_alt_position = alt_step_value;
    current_az_position = az_step_value;
  }
}
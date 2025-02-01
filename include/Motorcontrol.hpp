#ifndef __MOTORCONTROL_HPP
#define __MOTORCONTROL_HPP

#include <Arduino.h>
#include <Stepper.h>

void processInput(String input, Stepper &alt_stepper, Stepper &az_stepper, int &current_alt_position, int &current_az_position);
void moveSteppers(Stepper &alt_stepper, Stepper &az_stepper, int &current_alt_position, int &current_az_position, int alt_step_value, int az_step_value);

#endif
#include <Motorcontrol.hpp>

void moveSteppers(Stepper &alt_stepper, Stepper &az_stepper, int &current_alt_position, int &current_az_position,int alt_step_value,int az_step_value) {
  int alt_steps_to_move = alt_step_value - current_alt_position; // Calculate the number of steps to move for altitude
  int az_steps_to_move = az_step_value - current_az_position; // Calculate the number of steps to move for azimuth

  alt_stepper.step(alt_steps_to_move); // Move the altitude stepper motor to the new position
  az_stepper.step(az_steps_to_move); // Move the azimuth stepper motor to the new position

  current_alt_position = alt_step_value; // Update the current altitude position
  current_az_position = az_step_value; // Update the current azimuth position
}

void processInput(String input, Stepper &alt_stepper, Stepper &az_stepper, int &current_alt_position, int &current_az_position) {
  int commaIndex = input.indexOf(','); // Find the index of the comma separating altitude and azimuth values

  int alt_step_value = input.substring(0, commaIndex).toInt(); // Extract and convert the altitude step value from the input string
  int az_step_value = input.substring(commaIndex + 1).toInt(); // Extract and convert the azimuth step value from the input string

  moveSteppers(alt_stepper, az_stepper, current_alt_position, current_az_position, alt_step_value, az_step_value); // Move the steppers to the new positions
}
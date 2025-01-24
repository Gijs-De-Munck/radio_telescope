#include <Arduino.h>
#include <Stepper.h>

Stepper alt_stepper(200, 2, 3, 4, 5); //change this to the correct pins
Stepper az_stepper(200, 6, 7, 8, 9); //change this to the correct pins

int current_alt_position = 0;
int current_az_position = 0;

/**
 * @brief Initializes the serial communication and sets the speed for the stepper motors.
 * 
 * This function is called once when the program starts. It sets up the serial communication
 * with a baud rate of 9600 and configures the speed for both the altitude and azimuth stepper motors.
 */
void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate
  alt_stepper.setSpeed(5); // Set speed for altitude stepper motor
  az_stepper.setSpeed(5); // Set speed for azimuth stepper motor
}

/**
 * @brief Main loop that continuously checks for serial input and moves the stepper motors accordingly.
 * 
 * This function runs repeatedly after the setup function. It checks if there is any serial input available.
 * If there is, it reads the input, parses the altitude and azimuth step values, calculates the steps to move,
 * and commands the stepper motors to move to the new positions.
 */
void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); // Read the input string until a newline character is encountered
    
    int commaIndex = input.indexOf(','); // Find the index of the comma separating altitude and azimuth values
    
    int alt_step_value = input.substring(0, commaIndex).toInt(); // Extract and convert the altitude step value from the input string
    int az_step_value = input.substring(commaIndex + 1).toInt(); // Extract and convert the azimuth step value from the input string

    int alt_steps_to_move = alt_step_value - current_alt_position; // Calculate the number of steps to move for altitude
    int az_steps_to_move = az_step_value - current_az_position; // Calculate the number of steps to move for azimuth

    alt_stepper.step(alt_steps_to_move); // Move the altitude stepper motor to the new position
    az_stepper.step(az_steps_to_move); // Move the azimuth stepper motor to the new position

    current_alt_position = alt_step_value; // Update the current altitude position
    current_az_position = az_step_value; // Update the current azimuth position
  }
}
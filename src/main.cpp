#include <Arduino.h>
#include <Stepper.h>
#include <Motorcontrol.hpp>

Stepper alt_stepper(200, 2, 3, 4, 5); //change this to the correct pins
Stepper az_stepper(200, 6, 7, 8, 9); //change this to the correct pins

int current_alt_position = 0;
int current_az_position = 0;


void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate
  alt_stepper.setSpeed(5); // Set speed for altitude stepper motor
  az_stepper.setSpeed(5); // Set speed for azimuth stepper motor
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); // Read the input string until a newline character is encountered
    processInput(input, alt_stepper, az_stepper, current_alt_position, current_az_position); // Process the input string with steppers
  }
}
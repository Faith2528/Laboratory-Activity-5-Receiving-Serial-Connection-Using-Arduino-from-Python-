#include "LEDControl.h"

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Initialize LED pins
  initializeLEDs();
  
  // Wait for serial connection to be established
  while (!Serial) {
    ; // Wait for serial port to connect
  }
  
  Serial.println("Arduino LED Control Ready");
  Serial.println("Commands: R/r (Red), G/g (Green), B/b (Blue), A/a (All ON), O/o (All OFF)");
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read(); // Read the incoming byte
    
    // Process the command
    processCommand(command);
  }
}


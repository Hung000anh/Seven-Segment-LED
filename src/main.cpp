#include <Arduino.h>

// Define the pins for each segment (a to g) and the common cathode pin
const int segmentPins[8] = {2, 3, 4, 5, 6, 7, 8};
const int commonCathodePin = 9;

// Define the numbers to display on the seven-segment display
const byte numbers[11] = {
  B11111100, // 0
  B01100000, // 1
  B11011010, // 2
  B11110010, // 3
  B01100110, // 4
  B10110110, // 5
  B10111110, // 6
  B11100000, // 7
  B11111110, // 8
  B11110110  // 9
};

void setup() {
  // Set segment pins as outputs
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }

  // Set common cathode pin as output
  pinMode(commonCathodePin, OUTPUT);
}

// Function to display a digit on the seven-segment display
void displayNumber(int num) {
  // Turn off all segments
  for (int i = 0; i < 8; i++) {
    digitalWrite(segmentPins[i], HIGH);
  }

  // Activate segments based on the number to be displayed
  for (int i = 0; i < 8; i++) {
    if (bitRead(numbers[num], i) == LOW) {
      digitalWrite(segmentPins[7-i], LOW);
    }
  }

  // Turn on the common cathode to display the digit
 // digitalWrite(commonCathodePin, LOW);
}


void loop() {
  // Count from 0 to 9
  for (int i = 0; i < 10; i++) 
  {
    displayNumber(i);
    delay(1000); // Display each number for 1 second
  }
}



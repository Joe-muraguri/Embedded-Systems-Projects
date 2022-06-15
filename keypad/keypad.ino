
// Include the Keypad library
#include <Keypad.h>

// Constants for row and column sizes
const byte ROWS = 4;
const byte COLS = 4;

// Array to represent keys on keypad
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Connections to Arduino
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

// Create keypad object
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  // Setup serial monitor
  Serial.begin(9600);
}

void loop() {
  // Get key value if pressed
  int Number = 0;
  char customKey = customKeypad.getKey();

  if (customKey) {
    if(customKey == '1'){
      if(Number == 0)
        Number = 1;
      else 
        Number = (Number*10) + 1;
      }
    // Print key value to serial monitor
    Serial.println(customKey);
  }
}

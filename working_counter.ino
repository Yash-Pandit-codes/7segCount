// Define the segment pins
const int segmentPins[] = {2, 3, 4, 5, 6, 7, 8};

// Define the button pins
const int buttonUp = 9;
const int buttonDown = 10;

// Segment patterns for digits 0-9
const byte digits[10] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01101111  // 9
};

int count = 0;

void setup() {
  // Set segment pins as outputs
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  
  // Set button pins as inputs
  pinMode(buttonUp, INPUT_PULLUP);
  pinMode(buttonDown, INPUT_PULLUP);
}

void loop() {
  // Check if the up button is pressed
  if (digitalRead(buttonUp) == LOW) {
    count++;
    if (count > 9) count = 0; // Reset to 0 if count exceeds 9
    delay(200); // Debounce delay
  }
  
  // Check if the down button is pressed
  if (digitalRead(buttonDown) == LOW) {
    count--;
    if (count < 0) count = 9; // Reset to 9 if count goes below 0
    delay(200); // Debounce delay
  }
  
  // Display the count on the 7-segment display
  displayDigit(count);
}

void displayDigit(int digit) {
  byte segments = digits[digit];
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], (segments >> i) & 0x01);
    delay(20);
  }
}

/*Circuit Diagram
7-Segment Display: Connect the segments (a to g) to Arduino digital pins 2 to 8. Connect the common cathode to GND through a 220 ohm resistor.
Push Buttons: Connect one side of each button to 5V and the other side to digital pins 9 and 10, respectively. Also, connect a 10k ohm resistor from each button pin to GND.
This code sets up a simple counter that increments or decrements the displayed number based on button presses. The displayDigit function lights up the appropriate segments to show the current count.*/
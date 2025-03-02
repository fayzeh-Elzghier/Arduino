const int potPin = A0;        // Potentiometer connected to analog pin A0
const int ledPins[] = {3, 4, 5, 6}; // LEDs connected to digital pins 3, 4, 5, and 6

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  int potValue = analogRead(potPin);
  
  // Determine the number of LEDs to turn on
  int numLEDs = 0;
  if (potValue < 256) {
    numLEDs = 1;
  } else if (potValue < 512) {
    numLEDs = 2;
  } else if (potValue < 768) {
    numLEDs = 3;
  } else {
    numLEDs = 4;
  }
  
  // Turn on the appropriate number of LEDs
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], i < numLEDs ? HIGH : LOW);
  }
  
  delay(100); // Small delay to avoid rapid changes
}

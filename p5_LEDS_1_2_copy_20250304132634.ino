const int rockLED = 3;
const int peaceLED = 4;
const int thumbsLED = 5;
const int surfLED = 6;
const int palmLED = 7;

char currentGesture = '0';  // Keeps track of the current gesture

void setup() {
  Serial.begin(9600);

  pinMode(rockLED, OUTPUT);
  pinMode(peaceLED, OUTPUT);
  pinMode(thumbsLED, OUTPUT);
  pinMode(surfLED, OUTPUT);
  pinMode(palmLED, OUTPUT);

  setAllLEDs(LOW);  // Start with all LEDs off
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    // Only update LEDs if the gesture has changed AND it's a valid gesture (1-5)
    if (command != currentGesture && (command >= '1' && command <= '5')) {
      currentGesture = command;
      updateLEDs(currentGesture);
    }
  }
}

void setAllLEDs(int state) {
  digitalWrite(rockLED, state);
  digitalWrite(peaceLED, state);
  digitalWrite(thumbsLED, state);
  digitalWrite(surfLED, state);
  digitalWrite(palmLED, state);
}

void updateLEDs(char gesture) {
  setAllLEDs(LOW);  // Turn all off first

  if (gesture == '1') {
    digitalWrite(rockLED, HIGH);
  } else if (gesture == '2') {
    digitalWrite(peaceLED, HIGH);
  } else if (gesture == '3') {
    digitalWrite(thumbsLED, HIGH);
  } else if (gesture == '4') {
    digitalWrite(surfLED, HIGH);
  } else if (gesture == '5') {
    digitalWrite(palmLED, HIGH);
  }
}

#include <Servo.h>

// Create Servo objects
Servo servo1;
Servo servo2;

// Define pin numbers
const int servo1Pin = 6;
const int servo2Pin = 8;

void setup() {
  // Attach each servo to its respective pin
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
}

void loop() {
  // Move both servos to 0 degrees
  servo1.write(0);
  servo2.write(0);
  delay(1000); // Wait for 1 second

  // Move both servos to 90 degrees
  servo1.write(90);
  servo2.write(90);
  delay(1000); // Wait for 1 second

  // Move both servos to 180 degrees
  servo1.write(180);
  servo2.write(180);
  delay(1000); // Wait for 1 second
}

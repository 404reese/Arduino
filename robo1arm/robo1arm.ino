#include <Servo.h>

// Define servo object
Servo baseServo;

// Pin assignment
const int basePin = 3;

// Initial position for the base
int basePosition = 100; // Starting position

void setup() {
  // Attach servo to the base pin
  baseServo.attach(basePin);

  // Move base to initial position
  baseServo.write(basePosition);
  delay(3000); // Wait for 1 second
}


void loop() {
  for (basePosition = 50; basePosition <= 100; basePosition++) {
    baseServo.write(basePosition);  // Move to the current position

    // If at 40°, wait for 5 seconds
    if (basePosition == 50) {
      delay(5000);
    } else {
      delay(15); // Delay to slow down the movement
    }
  }

  // Optionally, add code to move back to 40° if you want continuous motion
}

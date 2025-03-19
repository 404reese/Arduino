#include <Servo.h> // Include the Servo library

Servo myServo;  // Create Servo object
int minPosition = 0;  // Minimum servo position (0 degrees)
int maxPosition = 180; // Maximum servo position (180 degrees)

void setup() {
    Serial.begin(9600);
    myServo.attach(9); // Attach servo to pin D9

    // Move servo to home position at startup
    Serial.println("Homing servo to 0 degrees...");
    myServo.write(minPosition);
    delay(1000); // Allow time to reach position
    Serial.println("Servo is ready. Starting 360-degree rotation...");
}

void loop() {
    rotateMotor360ThreeTimes();  // Rotate the servo a total of 360 degrees, 3 times
    delay(5000); // Wait for 5 seconds before starting the next rotation cycle
}

void rotateMotor360ThreeTimes() {
    for (int i = 0; i < 3; i++) {  // Repeat 3 times
        Serial.print("Rotation cycle: ");
        Serial.println(i + 1);

        // Move servo from 0 degrees to 180 degrees (half rotation)
        myServo.write(minPosition);
        delay(1000); // Wait for servo to reach position

        myServo.write(maxPosition);
        delay(1000); // Wait for servo to reach position

        // Move servo back from 180 degrees to 0 degrees (second half rotation)
        myServo.write(minPosition);
        delay(1000); // Wait for servo to reach position

        Serial.println("Cycle complete!");
    }

    Serial.println("Completed 3 full 360-degree rotations.");
}

#include <Servo.h> // Include the Servo library

Servo myServo;  // Create Servo object
int homePosition = 90; // Define home position

void setup() {
    Serial.begin(9600);
    myServo.attach(9); // Attach servo to pin D9

    // Move servo to home position at startup
    Serial.println("Homing servo to 90 degrees...");
    myServo.write(homePosition);
    delay(1000); // Allow time to reach position
    Serial.println("Servo is ready. Enter an angle (0-180):");
}

void loop() {
    if (Serial.available()) { // Check if data is available
        int inputAngle = Serial.parseInt(); // Read integer from Serial Monitor
        
        if (inputAngle >= 0 && inputAngle <= 180) { // Validate range
            myServo.write(inputAngle);
            Serial.print("Servo moved to: ");
            Serial.print(inputAngle);
            Serial.println(" degrees");
        } else if (inputAngle == -1) { // Use -1 as a special command to return home
            Serial.println("Returning to home position...");
            myServo.write(homePosition);
            Serial.println("Servo moved to home (90 degrees)");
        } else {
            Serial.println("Invalid input! Enter a value between 0 and 180.");
        }
        
        // Clear Serial buffer
        while (Serial.available()) Serial.read();
    }
}


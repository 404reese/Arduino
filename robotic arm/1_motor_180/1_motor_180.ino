#include <Servo.h>

Servo myservo;  // Create a Servo object

void setup() {
  myservo.attach(6);  // Attach the servo to pin D6
}

void loop() {
  myservo.write(0);    // Rotate to 0 degrees
  delay(1000);         // Wait for 1 second
  myservo.write(90);   // Rotate to 90 degrees
  delay(1000);         // Wait for 1 second
  myservo.write(180);  // Rotate to 180 degrees
  delay(1000);         // Wait for 1 second
}

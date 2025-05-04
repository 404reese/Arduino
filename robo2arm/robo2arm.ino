#include <Servo.h>

//––– Servo objects and pins
Servo gripperServo;
Servo baseServo;

const int GRIPPER_PIN       = 3;
const int BASE_ROTATION_PIN = 5;

//––– “Closed” vs “Open” positions (tweak these to match your hardware)
const int GRIPPER_CLOSED_POS = 50;
const int GRIPPER_OPEN_POS   = 100;

const int BASE_HOME_POS      = 60;
const int BASE_TARGET_POS    = 120;

//––– Timing (all in milliseconds)
const int GRIPPER_MOVE_DELAY   = 15;    // step delay for smooth gripper
const int BASE_MOVE_DELAY      = 15;   // ~5s to move 30° (30°/5000ms≈6°/1000ms→166ms/step)
const int HOLD_TIME            = 3000;  // how long gripper holds object at closed pos
const int PAUSE_BETWEEN_PHASES = 300;   // small pause between phases

void setup() {
  gripperServo.attach(GRIPPER_PIN);
  baseServo.attach(BASE_ROTATION_PIN);

  // go to known start positions
  gripperServo.write(GRIPPER_OPEN_POS);
  baseServo.write(BASE_HOME_POS);
  delay(1000);
}

void loop() {
  // 1) Close gripper
  for (int p = GRIPPER_OPEN_POS; p >= GRIPPER_CLOSED_POS; p--) {
    gripperServo.write(p);
    delay(GRIPPER_MOVE_DELAY);
  }
  delay(HOLD_TIME);

  // 2) Rotate base forward (home → target)
  for (int a = BASE_HOME_POS; a <= BASE_TARGET_POS; a++) {
    baseServo.write(a);
    delay(BASE_MOVE_DELAY);
  }
  delay(PAUSE_BETWEEN_PHASES);

  // 3) Open gripper
  for (int p = GRIPPER_CLOSED_POS; p <= GRIPPER_OPEN_POS; p++) {
    gripperServo.write(p);
    delay(GRIPPER_MOVE_DELAY);
  }
  delay(PAUSE_BETWEEN_PHASES);

  // 4) Rotate base back slowly (target → home)
  for (int a = BASE_TARGET_POS; a >= BASE_HOME_POS; a--) {
    baseServo.write(a);
    delay(BASE_MOVE_DELAY);
  }
  delay(PAUSE_BETWEEN_PHASES);

  // And it loops again…
}
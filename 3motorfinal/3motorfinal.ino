#include <Servo.h>

//––– Servo objects and pins
Servo gripperServo;
Servo baseServo;
Servo shoulderServo;

const int GRIPPER_PIN   = 3;
const int BASE_PIN      = 5;
const int SHOULDER_PIN  = 6;

//––– Positions
const int GRIPPER_OPEN_POS    = 100;
const int GRIPPER_CLOSED_POS  = 50;

const int BASE_HOME_POS       = 30;
const int BASE_TARGET_POS     = 120;

const int SHOULDER_UP_POS     = 100;
const int SHOULDER_DOWN_POS   = 170;

//––– Timing (ms)
const int GRIPPER_STEP_DELAY   = 15;
const int BASE_STEP_DELAY      = 15;
const int SHOULDER_STEP_DELAY  = 15;
const int HOLD_TIME            = 3000;  // time holding object
const int PHASE_PAUSE          = 300;   // brief pause between steps

void setup() {
  gripperServo.attach(GRIPPER_PIN);
  baseServo.attach(BASE_PIN);
  shoulderServo.attach(SHOULDER_PIN);

  // Go to known start positions
  gripperServo.write(GRIPPER_OPEN_POS);
  baseServo.write(BASE_HOME_POS);
  shoulderServo.write(SHOULDER_UP_POS);
  delay(1000);
}

void loop() {
  // 1) Lower shoulder to pick
  for (int s = SHOULDER_UP_POS; s <= SHOULDER_DOWN_POS; s++) {
    shoulderServo.write(s);
    delay(SHOULDER_STEP_DELAY);
  }
  delay(PHASE_PAUSE);

  // 2) Close gripper (pick)
  for (int g = GRIPPER_OPEN_POS; g >= GRIPPER_CLOSED_POS; g--) {
    gripperServo.write(g);
    delay(GRIPPER_STEP_DELAY);
  }
  delay(HOLD_TIME);

  // 3) Lift shoulder up with object
  for (int s = SHOULDER_DOWN_POS; s >= SHOULDER_UP_POS; s--) {
    shoulderServo.write(s);
    delay(SHOULDER_STEP_DELAY);
  }
  delay(PHASE_PAUSE);

  // 4) Rotate base forward (home → target)
  for (int b = BASE_HOME_POS; b <= BASE_TARGET_POS; b++) {
    baseServo.write(b);
    delay(BASE_STEP_DELAY);
  }
  delay(PHASE_PAUSE);

  // 5) Lower shoulder to drop
  for (int s = SHOULDER_UP_POS; s <= SHOULDER_DOWN_POS; s++) {
    shoulderServo.write(s);
    delay(SHOULDER_STEP_DELAY);
  }
  delay(PHASE_PAUSE);

  // 6) Open gripper (drop)
  for (int g = GRIPPER_CLOSED_POS; g <= GRIPPER_OPEN_POS; g++) {
    gripperServo.write(g);
    delay(GRIPPER_STEP_DELAY);
  }
  delay(PHASE_PAUSE);

  // 7) Lift shoulder back up
  for (int s = SHOULDER_DOWN_POS; s >= SHOULDER_UP_POS; s--) {
    shoulderServo.write(s);
    delay(SHOULDER_STEP_DELAY);
  }
  delay(PHASE_PAUSE);

  // 8) Rotate base back (target → home)
  for (int b = BASE_TARGET_POS; b >= BASE_HOME_POS; b--) {
    baseServo.write(b);
    delay(BASE_STEP_DELAY);
  }
  delay(PHASE_PAUSE);

  // Loop again…
}
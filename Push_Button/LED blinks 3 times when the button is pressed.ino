// LED blinks 3 times when the button is pressed

#define BUTTON_PIN 7
#define LED_PIN 8

int blinkCount = 0;   // To count how many times the LED has blinked
bool buttonState = LOW;  // To track the previous state of the button
bool lastButtonState = LOW;  // To detect button press transitions

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);  // Read the current state of the button

  // Check if the button was just pressed (transition from LOW to HIGH)
  if (buttonState == HIGH && lastButtonState == LOW) {
    blinkCount = 0;  // Reset blink count each time the button is pressed
  }

  // If button is pressed, blink LED 3 times
  if (buttonState == HIGH && blinkCount < 3) {
    digitalWrite(LED_PIN, HIGH);  // Turn the LED on
    delay(200);                   // Keep LED on for 200 milliseconds
    digitalWrite(LED_PIN, LOW);   // Turn the LED off
    delay(200);                   // Keep LED off for 200 milliseconds
    blinkCount++;                 // Increase the blink count
  } else if (buttonState == LOW) {
    digitalWrite(LED_PIN, LOW);  // Keep LED off when button is not pressed
  }

  lastButtonState = buttonState;  // Save the current state of the button for next loop
}

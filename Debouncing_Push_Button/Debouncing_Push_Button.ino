#define BUTTON_PIN 7
#define LED_PIN 8

int buttonState = LOW;
int lastButtonState = LOW;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50; // 50ms debounce time

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);
  
  if (reading != lastButtonState) {
    lastDebounceTime = millis(); // Reset debounce timer
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      
      if (buttonState == LOW) { // Toggle LED when button is pressed
        digitalWrite(LED_PIN, !digitalRead(LED_PIN));
      }
    }
  }

  lastButtonState = reading;
}

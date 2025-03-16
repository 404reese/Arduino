#define LED_PIN 9  

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  for (int brightness = 0; brightness <= 255; brightness++) {  // Fade in
    analogWrite(LED_PIN, brightness);
    delay(10);
  }

  for (int brightness = 255; brightness >= 0; brightness--) {  // Fade out
    analogWrite(LED_PIN, brightness);
    delay(10);
  }
}

#define POT_PIN A0  // Potentiometer connected to A0
#define LED_PIN 9   // LED connected to PWM Pin 9

void setup() {
    pinMode(POT_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    int potValue = analogRead(POT_PIN);      // Read the potentiometer value (0-1023)
    int ledBrightness = map(potValue, 0, 1023, 0, 255);  // Scale it to PWM range (0-255)
    
    analogWrite(LED_PIN, ledBrightness);     // Control LED brightness
}

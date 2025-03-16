#define TRIG_PIN 9  // Trig pin on D9
#define ECHO_PIN 10 // Echo pin on D10

void setup() {
    Serial.begin(9600);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

void loop() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    
    digitalWrite(TRIG_PIN, HIGH);  // Send 10µs pulse
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    
    long duration = pulseIn(ECHO_PIN, HIGH, 30000); // 30ms timeout (max ~500cm)
    
    if (duration == 0) {
        Serial.println("Error: No echo received!");
    } else {
        float distance_cm = (duration * 0.0343) / 2; // Convert to cm

        if (distance_cm > 400) { // Ignore out-of-range values
            Serial.println("Out of range (>400 cm)");
        } else {
            Serial.print("Distance: ");
            Serial.print(distance_cm);
            Serial.println(" cm");
        }
    }

    delay(500); // 500ms delay
}

#define LM35_PIN A0  

float readTemperature() {
    int samples = 10;
    float sum = 0;

    for (int i = 0; i < samples; i++) {
        int sensorValue = analogRead(LM35_PIN);
        float voltage = sensorValue * (5.0 / 1023.0); // Convert ADC value to voltage
        sum += voltage * 100.0; // Convert voltage to temperature in Celsius
        delay(10); // Small delay to stabilize readings
    }
    return sum / samples; // Return the averaged temperature
}

void setup() {
    Serial.begin(9600);
}

void loop() {
    float temperatureC = readTemperature();
    float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0; // Convert to Fahrenheit

    Serial.print("Temperature: ");
    Serial.print(temperatureC, 2); // Print Celsius with 2 decimal places
    Serial.print(" °C  |  ");
    Serial.print(temperatureF, 2); // Print Fahrenheit with 2 decimal places
    Serial.println(" °F");

    delay(1000); // Read every second
}

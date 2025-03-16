#define SENSOR_PIN A0  

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(SENSOR_PIN);  // Read sensor value (0-1023)
  float voltage = sensorValue * (5.0 / 1023.0);  // Convert to voltage
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print("  Voltage: ");
  Serial.println(voltage, 2);  // Print with 2 decimal places
  delay(500);
}


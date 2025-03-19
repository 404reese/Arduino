#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>

Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);

// Set **actual altitude** of your location for calibration
#define KNOWN_ALTITUDE 14.0  // <-- Change this to your real altitude in meters

float seaLevelPressure_hPa; // Variable for calibrated pressure

void setup() {
    Serial.begin(9600);
    
    if (!bmp.begin()) {
        Serial.println("BMP180 not detected. Check wiring!");
        while (1);
    }

    // **Calibrate Sea-Level Pressure**
    sensors_event_t event;
    bmp.getEvent(&event);
    if (event.pressure) {
        seaLevelPressure_hPa = event.pressure / pow(1 - (KNOWN_ALTITUDE / 44330.0), 5.255);
        Serial.print("Calibrated Sea Level Pressure: ");
        Serial.print(seaLevelPressure_hPa);
        Serial.println(" hPa");
    }
}

void loop() {
    sensors_event_t event;
    bmp.getEvent(&event);

    if (event.pressure) {
        Serial.print("Pressure: ");
        Serial.print(event.pressure);
        Serial.println(" hPa");
    }

    float temperature;
    bmp.getTemperature(&temperature);
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    // **Use the Calibrated Sea-Level Pressure for Correct Altitude**
    Serial.print("Altitude = ");
    Serial.print(bmp.pressureToAltitude(seaLevelPressure_hPa, event.pressure));
    Serial.println(" meters");

    Serial.println();
    delay(1000);
}

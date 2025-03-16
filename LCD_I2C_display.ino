#include <Wire.h>  // I2C communication
#include <LiquidCrystal_I2C.h>  // I2C LCD library

#define I2C_ADDR 0x27  // Change to 0x3F if needed
LiquidCrystal_I2C lcd(I2C_ADDR, 16, 2); // 16x2 LCD

void setup() {
    Serial.begin(9600);
    lcd.begin(16, 2); // Corrected: Provide columns and rows
    lcd.backlight();  // Turn on backlight

    lcd.setCursor(0, 0);
    lcd.print("I2C LCD Ready!");
    delay(2000);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter text:");
    Serial.println("Type a message and press Enter:");
}

void loop() {
    if (Serial.available()) {
        String message = Serial.readStringUntil('\n');
        message.trim();

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Msg:");
        lcd.setCursor(0, 1);
        lcd.print(message);

        Serial.println("Message displayed on LCD!");
    }
}



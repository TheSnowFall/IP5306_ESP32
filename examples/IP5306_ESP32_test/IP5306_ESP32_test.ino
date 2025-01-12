#include <Wire.h>
#include "IP5306_ESP32.h"

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(115200);
  while (!Serial) {
    ; // Wait for Serial to connect
  }

  // Initialize I2C
  Wire.begin();

  // Check power source
  uint8_t powerSource = IP5306_GetPowerSource();
  Serial.print("Power Source: ");
  if (powerSource == 0) {
    Serial.println("Battery");
  } else {
    Serial.println("VIN");
  }

  // Check if the battery is full
  uint8_t batteryFull = IP5306_GetBatteryFull();
  Serial.print("Battery Status: ");
  if (batteryFull == 1) {
    Serial.println("Full");
  } else {
    Serial.println("Charging/Discharging");
  }

  // Read battery level LEDs
  uint8_t batteryLevel = IP5306_GetLevelLeds();
  uint8_t batteryPct = IP5306_LEDS2PCT(batteryLevel);
  Serial.print("Battery Level: ");
  Serial.print(batteryPct);
  Serial.println("%");
}

void loop() {
  // Optionally poll the power source and battery status periodically
  delay(5000);

  uint8_t powerSource = IP5306_GetPowerSource();
  Serial.print("Power Source: ");
  Serial.println(powerSource == 0 ? "Battery" : "VIN");

  uint8_t batteryFull = IP5306_GetBatteryFull();
  Serial.print("Battery Status: ");
  Serial.println(batteryFull == 1 ? "Full" : "Charging/Discharging");

  uint8_t batteryLevel = IP5306_GetLevelLeds();
  uint8_t batteryPct = IP5306_LEDS2PCT(batteryLevel);
  Serial.print("Battery Level: ");
  Serial.print(batteryPct);
  Serial.println("%");
}

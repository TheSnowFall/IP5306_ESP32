# IP5306_ESP32 Library

The **IP5306_ESP32** library is designed to interact with the IP5306 power management IC using I2C. This library is inferred or inspired from the original [IP5306 Arduino Library](https://github.com/Al1c3-1337/IP5306-arduino/tree/master), with some minor changes.

## Features

- Interact with the IP5306 power management IC via I2C.
- Query and configure system and charging registers.

## Changes Made

- Adjusted the library on compatibility with ESP32.
- Uploaded a working example sketch to demonstrate API usage.

## Tested Hardware

These APIs have been tested on the **[TTGO T-Call SIM800L](https://lilygo.cc/products/t-call-v1-4?variant=43766872965301)** version only.

## Known Issue with TTGO T-Call

The **TTGO T-Call** has a major design flaw: the **KEY** pin is connected to the **RESET** pin. This causes the following issue:

- If the TTGO is running on battery power and the battery fully discharges or is removed while the device is running, the **RESET** button must be pressed to restart the board.

Below is a schematic illustrating this issue:

![TTGO T-Call Reset Issue](./documental_assets/TTGO_Ip5306_reset.PNG)

## Installation

1. Clone or download the repository.
2. Place the `IP5306_ESP32` folder in your Arduino `libraries` folder.
3. Restart the Arduino IDE to ensure the library is recognized.

## API Reference

### Include the Library

Include the library and initialize I2C before using the APIs:

```cpp
#include <Wire.h>
#include "IP5306_ESP32.h"

void setup() {
    Wire.begin();
}
```

### API Functions

Below are all the available API functions in the `IP5306_ESP32.h` file with their usage and expected output.

#### **System Configuration**

##### `uint8_t IP5306_GetKeyOffEnabled()`

Gets the state of the KEY pin functionality.

- **Returns**: `0` (disabled), `1` (enabled)

**Usage:**

```cpp
uint8_t keyOff = IP5306_GetKeyOffEnabled();
Serial.println(keyOff ? "Key Off Enabled" : "Key Off Disabled");
```

##### `void IP5306_SetKeyOffEnabled(bool enable)`

Enables or disables the KEY pin functionality.

- **Parameters**: `true` (enable), `false` (disable)

**Usage:**

```cpp
IP5306_SetKeyOffEnabled(true);
Serial.println("Key Off Enabled");
```

##### `uint8_t IP5306_GetBoostOutputEnabled()`

Checks if boost output is enabled.

- **Returns**: `0` (disabled), `1` (enabled)

**Usage:**

```cpp
uint8_t boostOutput = IP5306_GetBoostOutputEnabled();
Serial.println(boostOutput ? "Boost Output Enabled" : "Boost Output Disabled");
```

##### `void IP5306_SetBoostOutputEnabled(bool enable)`

Enables or disables boost output.

- **Parameters**: `true` (enable), `false` (disable)

**Usage:**

```cpp
IP5306_SetBoostOutputEnabled(true);
Serial.println("Boost Output Enabled");
```

##### `uint8_t IP5306_GetPowerOnLoadEnabled()`

Checks if the power-on load feature is enabled.

- **Returns**: `0` (disabled), `1` (enabled)

**Usage:**

```cpp
uint8_t powerOnLoad = IP5306_GetPowerOnLoadEnabled();
Serial.println(powerOnLoad ? "Power On Load Enabled" : "Power On Load Disabled");
```

##### `void IP5306_SetPowerOnLoadEnabled(bool enable)`

Enables or disables the power-on load feature.

- **Parameters**: `true` (enable), `false` (disable)

**Usage:**

```cpp
IP5306_SetPowerOnLoadEnabled(true);
Serial.println("Power On Load Enabled");
```

#### **Charging Configuration**

##### `uint8_t IP5306_GetChargerEnabled()`

Checks if the charger is enabled.

- **Returns**: `0` (disabled), `1` (enabled)

**Usage:**

```cpp
uint8_t charger = IP5306_GetChargerEnabled();
Serial.println(charger ? "Charger Enabled" : "Charger Disabled");
```

##### `void IP5306_SetChargerEnabled(bool enable)`

Enables or disables the charger.

- **Parameters**: `true` (enable), `false` (disable)

**Usage:**

```cpp
IP5306_SetChargerEnabled(true);
Serial.println("Charger Enabled");
```

#### **Event Detection**

##### `uint8_t IP5306_GetShortPressDetected()`

Checks if a short press event was detected.

- **Returns**: `0` (not detected), `1` (detected)

**Usage:**

```cpp
if (IP5306_GetShortPressDetected()) {
    Serial.println("Short Press Detected");
    IP5306_ClearShortPressDetected();
}
```

##### `void IP5306_ClearShortPressDetected()`

Clears the short press detected flag.

**Usage:**

```cpp
IP5306_ClearShortPressDetected();
Serial.println("Short Press Cleared");
```

##### `uint8_t IP5306_GetLongPressDetected()`

Checks if a long press event was detected.

- **Returns**: `0` (not detected), `1` (detected)

**Usage:**

```cpp
if (IP5306_GetLongPressDetected()) {
    Serial.println("Long Press Detected");
    IP5306_ClearLongPressDetected();
}
```

##### `void IP5306_ClearLongPressDetected()`

Clears the long press detected flag.

**Usage:**

```cpp
IP5306_ClearLongPressDetected();
Serial.println("Long Press Cleared");
```

##### `uint8_t IP5306_GetDoubleClickDetected()`

Checks if a double click event was detected.

- **Returns**: `0` (not detected), `1` (detected)

**Usage:**

```cpp
if (IP5306_GetDoubleClickDetected()) {
    Serial.println("Double Click Detected");
    IP5306_ClearDoubleClickDetected();
}
```

##### `void IP5306_ClearDoubleClickDetected()`

Clears the double click detected flag.

**Usage:**

```cpp
IP5306_ClearDoubleClickDetected();
Serial.println("Double Click Cleared");
```

#### **Battery and Power Status**

##### `uint8_t IP5306_GetPowerSource()`

Checks the current power source.

- **Returns**: `0` (Battery), `1` (VIN)

**Usage:**

```cpp
uint8_t powerSource = IP5306_GetPowerSource();
Serial.println(powerSource ? "VIN" : "BATTERY");
```

##### `uint8_t IP5306_GetBatteryFull()`

Checks if the battery is fully charged.

- **Returns**: `0` (not full), `1` (full)

**Usage:**

```cpp
uint8_t isBatteryFull = IP5306_GetBatteryFull();
Serial.println(isBatteryFull ? "Battery Full" : "Battery Not Full");
```

##### `uint8_t IP5306_GetOutputLoad()`

Checks the output load state.

- **Returns**: `0` (heavy load), `1` (light load)

**Usage:**

```cpp
uint8_t outputLoad = IP5306_GetOutputLoad();
Serial.println(outputLoad ? "Light Load" : "Heavy Load");
```

#### `uint8_t IP5306_GetBatteryLevel()`

Gets the battery level percentage.

- **Returns**: Battery level as a percentage (0-100).

**Usage:**

```cpp
uint8_t batteryLevel = IP5306_GetBatteryLevel();
Serial.print("Battery Level: ");
Serial.print(batteryLevel);
Serial.println("%");
```

#### `void IP5306_SetChargingCurrent(uint8_t current)`

Sets the charging current for the IP5306.

- **Parameters**:
  - `current`: Charging current value (refer to the datasheet for valid values).

**Usage:**

```cpp
IP5306_SetChargingCurrent(3); // Set to a predefined current level
Serial.println("Charging current set");
```

#### `uint8_t IP5306_GetChargeState()`

Gets the current charging state.

- **Returns**:
  - `0`: Not charging
  - `1`: Charging

**Usage:**

```cpp
uint8_t chargeState = IP5306_GetChargeState();
Serial.print("Charging State: ");
Serial.println(chargeState ? "Charging" : "Not Charging");
```

## Special Features related to Charging/Discharging

## Charging Full Stop Voltage

### `uint8_t IP5306_GetChargingFullStopVoltage()`
Checks the configured charging full-stop voltage.

- **Returns**:
  - `0`: 4.14V
  - `1`: 4.17V (recommended)
  - `2`: 4.185V
  - `3`: 4.2V

**Usage:**
```cpp
uint8_t stopVoltage = IP5306_GetChargingFullStopVoltage();
Serial.print("Charging Full Stop Voltage: ");
Serial.println(stopVoltage == 0 ? "4.14V" : stopVoltage == 1 ? "4.17V" : stopVoltage == 2 ? "4.185V" : "4.2V");
```

### `void IP5306_SetChargingFullStopVoltage(uint8_t value)`
Configures the charging full-stop voltage.

- **Parameters**:
  - `value`:
    - `0`: 4.14V
    - `1`: 4.17V (recommended)
    - `2`: 4.185V
    - `3`: 4.2V


**Usage:**
```cpp
IP5306_SetChargingFullStopVoltage(1);
Serial.println("Charging Full Stop Voltage set to 4.17V");
```

---

## Charge Under-Voltage Loop

### `uint8_t IP5306_GetChargeUnderVoltageLoop()`
Gets the current under-voltage loop setting for charging.

- **Returns**: 
  - Corresponds to `VOUT = 4.45V + (value * 0.05V)`

**Usage:**
```cpp
uint8_t underVoltage = IP5306_GetChargeUnderVoltageLoop();
Serial.print("Charge Under-Voltage Loop: VOUT = ");
Serial.println(4.45 + underVoltage * 0.05, 2);
```

### `void IP5306_SetChargeUnderVoltageLoop(uint8_t value)`
Sets the under-voltage loop for charging.

- **Parameters**:
  - `value`: Corresponds to `VOUT = 4.45V + (value * 0.05V)`

**Recommended Value**: 2 (4.55V)

**Usage:**
```cpp
IP5306_SetChargeUnderVoltageLoop(2);
Serial.println("Charge Under-Voltage Loop set to 4.55V");
```

---

## End Charge Current Detection

### `uint8_t IP5306_GetEndChargeCurrentDetection()`
Gets the configured end charge current detection threshold.

- **Returns**: 
  - `0`: 200mA
  - `1`: 400mA
  - `2`: 500mA (default)
  - `3`: 600mA

**Usage:**
```cpp
uint8_t endChargeCurrent = IP5306_GetEndChargeCurrentDetection();
Serial.print("End Charge Current Detection: ");
Serial.println(endChargeCurrent == 0 ? "200mA" : endChargeCurrent == 1 ? "400mA" : endChargeCurrent == 2 ? "500mA" : "600mA");
```

### `void IP5306_SetEndChargeCurrentDetection(uint8_t value)`
Sets the end charge current detection threshold.

- **Parameters**:
  - `value`:
    - `0`: 200mA
    - `1`: 400mA
    - `2`: 500mA (recommended)
    - `3`: 600mA


**Usage:**
```cpp
IP5306_SetEndChargeCurrentDetection(2);
Serial.println("End Charge Current Detection set to 500mA");
```

---

## Voltage Pressure

### `uint8_t IP5306_GetVoltagePressure()`
Gets the current voltage pressure adjustment.

- **Returns**:
  - `0`: None
  - `1`: +14mV
  - `2`: +28mV (recommended)
  - `3`: +42mV

**Usage:**
```cpp
uint8_t pressure = IP5306_GetVoltagePressure();
Serial.print("Voltage Pressure: +");
Serial.println(pressure == 0 ? "0mV" : pressure == 1 ? "14mV" : pressure == 2 ? "28mV" : "42mV");
```

### `void IP5306_SetVoltagePressure(uint8_t value)`
Sets the voltage pressure adjustment.

- **Parameters**: 
  - `value`:
    - `0`: None
    - `1`: +14mV
    - `2`: +28mV (recommended)
    - `3`: +42mV


**Usage:**
```cpp
IP5306_SetVoltagePressure(2);
Serial.println("Voltage Pressure set to +28mV");
```

---

## Charge Cutoff Voltage

### `uint8_t IP5306_GetChargeCutoffVoltage()`
Gets the configured charge cutoff voltage.

- **Returns**:
  - `0`: 4.2V
  - `1`: 4.3V
  - `2`: 4.35V
  - `3`: 4.4V

**Usage:**
```cpp
uint8_t cutoffVoltage = IP5306_GetChargeCutoffVoltage();
Serial.print("Charge Cutoff Voltage: ");
Serial.println(cutoffVoltage == 0 ? "4.2V" : cutoffVoltage == 1 ? "4.3V" : cutoffVoltage == 2 ? "4.35V" : "4.4V");
```

### `void IP5306_SetChargeCutoffVoltage(uint8_t value)`
Sets the charge cutoff voltage.

- **Parameters**: 
  - `value`:
    - `0`: 4.2V (recommended)
    - `1`: 4.3V
    - `2`: 4.35V
    - `3`: 4.4V

**Usage:**
```cpp
IP5306_SetChargeCutoffVoltage(0);
Serial.println("Charge Cutoff Voltage set to 4.2V");
```

---

## VIN Input Current

### `uint8_t IP5306_GetVinCurrent()`
Gets the configured input current from VIN.

- **Returns**:
  - Current in mA: `50 + (value * 100)`

**Usage:**
```cpp
uint8_t vinCurrent = IP5306_GetVinCurrent();
Serial.print("VIN Current: ");
Serial.print(50 + vinCurrent * 100);
Serial.println("mA");
```

### `void IP5306_SetVinCurrent(uint8_t value)`
Sets the input current from VIN.

- **Parameters**: 
  - `value`: Corresponds to `Current (mA) = 50 + (value * 100)`

**Recommended Value**: 2250mA

**Usage:**
```cpp
IP5306_SetVinCurrent(22);
Serial.println("VIN Current set to 2250mA");
```


## Contributing

Feel free to submit issues and pull requests to improve the library.

---

**Note:** Refer to the [IP5306 Application Note](./documental_assets/datasheet/IP5306_Application_Note.pdf) and the [IP5306 Datasheet](./documental_assets/datasheet/IP5306_datasheet.pdf) for more information about the registers and their configurations.

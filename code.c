/**
 * @file home_automation.ino
 * @brief Smart Home Automation System Firmware
 * * Re-engineered firmware for Arduino Nano. Handles 4-channel relay switching 
 * via Bluetooth serial communication and automated safety sensor monitoring.
 */

#include <SoftwareSerial.h>

// --- Pin Configurations ---
#define BLUETOOTH_RX      2
#define BLUETOOTH_TX      3

#define RELAY_LIGHT       4
#define RELAY_FAN         5
#define RELAY_WATER_TANK  6
#define RELAY_GARDEN_PUMP 7

#define BUZZER            8

#define SENSOR_SMOKE       A0
#define SENSOR_MOISTURE    A1
#define SENSOR_WATER_LEVEL A2

// --- System Thresholds ---
#define SMOKE_THRESHOLD   400  // ADC value threshold for safety trigger

// Initialize Software Serial for Bluetooth communication
SoftwareSerial bluetooth(BLUETOOTH_RX, BLUETOOTH_TX);

/**
 * @brief Initializes microcontroller pins and serial communication interfaces.
 */
void setup() {
    // Initialize hardware serial for debugging and software serial for Bluetooth
    Serial.begin(9600);
    bluetooth.begin(9600);
    
    // Configure output control pins
    pinMode(RELAY_LIGHT, OUTPUT);
    pinMode(RELAY_FAN, OUTPUT);
    pinMode(RELAY_WATER_TANK, OUTPUT);
    pinMode(RELAY_GARDEN_PUMP, OUTPUT);
    pinMode(BUZZER, OUTPUT);
    
    // Most multi-channel relay boards are Active-LOW (HIGH = OFF, LOW = ON)
    // Initialize all appliances to safe OFF state
    digitalWrite(RELAY_LIGHT, HIGH);
    digitalWrite(RELAY_FAN, HIGH);
    digitalWrite(RELAY_WATER_TANK, HIGH);
    digitalWrite(RELAY_GARDEN_PUMP, HIGH);
    
    // Ensure safety alarm is inactive initially
    digitalWrite(BUZZER, LOW);
}

/**
 * @brief Main execution loop. Handles incoming commands and sensor processing.
 */
void loop() {
    // 1. Process Incoming Remote Commands from the Mobile App
    if (bluetooth.available() > 0) {
        char remoteCommand = (char)bluetooth.read();
        
        // Debug output to hardware serial monitor
        Serial.print("Executing Command: ");
        Serial.println(remoteCommand);
        
        switch (remoteCommand) {
            case 'A': 
                digitalWrite(RELAY_LIGHT, LOW);   // Turn Light ON
                break;
            case 'a': 
                digitalWrite(RELAY_LIGHT, HIGH);  // Turn Light OFF
                break;
                
            case 'B': 
                digitalWrite(RELAY_FAN, LOW);     // Turn Fan ON
                break;
            case 'b': 
                digitalWrite(RELAY_FAN, HIGH);    // Turn Fan OFF
                break;
                
            case 'C': 
                digitalWrite(RELAY_GARDEN_PUMP, LOW);  // Turn Garden Pump ON
                break;
            case 'c': 
                digitalWrite(RELAY_GARDEN_PUMP, HIGH); // Turn Garden Pump OFF
                break;
                
            case 'D': 
                digitalWrite(RELAY_WATER_TANK, LOW);   // Turn Water Tank Motor ON
                break;
            case 'd': 
                digitalWrite(RELAY_WATER_TANK, HIGH);  // Turn Water Tank Motor OFF
                break;
                
            default:
                // Ignore unexpected data frames
                break;
        }
    }

    // 2. Read Ambient Environmental Values
    int smokeSignal       = analogRead(SENSOR_SMOKE);
    int moistureSignal    = analogRead(SENSOR_MOISTURE);
    int waterLevelSignal  = analogRead(SENSOR_WATER_LEVEL);
    
    // 3. Safety Interlock Evaluation
    // If the smoke sensor crosses the safety baseline, trigger the audio alarm
    if (smokeSignal > SMOKE_THRESHOLD) {
        digitalWrite(BUZZER, HIGH); 
    } else {
        digitalWrite(BUZZER, LOW);
    }
    
    // Brief processing pause to stabilize the MCU Analog-to-Digital Converter (ADC)
    delay(50);
}
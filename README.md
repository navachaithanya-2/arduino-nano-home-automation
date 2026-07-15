# arduino-nano-home-automation
A Bluetooth-controlled Smart Home Automation system built with Arduino Nano. Features automated safety monitoring using smoke, moisture, and water level sensors alongside manual appliance controls via a mobile application.

A legacy Bluetooth-controlled Home Automation and environment monitoring system built using an Arduino Nano. This project allows a user to control high-voltage home appliances via a custom mobile application while using sensors to safely automate water management and fire alerts.

## 📺 Project Resources
* **Demonstration Video:** [Watch the Project Presentation Video on YouTube](https://youtu.be/YmVLzEqBRTQ?si=91fRT49kHC_4mduk)

## 🛠️ System Architecture
Based on the project design, the system is divided into Inputs, Processing, and Outputs:

### 📥 Inputs
* **Bluetooth Module (HC-05/HC-06):** Receives control commands from the mobile application.
* **Moisture Sensor:** Monitors soil moisture for garden automation.
* **Water Level Sensor:** Tracks overhead water tank capacity.
* **Smoke Sensor (MQ Series):** Detects smoke/gas leaks for home safety.

### 🧠 Processing
* **Arduino Nano:** The core microcontroller processing sensor data and execution switches.

### 📤 Outputs
* **Buzzer:** Auditory alarm triggered by critical sensor events (e.g., smoke detection).
* **4-Channel Relay Module:** Acts as an electronic switch to safely isolate and control high-voltage appliances:
  * Light 💡
  * Fan 🌀
  * Water Tank Motor 🚰
  * Garden Pump Motor 🪴

---

## 📱 Mobile Application Layout
The project utilizes a dedicated Android smartphone app with the following control interface layout:
* **Connection Status:** Displays real-time Bluetooth connection state (`Connected` / `Disconnected`).
* **Appliance Toggles:** Individual `ON` and `OFF` button pairs for the Light, Fan, Garden Motor, and Water Tank.

---

## 🔧 Future Improvements
* Migration from Bluetooth to Wi-Fi (ESP8266/ESP32) for cloud-based IoT access.
* Integration of an I2C LCD Display for physical status readouts inside the home.

🎓 Acknowledgments

  Special thanks to Saraswathi Vidhyalayam educational institution for facilitating the platform and context under which the baseline prototype of this automation ecosystem was originally conceptualized and presented.

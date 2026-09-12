# Industrial-Automation-in-IOT

An IoT-based industrial automation system built with a NodeMCU/ESP32 microcontroller
integrated with the Blynk IoT application, enabling remote monitoring and control of
industrial appliances such as fans, motors, lights, and other electrical devices from
a smartphone or web interface.

## Overview

The system connects to the internet via Wi-Fi and communicates with the Blynk cloud
server for real-time feedback, status updates, and alerts. Relay modules interface
high-power industrial loads safely, protecting both the control system and connected
equipment. The design supports scalability for adding more devices, and manual
control via push buttons remains available even without internet access.

## Features

- Remote monitoring and control through the Blynk IoT platform
- Wireless control using Wi-Fi
- Control of fans, motors, LEDs, and AC loads
- Manual control using push buttons
- Real-time device status monitoring
- Scalable architecture for adding additional devices
  
## Hardware Used
- NodeMCU (ESP8266) / ESP32 microcontroller
- L298N motor driver module
- Relay modules
- Push button (manual control)
- Fan, LED, AC device (controlled outputs)

## Software Used
- Arduino IDE (Embedded C/C++)
- Blynk IoT platform / mobile app
- Wi-Fi communication

## Technologies Used
- Embedded C/C++
- IoT
- Wi-Fi Communication
- Blynk IoT
- Arduino IDE
- NodeMCU / ESP32
  
## System Architecture
Three layers:
1. **User interface layer** — Blynk mobile app for sending commands and monitoring status
2. **Cloud layer** — receives commands from the app, relays them to the NodeMCU, and syncs device status
3. **Hardware layer** — NodeMCU + relays/motor driver/output devices, processes commands and controls outputs

## Setup
1. Install the Arduino IDE and add ESP8266/ESP32 board support.
2. Install the Blynk library.
3. Create a `secrets.h` file (gitignored) with your Wi-Fi SSID/password and Blynk auth token.
4. Upload the sketch in `/src` to your NodeMCU/ESP32.
5. Open the Blynk app, add your devices, and control them from your phone or the push button.

## Team
- Vigneshwar Reddy
- parvathala Pathanjali
- Mohammad Shahnawaz
- Konamgeri Nikitha

Guided by Dr. B. Prasad, Associate Professor, Dept. of CSE, CMR Engineering College.

## Future Scope
Integration of temperature/humidity/gas sensors for environmental monitoring, data
logging and analytics, and AI-based predictive maintenance.

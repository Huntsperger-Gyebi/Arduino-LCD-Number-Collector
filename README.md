Arduino LCD Number Collector
An interactive mini-game built for the Arduino Uno, featuring a 16x2 I2C LCD screen and an analog joystick. 
The objective is to navigate your character across the screen to collect random values until the sum reaches 9.

🚀 Project Overview
This project focuses on embedded systems programming and hardware-software integration. It demonstrates how to handle analog
input (ADC) from a joystick to control coordinate-based movement on an I2C-enabled display, while managing game state logic
and collision detection in C++.

🛠 Hardware Requirements
Microcontroller: Arduino Uno
Display: 16x2 I2C LCD Module
Input: Analog XY Joystick Module
Connectivity: Breadboard and Jumper Wires

⚡ FeaturesReal-time Navigation: 
Responsive character movement using joystick axis thresholding to prevent input drift.
Dynamic Objective System: Random number generation for targets, requiring the player to navigate coordinates to collect
values.
State Management: Tracks player score across the grid and triggers a "WIN" sequence upon reaching the goal.
Optimized Rendering: Refresh logic that balances responsiveness with LCD performance to prevent screen flickering.

🔧 Wiring Guide
Joystick/LCD Pin----------Arduino Pin
Joystick VRx--------------A0
Joystick VRy--------------A1
LCD SDA-------------------A4
LCD SCL-------------------A5
VCC/GND-------------------5V/GND

💻 Technical Implementation
Language: Embedded C++
Library: LiquidCrystal_I2C
Core Logic:
1.analogRead() for joystick input polling.
2.Threshold-based movement to create dead-zones.
3.Collision detection via coordinate mapping (playerX == targetX && playerY == targetY)

📈 Future Improvements
1.Add a "High Score" feature using EEPROM to store progress across power cycles.
2.Introduce timed levels to increase difficulty.
3.Integrate a buzzer for sound effects upon collection and winning.

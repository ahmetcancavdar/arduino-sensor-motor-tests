# arduino-sensor-motor-tests
A collection of basic Arduino test scripts for motor control, motion sensing, and GPS tracking.
# Arduino Sensor and Motor Control Modules 🚀

This repository contains independent test and usage codes for three fundamental hardware components frequently used in Arduino-based robotics and autonomous system projects. The codes are written in a minimal and easy-to-understand way to help you grasp the concepts of movement, balance/orientation, and location tracking.

## 🛠️ Hardware Used and Features

1. **L298N Motor Driver**
   * Provides DC motor control using simple characters (`w`: forward, `s`: backward, `x`: stop) sent via the Serial Monitor.
   * Allows speed control (between 0-255) using PWM.

2. **MPU6050 IMU (Accelerometer and Gyroscope)**
   * Communicates with the sensor using the I2C protocol.
   * Prints real-time acceleration (g) and angular velocity (dps) data on the X, Y, and Z axes to the Serial Monitor.
   * Reads data from the built-in temperature sensor (Temp) on the module.

3. **NEO-6M GPS Module**
   * Parses NMEA data received from satellites using the `TinyGPS++` and `SoftwareSerial` libraries.
   * Once the device gets a satellite fix, it outputs real-time **Latitude** and **Longitude** data in a comma-separated format.

## 📂 Folder Structure

When you clone the project, you will find 3 different Arduino `.ino` files. You can test each hardware component individually using these scripts before integrating them into your main project.

## 🚀 How to Use

1. Open the code for the hardware you want to test in the Arduino IDE.
2. Make the necessary wiring connections (pin numbers are specified at the top of each code).
3. Upload the code to your Arduino.
4. Open `Tools > Serial Monitor` (paying attention to the Baud Rate: 9600 for the Motor and GPS, 115200 for the IMU) and observe the data.

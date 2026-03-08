# arduino-sensor-motor-tests
A collection of basic Arduino test scripts for motor control, motion sensing, and GPS tracking.
# Arduino Sensor & Motor Test Scripts 🚀

This repository contains basic, standalone Arduino test codes for essential hardware components used in robotics and autonomous projects. These scripts are designed to be minimal and easy to understand, making them perfect for testing individual sensors and actuators before integrating them into a larger system.

## 🛠️ Included Tests

1. **Motor Control Script**
   * A simple serial-controlled script to test DC motor drivers.
   * Send basic characters via Serial Monitor (`w` for forward, `s` for backward, `x` for stop) to control movement.
   * Includes basic PWM speed control mapping.

2. **IMU (Inertial Measurement Unit) Sensor Script**
   * Reads raw data from a 6-axis motion sensor via I2C.
   * Outputs X, Y, Z acceleration (in g) and gyroscope (in dps) values to the Serial Monitor.
   * Useful for balancing robots or orientation tracking.

3. **GPS Module Script**
   * Parses NMEA sentences from a standard GPS receiver using software serial.
   * Outputs clean Latitude and Longitude coordinates once a satellite fix is acquired.

## 📂 How to Use

1. Clone or download this repository.
2. Open the specific `.ino` file for the hardware you want to test.
3. Wire your components according to the pin definitions at the top of each script.
4. Upload the code to your Arduino board.
5. Open the **Serial Monitor** (make sure to match the baud rate specified in the `setup()` function of each code) to interact with the motors or view sensor data.

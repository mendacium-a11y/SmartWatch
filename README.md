# Smart Watch Project using ESP32

Welcome to the **Smart Watch Project** repository! This project brings together a wearable prototype using the ESP32, multiple health and motion sensors, and a custom-designed PCB to build a basic, functional smartwatch. This project showcases the integration of IoT and sensor technologies in a compact wearable form factor, all running on open-source hardware and software.

## Project Overview

This smartwatch project leverages the **ESP32 microcontroller** for its versatility and built-in Wi-Fi and Bluetooth capabilities. The smartwatch monitors and displays essential health metrics like heart rate, temperature, and activity levels. With real-time data processing, this smartwatch can be used for health monitoring and fitness tracking. Key sensors include:

- **MAX30100** for heart rate and blood oxygen (SpO2) monitoring
- **MPU6050** for motion tracking and step counting
- **LM35** for temperature measurement

The repository contains all the necessary files to replicate this project, including firmware code, PCB design files, and images.

## Features

- **Heart Rate and SpO2 Monitoring**: Uses the MAX30100 sensor to track heart rate and blood oxygen levels.
- **Step Counting and Motion Detection**: The MPU6050 accelerometer and gyroscope enable activity tracking, including step counting and basic movement analysis.
- **Temperature Monitoring**: With the LM35 sensor, the smartwatch measures ambient temperature for added health insights.
- **Bluetooth Connectivity**: Powered by the ESP32, allowing data to be shared with mobile devices.
- **Custom PCB Design**: All components are integrated on a custom PCB design, making it compact and wearable.

## Components Used

1. **ESP32**: Microcontroller with Wi-Fi and Bluetooth capabilities.
2. **MAX30100**: Heart rate and SpO2 sensor.
3. **MPU6050**: 6-axis gyroscope and accelerometer for motion tracking.
4. **LM35**: Analog temperature sensor.
5. **Battery and Power Management Circuitry**: Ensures the device is powered efficiently, suitable for wearable applications.

## Repository Contents

- **Firmware Code**: The main code files that control the smartwatch, allowing it to read sensor data, process it, and output relevant metrics.
- **PCB Gerber Files**: Files needed to fabricate the custom PCB for this smartwatch.
- **PCB Images**:  Visual representations of the [PCB Layout](/pics/PCB.png),  and [design](/pics/Layout.png) for easy reference.
## Getting Started

To recreate or modify this project, follow these steps:

1. **Hardware Assembly**:
   - Fabricate the PCB using the provided Gerber files.
   - Solder the ESP32, MAX30100, MPU6050, LM35, and other components onto the PCB as per the layout.
   - Connect a battery and ensure proper power management.

2. **Firmware Setup**:
   - Flash the ESP32 with the firmware available in the directory [(code)](/watch.ino) 
   - Ensure you have the required libraries for ESP32, MAX30100, MPU6050, and LM35 installed in your Arduino IDE or PlatformIO environment.

3. **Connect and Test**:
   - Power on the smartwatch and verify that sensor readings display correctly.
   - Test Bluetooth connectivity for data transmission.
   - Make any necessary adjustments or calibrations to the sensors if needed.

## Usage

1. **Power On**: Power the smartwatch using the onboard battery or a USB connection to the ESP32.
2. **Data Viewing**: Monitor your health metrics directly on the smartwatch display or over Bluetooth.
3. **Calibration**: Adjust settings in the code to calibrate for specific motion sensitivity or environmental conditions if needed.

## Future Improvements

This smartwatch can be expanded with more advanced features, such as:

- **GPS Module**: For location tracking and geolocation-based activity monitoring.
- **Advanced Health Metrics**: Further processing of sensor data to estimate additional health parameters.
- **Battery Optimization**: Longer battery life with sleep modes and optimized power consumption.

## License

This project is open-source and available under the MIT License.

## Contributing

Contributions are welcome! Please feel free to submit issues, request features, or contribute to the project. Together, we can expand the functionality and impact of this smartwatch.

---

This project demonstrates a compact, functional smartwatch with real-world health applications and data connectivity. Have fun building, customizing, and using your own IoT-enabled smartwatch!
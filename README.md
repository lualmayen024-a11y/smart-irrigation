01.EKALALE LOKAALE BSCCS/2025/30137
02.SUMAYA BIGENIMANA BSCCS/2025/32262
03.THIJIEN CHIKOT BSCCS/2025/30142
04.DENG MAKUCH BSCCS/2025/69596
05.SAVAN JOSEPH BSCCS/2025/30679
06.MAYEN LUAL BSCCS/2025/67976
07.PATRICK MUGABO NZABAKIZA BSCCS/2025/31135
08.PIOL DENG BSCCS/2025/69731

Smart Irrigation System – Technical Report

Executive Summary
This project presents the design and simulation of a Smart Irrigation System using Tinkercad and Arduino Uno. The system uses a soil moisture sensor to automatically control water flow, optimizing water usage and promoting sustainable farming through IoT technology.

1. Introduction
The Smart Irrigation System automates watering based on real-time soil moisture readings, eliminating guesswork and conserving water.

Objectives

Automate irrigation using soil moisture levels

Conserve water through precision control

Build an affordable, scalable IoT prototype


2. System Design
The system operates as a closed loop where the soil moisture sensor sends data to the Arduino Uno, which controls a 5V DC pump.

Main components include:

Arduino Uno as the microcontroller

Analog capacitive soil moisture sensor

5V DC submersible water pump with TIP120 transistor driver and diode protection

LED indicator for system status


All components are powered by the Arduino 5V rail. The soil moisture sensor connects to an analog pin, and the pump is controlled through a digital output pin.

3. Operation
The system continuously monitors soil moisture levels every few seconds.

When the soil is dry, the pump automatically turns on to water the plants.

When the moisture level is optimal, the system continues monitoring without action.

When the soil is wet, watering stops automatically.


This ensures efficient use of water and prevents over-watering.

4. Testing and Results
Testing was done in Tinkercad to verify sensor calibration, decision thresholds, and pump control.
Results showed fast response, accurate detection, and consistent pump activation with zero false triggers.

5. Challenges and Solutions
Some challenges included interpreting sensor readings, handling pump current, and balancing timing cycles. These were solved by adjusting logic, adding a transistor with a diode for protection, and standardizing timing intervals.

6. Applications and Future Work
The system can be used in home gardens, small farms, and educational IoT demonstrations.
Future improvements could include solar power, weather-based automation, multiple watering zones, and mobile monitoring applications.

7. Conclusion
The Smart Irrigation System successfully achieved automated, reliable, and water-efficient irrigation. It demonstrates that cost-effective smart farming solutions can be created using simple IoT components. The system has potential to reduce water usage by 30–50 percent compared to traditional methods.

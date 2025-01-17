# Self-Balancing Robot (MSP430)
This project involves the development of a self-balancing robot using the MSP430 microcontroller. The robot is designed to maintain its balance autonomously through real-time adjustments, using sensors and motors to counteract any tilting. The primary goal of this project is to demonstrate the implementation of a feedback control system in robotics.


Features:

MSP430 Microcontroller: The core of the system, responsible for processing sensor data and controlling the motors.
MPU6050: An accelerometer and gyroscope used to measure the tilt and orientation of the robot.
L298N Motor Driver: Used to control the 6V DC motors that drive the robot’s wheels.
Self-balancing Mechanism: The robot uses feedback control to continuously adjust its position and stay upright.

# Electronic Components Used
I have prepared this project using the following components:
## 1.MSP430g2553 & LaunchPad

![Image](https://github.com/user-attachments/assets/34c795f6-d147-4867-8d31-e16f89440f1c)
  
![Image](https://github.com/user-attachments/assets/9a668750-a3ad-434f-a144-23f47e390419)
## 2.MPU6050 Gyroscope and Accelerometer

![Image](https://github.com/user-attachments/assets/874ac7aa-da2f-4784-97af-85e7290072e5)
## 3.l298n Motor Driver
![Image](https://github.com/user-attachments/assets/fec6dea8-bcea-4b7f-9fd2-c237f065792e)

## 4. 6V DC Motor
![Image](https://github.com/user-attachments/assets/d2b2ca54-b438-43c2-bad0-90abf0d0f688)

## 5.12V 3A Power Supply
Power Requirements:

Voltage: This circuit operates on a 8V to 12V power supply, which is suitable for both the motors and other components.
Current: The total current consumption of the circuit is approximately 1.5A when the motors are running under typical load conditions. A 12V 3A power supply should be sufficient to power the system.
![Image](https://github.com/user-attachments/assets/5a52fdaa-d75e-4e64-88b0-32a995209d01)

#### 5.1 LM1117T 3.3v
Note: A voltage regulator is required to provide 3.3V power for the MSP430 and MPU6050 components.
![Image](https://github.com/user-attachments/assets/6132cf95-9b24-466d-86e7-7416327ae114)
# Circuit Schematic & PCB
## 1. Schematic Of The Circuit
![Image](https://github.com/user-attachments/assets/d784af85-73a3-45fe-a86a-202b21c05503)
## 2. 5cm*10cm PCB
![Image](https://github.com/user-attachments/assets/8a9c8163-5e15-479b-912e-0d2a9a07e4e1)

# References
- **MSP430G2553** - [Texas Instruments](https://www.ti.com/product/MSP430G2553)
- **MPU6050** - [InvenSense Inc.](https://cdn.sparkfun.com/datasheets/Sensors/Accelerometers/RM-MPU-6000A.pdf)
- **L298N** - [Handson Technology](https://www.handsontec.com/dataspecs/L298N%20Motor%20Driver.pdf)
- **6V DC MOTOR** - [Handson Technology](https://handsontec.com/index.php/product/36v-mini-dc-gear-motor/)
- **LM1117 3.3V Voltage Regulator** - [ON Semiconductor](https://www.onsemi.com/products/power-management/linear-regulators-ldo/lm1117)
- **Arduino Nano Sample** - [Electric DIY Lab](https://electricdiylab.com/diy-self-balancing-robot/) 
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

![Image](https://github.com/user-attachments/assets/4f74f4d0-7925-464f-b19c-d381d5bea6a0)
  
![Image](https://github.com/user-attachments/assets/9d8a27a5-08ff-4a10-bd02-a31e1fe73148)

## 2.MPU6050 Gyroscope and Accelerometer
![Image](https://github.com/user-attachments/assets/3c99eb47-6610-4ef5-b66b-bb708f9765c2)

## 3.l298n Motor Driver
![Image](https://github.com/user-attachments/assets/56a81309-9af6-4280-bd58-7853800a305e)

## 4. 6V DC Motor
![Image](https://github.com/user-attachments/assets/eaeec5ca-359a-46af-a26a-376a46e8f67e)

## 5.12V 3A Power Supply
Power Requirements:

Voltage: This circuit operates on a 8V to 12V power supply, which is suitable for both the motors and other components.
Current: The total current consumption of the circuit is approximately 1.5A when the motors are running under typical load conditions. A 12V 3A power supply should be sufficient to power the system.
![Image](https://github.com/user-attachments/assets/26edc0e8-455e-4a14-81eb-db2babb52546)

#### 5.1 LM1117T 3.3v
Note: A voltage regulator is required to provide 3.3V power for the MSP430 and MPU6050 components.
![Image](https://github.com/user-attachments/assets/377ee12c-a037-4443-b7d2-ec0806ee8bd6)

# Circuit Schematic & PCB
## 1. Schematic Of The Circuit
![Image](https://github.com/user-attachments/assets/c4ff2317-6863-4797-b5d8-67119451579f)
## 2. 5cm*10cm PCB
![Image](https://github.com/user-attachments/assets/e24c7051-51b7-4c18-878f-5feb562a93ea)

# References
- **MSP430G2553** - [Texas Instruments](https://www.ti.com/product/MSP430G2553)
- **MPU6050** - [InvenSense Inc.](https://cdn.sparkfun.com/datasheets/Sensors/Accelerometers/RM-MPU-6000A.pdf)
- **L298N** - [Handson Technology](https://www.handsontec.com/dataspecs/L298N%20Motor%20Driver.pdf)
- **6V DC MOTOR** - [Handson Technology](https://handsontec.com/index.php/product/36v-mini-dc-gear-motor/)
- **LM1117 3.3V Voltage Regulator** - [ON Semiconductor](https://www.onsemi.com/products/power-management/linear-regulators-ldo/lm1117)
- **Arduino Nano Sample** - [Electric DIY Lab](https://electricdiylab.com/diy-self-balancing-robot/) 
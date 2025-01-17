#include "genel.h"
#include <math.h>

// Motor pinlerini tanımlama
#define MOTOR1_IN1 BIT3  // P1.3
#define MOTOR1_IN2 BIT4  // P1.4

#define MOTOR2_IN3 BIT2  // P2.2
#define MOTOR2_IN4 BIT3  // P2.3

// MPU6050 I2C adresi
#define MPU6050_ADDR 0x68
#define ACCEL_XOUT_H 0x3B
#define ACCEL_YOUT_H 0x3D
#define ACCEL_ZOUT_H 0x3F
#define PWR_MGMT_1 0x6B

// I2C ile veri yazma ve okuma fonksiyon prototipleri
void i2c_write(uint8_t addr, uint8_t reg, uint8_t data);
uint16_t i2c_read(uint8_t addr, uint8_t reg);

// Motor kontrol fonksiyonları
void motor_init();
void motor1_forward();
void motor1_backward();
void motor1_stop();
void motor2_forward();
void motor2_backward();
void motor2_stop();

// MPU6050 başlatma
void mpu6050_init() {
    i2c_write(MPU6050_ADDR, PWR_MGMT_1, 0x00);  // Uyku modundan çıkar
}

// MPU6050 ivme verilerini okuma
int16_t read_accel_x() {
    return (i2c_read(MPU6050_ADDR, ACCEL_XOUT_H) << 8) | i2c_read(MPU6050_ADDR, ACCEL_XOUT_H + 1);
}

int16_t read_accel_y() {
    return (i2c_read(MPU6050_ADDR, ACCEL_YOUT_H) << 8) | i2c_read(MPU6050_ADDR, ACCEL_YOUT_H + 1);
}

int16_t read_accel_z() {
    return (i2c_read(MPU6050_ADDR, ACCEL_ZOUT_H) << 8) | i2c_read(MPU6050_ADDR, ACCEL_ZOUT_H + 1);
}

// Açı hesaplama
float calculate_angle(int16_t accel_x, int16_t accel_y, int16_t accel_z) {
    float angle = atan2(accel_y, accel_z) * 180.0 / 3.14159265;  // Y ve Z eksenine göre açı hesapla
    return angle;
}

// Ana fonksiyon
void main() {
    WDTCTL = WDTPW | WDTHOLD;  // Watchdog Timer'ı durdur

    motor_init();     // Motorları başlat
    mpu6050_init();   // MPU6050'i başlat

    int16_t accel_x, accel_y, accel_z;
    float angle;

    while (1) {
        accel_x = read_accel_x();  // X eksenindeki ivmeyi oku
        accel_y = read_accel_y();  // Y eksenindeki ivmeyi oku
        accel_z = read_accel_z();  // Z eksenindeki ivmeyi oku

        // Açı hesapla
        angle = calculate_angle(accel_x, accel_y, accel_z);

        // Motor kontrolünü yap
        if (angle > 5.0) {  // Pozitif eğim, motorlar ileri
            motor1_forward();
            motor2_forward();
        } else if (angle < -5.0) {  // Negatif eğim, motorlar geri
            motor1_backward();
            motor2_backward();
        } else {  // Açı yok, motorlar duruyor
            motor1_stop();
            motor2_stop();
        }

        __delay_cycles(10000);  // motor surucusu icin gerekli gecikme
    }
}

// Motor kontrol ve I2C yazma/okuma kodları aşağıda:

void motor_init() {
    P1DIR |= MOTOR1_IN1 + MOTOR1_IN2;  // Motor 1 pinlerini çıkış olarak ayarla
    P2DIR |= MOTOR2_IN3 + MOTOR2_IN4;  // Motor 2 pinlerini çıkış olarak ayarla
    P1OUT &= ~(MOTOR1_IN1 + MOTOR1_IN2);  // Motor 1 yön pinlerini sıfırla
    P2OUT &= ~(MOTOR2_IN3 + MOTOR2_IN4);  // Motor 2 yön pinlerini sıfırla
}

void motor1_forward() {
    P1OUT |= MOTOR1_IN1;  // Motor 1'in ileri yönü
    P1OUT &= ~MOTOR1_IN2;
}

void motor1_backward() {
    P1OUT |= MOTOR1_IN2;  // Motor 1'in geri yönü
    P1OUT &= ~MOTOR1_IN1;
}

void motor1_stop() {
    P1OUT &= ~(MOTOR1_IN1 + MOTOR1_IN2);  // Motor 1'i durdur
}

void motor2_forward() {
    P2OUT |= MOTOR2_IN3;  // Motor 2'nin ileri yönü
    P2OUT &= ~MOTOR2_IN4;
}

void motor2_backward() {
    P2OUT |= MOTOR2_IN4;  // Motor 2'nin geri yönü
    P2OUT &= ~MOTOR2_IN3;
}

void motor2_stop() {
    P2OUT &= ~(MOTOR2_IN3 + MOTOR2_IN4);  // Motor 2'yi durdur
}

// I2C işlemleri
void i2c_write(uint8_t addr, uint8_t reg, uint8_t data) {
    UCB0I2CSA = addr;  // I2C adresi belirle
    UCB0CTL1 |= UCTR + UCTXSTT;  // Yazma moduna geç ve start gönder

    while (!(IFG2 & UCB0TXIFG));  // Verinin gönderilmesini bekle
    UCB0TXBUF = reg;  // Register adresini gönder

    while (!(IFG2 & UCB0TXIFG));  // Verinin gönderilmesini bekle
    UCB0TXBUF = data;  // Veriyi gönder

    while (!(IFG2 & UCB0TXIFG));  // Verinin gönderilmesini bekle
    UCB0CTL1 |= UCTXSTP;  // Stop bitini gönder
    while (UCB0CTL1 & UCTXSTP);  // Stop bitinin gönderilmesini bekle
}

uint16_t i2c_read(uint8_t addr, uint8_t reg) {
    uint8_t data;

    UCB0I2CSA = addr;  // I2C adresi belirle
    UCB0CTL1 |= UCTR + UCTXSTT;  // Yazma moduna geç ve start gönder

    while (!(IFG2 & UCB0TXIFG));  // Verinin gönderilmesini bekle
    UCB0TXBUF = reg;  // Register adresini gönder

    while (!(IFG2 & UCB0TXIFG));  // Verinin gönderilmesini bekle
    UCB0CTL1 &= ~UCTR;  // Okuma moduna geç
    UCB0CTL1 |= UCTXSTT;  // Tekrar start gönder

    while (UCB0CTL1 & UCTXSTT);  // Start bitinin tamamlanmasını bekle
    data = UCB0RXBUF;  // Veriyi al

    UCB0CTL1 |= UCTXSTP;  // Stop bitini gönder
    while (UCB0CTL1 & UCTXSTP);  // Stop bitinin tamamlanmasını bekle

    return data;
}

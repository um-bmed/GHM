#pragma once
#include <Arduino.h>
#include "PicoGamepad.h"
#include "GY521.h"

#define GYRORANGE 250
#define ACCELRANGE 2
class HeadGamingMouse {

private:
    PicoGamepad *gamepad;
    GY521 *imu;
    arduino::MbedI2C *wire;

    // Pins
    static const uint sda_pin;
    static const uint scl_pin;

    uint16_t gyro_delay;
    uint16_t last_gyro_time;
    uint16_t cur_time;
    uint16_t gyroNoise;
    uint16_t accelNoise;
    uint16_t flag;

    class Data;
    Data *gyro;
    Data *accel;
    Data *gyroPrev;
    Data *accelPrev;
    Data *gyroDelta;
    Data *accelDelta;
    Data *gyroZero;
    Data *accelZero;

    bool data_ready;

    void readFromGyro();
    void sendToGamepad();
    boolean calcDelta();
    void calibrate();
    void scaleGyro();

    class Data {
    public:
        uint16_t x;
        uint16_t y;
        uint16_t z;
        Data();
    };

protected:


public:
    HeadGamingMouse(PicoGamepad *gamepad);
    HeadGamingMouse();
    ~HeadGamingMouse();
    void process();
    void demo_gamepad();
    void demo_imu();

};
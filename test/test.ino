/*
  PicoGamepad

  Turn a Raspberry Pico 2040 into an HID gamepad

  Supports:
  128 Buttons
  8 Analog axes
  4 Hat switches
  
  created 28 June 2021
  by Jake Wilkinson (RealRobots)

  This example code is in the public domain.

  https://www.gitlab.com/realrobots/PicoGamepad
*/

#include <PicoGamepad.h>
#include <GY521.h>

struct gyrodata {
    float* x;
    float* y;
    float* z;
};

struct acceldata {
    float* x;
    float* y;
    float* z;   
};

struct magdata {
    float* x;
    float* y;
    float* z;
};

PicoGamepad gamepad;
GY521 imu;


// 16 bit integer for holding input values
int val;

uint16_t gyro_delay;
uint16_t last_gyro_time;
uint16_t cur_time;
boolean data_ready = false;

struct gyrodata gyro;
struct acceldata accel;
struct magdata mag;

void setup() {  
  Serial.begin(115200);
  
  
  //pinMode(LED_BUILTIN, OUTPUT);

  // X Potentiometer on pin 26
  //pinMode(26, INPUT);
  // Y Potentiometer on pin 27
  //pinMode(27, INPUT);

  // Button on pin 
  //pinMode(28, INPUT_PULLUP);


  gyro.x = new float();
  gyro.y = new float();
  gyro.z = new float();

  accel.x = new float();
  accel.y = new float();
  accel.z = new float();

  // Pins
  const uint sda_pin = 26;
  const uint scl_pin = 27;

  MbedI2C i2c(sda_pin, scl_pin);

  // Initialize I2C pins
  gpio_set_function(sda_pin, GPIO_FUNC_I2C);
  gpio_set_function(scl_pin, GPIO_FUNC_I2C);

  i2c.begin();
}

void loop() {

 
  cur_time = millis();

  //if (cur_time - last_gyro_time > gyro_delay) {
    //    last_gyro_time = cur_time;

        //imu->read();

    //    *accel.x = (float) random(0, 100);
    //    *accel.y = (float) random(0, 100);
    //    *accel.z = (float) random(0, 100);

    //    *gyro.x = (float) random(0, 100);
    //    *gyro.y = (float) random(0, 100);
    //    *gyro.z = (float) random(0, 100);

    //    data_ready = true;

    //}
    // poll gyroscope within a certain time interval
     if (cur_time - last_gyro_time > gyro_delay) {
         last_gyro_time = cur_time;

         imu.read();

         *accel.x = imu.getAccelX();
         *accel.y = imu.getAccelY();
         *accel.z = imu.getAccelZ();

         *gyro.x = imu.getRoll();
         *gyro.y = imu.getPitch();
         *gyro.z = imu.getYaw();

         data_ready = true;

     }
  
    //pass data to gamepad
    if (data_ready) {
        gamepad.SetRx(*gyro.x);
        gamepad.SetRy(*gyro.y);
        gamepad.SetRz(*gyro.z);

        gamepad.send_update();
        data_ready = false;
    }

  // Get input value from Pico analog pin
  //val = analogRead(26);

  // Map analog 0-1023 value from pin to max HID range -32767 - 32767
  //val = map(val, 0, 1023, -32767, 32767);

  // Send value to HID object
  //gamepad.SetX(val);

  // Repeat with Y pin
  //val = analogRead(27);
  //val = map(val, 0, 1023, -32767, 32767);
  //gamepad.SetY(val);
  
//  gamepad.SetZ(val);
//  gamepad.SetRx(val);
//  gamepad.SetRy(val);
//  gamepad.SetRz(val);
//  gamepad.SetS0(val);
//  gamepad.SetS1(val);

  // Set button 0 of 128 by reading button on digital pin 28
  //gamepad.SetButton(0, !digitalRead(28));

  // Set hat direction, 4 hats available. direction is clockwise 0=N 1=NE 2=E 3=SE 4=S 5=SW 6=W 7=NW 8=CENTER 
  // gamepad.SetHat(0, 8);


  // Send all inputs via HID 
  // Nothing is send to your computer until this is called.
  gamepad.send_update();

  // Flash the LED just for fun
  //digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); 
  //delay(100);
}
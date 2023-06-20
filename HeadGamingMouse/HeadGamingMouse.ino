
#include "HeadGamingMouse.h"
#include "PicoGamepad.h"

PicoGamepad gamepad;

HeadGamingMouse *mouse;

uint64_t cur_time;
uint64_t last_gyro_time;
uint64_t gyro_delay;
uint64_t flag;

void setup()
{
  Serial.begin( 115200 );
  mouse = new HeadGamingMouse( &gamepad );
  //mouse = new HeadGamingMouse;

  gyro_delay = 2000;
  last_gyro_time = 0;
  flag = 0;
}

void loop()
{
  mouse->process();

  cur_time = millis();
  if ( cur_time - last_gyro_time > gyro_delay )
  {
    last_gyro_time = cur_time;
    mouse->demo_imu();
  }

}

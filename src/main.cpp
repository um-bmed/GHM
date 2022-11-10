#include <Arduino.h>
//#include "../lib/PicoGamepad.h"
//#include <SPI.h>
//#include <Wire.h>



//PicoGamepad *gamepad = nullptr;

void setup() {

  // put your setup code here, to run once:
  // Serial.begin(9600);
  //gamepad = new PicoGamepad();
  


  
}

void loop() {
  // put your main code here, to run repeatedly:


}


/* void testXYAxis(unsigned int currentStep)
{
  int xAxis;
  int yAxis;
  
  if (currentStep < 256)
  {
    xAxis = currentStep - 127;
    yAxis = -127;
    Joystick.setXAxis(xAxis);
    Joystick.setYAxis(yAxis);
  } 
  else if (currentStep < 512)
  {
    yAxis = currentStep - 256 - 127;
    Joystick.setYAxis(yAxis);
  }
  else if (currentStep < 768)
  {
    xAxis = 128 - (currentStep - 512);
    Joystick.setXAxis(xAxis);
  }
  else if (currentStep < 1024)
  {
    yAxis = 128 - (currentStep - 768);
    Joystick.setYAxis(yAxis);
  }
  else if (currentStep < 1024 + 128)
  {
    xAxis = currentStep - 1024 - 127;
    Joystick.setXAxis(xAxis);
    Joystick.setYAxis(xAxis);
  }
}

void testZAxis(unsigned int currentStep)
{
  if (currentStep < 128)
  {
    Joystick.setZAxis(-currentStep);
  } 
  else if (currentStep < 256 + 128)
  {
    Joystick.setZAxis(currentStep - 128 - 127);
  } 
  else if (currentStep < 256 + 128 + 127)
  {
    Joystick.setZAxis(127 - (currentStep - 383));
  } 
}

void testXYZAxisRotation(unsigned int degree)
{
  Joystick.setRxAxis(degree);
  Joystick.setRyAxis(degree);
  Joystick.setRzAxis(degree * 2);
}


void loop() {

  // System Disabled
  if (digitalRead(A0) != 0)
  {
    // Turn indicator light off.
    digitalWrite(LED_BUILTIN, 0);
    return;
  }

  // Turn indicator light on.
  digitalWrite(LED_BUILTIN, 1);
  
  if (millis() >= gNextTime)
  {
   
    if (gCurrentStep < (37 + 256 + 1024 + 128))
    {
      gNextTime = millis() + gcAnalogDelta;
      testXYAxis(gCurrentStep - (37 + 256));
    }
    else if (gCurrentStep < (37 + 256 + 1024 + 128 + 510))
    {
      gNextTime = millis() + gcAnalogDelta;
      testZAxis(gCurrentStep - (37 + 256 + 1024 + 128));
    }
    else if (gCurrentStep < (37 + 256 + 1024 + 128 + 510 + 28 + 360))
    {
      gNextTime = millis() + gcAnalogDelta;
      testXYZAxisRotation(gCurrentStep - (37 + 256 + 1024 + 128 + 510 + 28));
    }
    
    if (testAutoSendMode == false)
    {
      Joystick.sendState();
    }
    
    gCurrentStep++;
    if (gCurrentStep == (37 + 256 + 1024 + 128 + 510 + 28 + 360))
    {
      gNextTime = millis() + gcCycleDelta;
      gCurrentStep = 0;
    }
  }
}
 */
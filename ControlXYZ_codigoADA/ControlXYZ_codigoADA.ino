#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

#define Serial SERIAL_PORT_USBVIRTUAL
#define PASOS_REV 1024

  //creación del objeto Wing
  Adafruit_MotorShield f_Axis;
  Adafruit_MotorShield AxisX = Adafruit_MotorShield(0x60);
  Adafruit_MotorShield AxisY = Adafruit_MotorShield(0x61); 
  Adafruit_MotorShield AxisZ = Adafruit_MotorShield(0x62);
 
  //creación del objeto stepper
   Adafruit_StepperMotor *f_Stepper;
 
const int BUFFER_SIZE = 50;
byte buf[BUFFER_SIZE];
unsigned int N_steps;


void setup() {
  
  Serial.begin(9600);

  AxisX.begin();
  AxisY.begin();
  AxisZ.begin();

   buf[0] = 0x60; buf[1] = 0x01; buf[2] = 0x01; buf[3] = 0x04; buf[4] = 0x04; buf[5] = 0x00;

  f_Stepper = AxisX.getStepper(PASOS_REV, buf[1]);
}


void loop() {
/*
  if (Serial.available() > 0) {
    int rlen = Serial.readBytes((char*)buf, BUFFER_SIZE);

    
    Serial.print("Se ha recibido: ");
    for(int i = 0; i < rlen; i++)
      Serial.print(buf[i]); 
    

    f_Axis = Adafruit_MotorShield(buf[0]);
    f_Stepper = f_Axis.getStepper(N_steps, buf[1]);
                             
  }
*/

  N_steps = buf[4]*256 + buf[5];
  f_Stepper->step(N_steps, buf[2], buf[3]);
  f_Stepper->release();
  
  delay(100);
}

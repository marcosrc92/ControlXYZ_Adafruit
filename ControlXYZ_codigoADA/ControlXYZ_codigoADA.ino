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
  Adafruit_StepperMotor *X1_Stepper, *X2_Stepper, *Y1_Stepper, *Y2_Stepper, *Z1_Stepper, *Z2_Stepper;
 
const int BUFFER_SIZE = 6;
char buf[BUFFER_SIZE];
unsigned int N_steps=0;

void move_stepper(){

  char eje = buf[0];
  char motor = buf[1];

  N_steps = buf[4]*256 + buf[5];
  
  switch (motor){
    case 0x01:
      if(eje == 0x60){
        X1_Stepper->step(N_steps, buf[2], buf[3]);
        X1_Stepper->release();
      }
      else if(eje == 0x61){
        Y1_Stepper->step(N_steps, buf[2], buf[3]);
        Y1_Stepper->release();
      }
      else if(eje == 0x62){
        Z1_Stepper->step(N_steps, buf[2], buf[3]);
        Z1_Stepper->release();
      }
    break;

    case 0x02:
      if(eje == 0x60){
        X2_Stepper->step(N_steps, buf[2], buf[3]);
        X2_Stepper->release();
      }
      else if(eje == 0x61){
        Y2_Stepper->step(N_steps, buf[2], buf[3]);
        Y2_Stepper->release();
      }
      else if(eje == 0x62){
        Z2_Stepper->step(N_steps, buf[2], buf[3]);
        Z2_Stepper->release();
      }
    break;
    
  }
  
  //f_Stepper->step(N_steps, buf[2], buf[3]);
  //f_Stepper->release();
  buf[4] = 0; buf[5] = 0;
}

void setup() {
  
  Serial.begin(9600);

  AxisX.begin();
  AxisY.begin();
  AxisZ.begin();

  X1_Stepper = AxisX.getStepper(PASOS_REV, 1);
  X2_Stepper = AxisX.getStepper(PASOS_REV, 2);
  Y1_Stepper = AxisY.getStepper(PASOS_REV, 1);
  Y2_Stepper = AxisY.getStepper(PASOS_REV, 2);
  Z1_Stepper = AxisZ.getStepper(PASOS_REV, 1);
  Z2_Stepper = AxisZ.getStepper(PASOS_REV, 2);
}



void loop() {

  if (Serial.available() > 0) {
    int rlen = Serial.readBytes(buf, BUFFER_SIZE);

    
    Serial.print("Se ha recibido: ");
    for(int i = 0; i < rlen; i++)
      Serial.print(buf[i]); 

    move_stepper();                             
  }

  delay(100);
}

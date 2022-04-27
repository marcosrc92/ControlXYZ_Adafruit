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
 
const int BUFFER_SIZE = 6;
char buf[BUFFER_SIZE];
unsigned int N_steps=0;

void move_stepper(){
  N_steps = buf[4]*256 + buf[5];
  f_Stepper->step(N_steps, buf[2], buf[3]);
  f_Stepper->release();
  buf[4] = 0; buf[5] = 0;
}

void setup() {
  
  Serial.begin(9600);

  AxisX.begin();
  AxisY.begin();
  AxisZ.begin();

  f_Stepper = AxisX.getStepper(PASOS_REV, 1);
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

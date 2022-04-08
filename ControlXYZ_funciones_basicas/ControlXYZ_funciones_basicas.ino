#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

#define Serial SERIAL_PORT_USBVIRTUAL

  //creación de objetos Wing
  Adafruit_MotorShield AxisX = Adafruit_MotorShield(0x60);
  Adafruit_MotorShield AxisY = Adafruit_MotorShield(0x61); 
  Adafruit_MotorShield AxisZ = Adafruit_MotorShield(0x62);

  //creación de objetos stepper
  unsigned int N_steps = 1024;
  Adafruit_StepperMotor *Stepper_X1 = AxisX.getStepper(N_steps, 1);
  Adafruit_StepperMotor *Stepper_X2 = AxisX.getStepper(N_steps, 2);
  Adafruit_StepperMotor *Stepper_Y1 = AxisY.getStepper(N_steps, 1);
  Adafruit_StepperMotor *Stepper_Y2 = AxisY.getStepper(N_steps, 2);
  Adafruit_StepperMotor *Stepper_Z1 = AxisZ.getStepper(N_steps, 1);
  Adafruit_StepperMotor *Stepper_Z2 = AxisZ.getStepper(N_steps, 2);

void setup() {
  
  Serial.begin(9600);
  AxisX.begin();
  AxisY.begin();
  AxisZ.begin();

  Stepper_X1->release();
  Stepper_X2->release();
  Stepper_Y1->release();
  Stepper_Y2->release();
  Stepper_Z1->release();
  Stepper_Z2->release();


}

const int BUFFER_SIZE = 50;
char buf[BUFFER_SIZE];

void loop() {

  if (Serial.available() > 0) {
    int rlen = Serial.readBytes(buf, BUFFER_SIZE);

    Serial.print("Se ha recibido: ");
    for(int i = 0; i < rlen; i++)
      Serial.print(buf[i]);                        
  }

  //if(buf[0] == 's'){
  if(buf[0] == 0x73){
    Serial.println("Single coil steps");
    Stepper_X1->step(1024, FORWARD, SINGLE);
    Stepper_X1->step(1024, BACKWARD, SINGLE);
  }

  //else if(buf[0] == 'd'){
  if(buf[0] == 0x64){
    Serial.println("Double coil steps");
    Stepper_X1->step(1024, FORWARD, DOUBLE);
    Stepper_X1->step(1024, BACKWARD, DOUBLE);
  }

  //else if(buf[0] == 'i'){
  if(buf[0] == 0x69){
    Serial.println("Interleave steps");
    Stepper_X1->step(1024, FORWARD, INTERLEAVE);
    Stepper_X1->step(1024, BACKWARD, INTERLEAVE);
  }

  //else if(buf[0] == 'm'){  
  if(buf[0] == 0x6D){
    Serial.println("Microstep steps");
    Stepper_X1->step(1024, FORWARD, MICROSTEP);
    Stepper_X1->step(1024, BACKWARD, MICROSTEP);
  }

  else
    Stepper_X1->release();
  
  delay(100);
}

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"


void setup() {

  //creación de objetos Wing
  Adafruit_MotorShield AxisX = Adafruit_MotorShield(0x60);
  Adafruit_MotorShield AxisY = Adafruit_MotorShield(0x61); 
  Adafruit_MotorShield AxisZ = Adafruit_MotorShield(0x62);

  //creación de objetos stepper
  unsigned int N_steps = 1000;
  Adafruit_StepperMotor *Stepper_X1 = AxisX.getStepper(N_steps, 1);
  Adafruit_StepperMotor *Stepper_X2 = AxisX.getStepper(N_steps, 2);
  Adafruit_StepperMotor *Stepper_Y1 = AxisY.getStepper(N_steps, 1);
  Adafruit_StepperMotor *Stepper_Y2 = AxisY.getStepper(N_steps, 2);
  Adafruit_StepperMotor *Stepper_Z1 = AxisZ.getStepper(N_steps, 1);
  Adafruit_StepperMotor *Stepper_Z2 = AxisZ.getStepper(N_steps, 2);

  

}

void loop() {
  // put your main code here, to run repeatedly:

}

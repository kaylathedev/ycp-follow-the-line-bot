/*!
 * \brief  Controls the motor through a L293 and the serial monitor.
 */

#include "ir_arduino_driver.h"
#include "motor_arduino_driver.h"

#include<Arduino.h>

/**
 * Driver Inputs
 *   Arduino #6 = Pin #2 on L293, (Driver input)
 *   Arduino #5 = Pin #7 on L293, (Driver input)
 *   Arduino #8 = Pin #10 on L293, (Driver input)
 *   Arduino #7 = Pin #15 on L293, (Driver input)
 * PWM
 *  Arduino #10 = Pin #1 on L293, (1,2EN)
 *  Arduino #11 = Pin #9 on L293, (3,4EN)
 */
Motor_Arduino_Driver motor = Motor_Arduino_Driver(6, 5, 8, 7, 10, 11);
IR_Arduino_Driver ir = IR_Arduino_Driver(A0, A1);
float current_direction = 0.0;
float current_speed     = 0.0;

void setup() {
}

void loop() {
  loop_turn_only_on_detection();
}

void loop_turn_only_on_detection() {
  //int left = ir.readLeft();
  //int right = ir.readRight();

  if (ir.readLeft() > 200) {
    motor.pivotLeft(0.2);
    delay(200); // short time
    return;
  }
  if (ir.readRight() > 200) {
    motor.pivotRight(0.2);
    delay(200); // short time
    return;
  }

  motor.setVelocity(0.0, 0.2); // straight
}


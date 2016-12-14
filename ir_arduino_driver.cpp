#include "ir_arduino_driver.h"

#include<Arduino.h>

int IR_Arduino_Driver::readLeft() {
  return analogRead(ir_sensor_left);
}
int IR_Arduino_Driver::readRight() {
  return analogRead(ir_sensor_right);
}
IR_Arduino_Driver::IR_Arduino_Driver(int ir_left, int ir_right) {
  ir_sensor_left = ir_left;
  ir_sensor_right = ir_right;

  pinMode(ir_sensor_left, INPUT_PULLUP);
  pinMode(ir_sensor_right, INPUT_PULLUP);
}
bool IR_Arduino_Driver::isLeftBlack() {
  int value = readLeft();
  return value > 60;
}
bool IR_Arduino_Driver::isRightBlack() {
  int value = readRight();
  return value > 60;
}


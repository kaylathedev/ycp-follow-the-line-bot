#include "motor_arduino_driver.h"

#include<Arduino.h>

void Motor_Arduino_Driver::setLeftSpeed(float speed) {
  speed *= 255;
  if (speed < 0) {
    speed = -speed;
    digitalWrite(motor_left_a, LOW);
    digitalWrite(motor_left_b, HIGH);
  } else {
    digitalWrite(motor_left_a, HIGH);
    digitalWrite(motor_left_b, LOW);
  }
  analogWrite(motor_speed_left, speed);
}
void Motor_Arduino_Driver::setRightSpeed(float speed) {
  speed *= 255;
  if (speed < 0) {
    speed = -speed;
    digitalWrite(motor_right_a, LOW);
    digitalWrite(motor_right_b, HIGH);
  } else {
    digitalWrite(motor_right_a, HIGH);
    digitalWrite(motor_right_b, LOW);
  }
  analogWrite(motor_speed_right, speed);
}
Motor_Arduino_Driver::Motor_Arduino_Driver(int left_a, int left_b, int right_b, int right_a, int speed_left, int speed_right) {
  motor_left_a = left_a;
  motor_left_b = left_b;
  motor_right_b = right_b;
  motor_right_a = right_a;
  motor_speed_left = speed_left;
  motor_speed_right = speed_right;

  int outputs[] = {motor_left_a, motor_left_a,
                   motor_left_b, motor_right_b,
                   speed_left, speed_right};

  // Set each of the output pins to OUTPUT
  int length = sizeof(outputs) / sizeof(outputs[0]);
  for (int i = 0; i < length; i++) {
    pinMode(outputs[i], OUTPUT);
  }
}
void Motor_Arduino_Driver::setVelocity(float direction, float speed) {
  int left, right;
  if (direction > 0) {
    left = (1 - (direction));
    right = 1;
  } else {
    left = 1;
    right = (1 - (-direction));
  }

  setLeftSpeed(speed * left);
  setRightSpeed(speed * right);
}
void Motor_Arduino_Driver::pivotLeft(float speed) {
  setLeftSpeed(speed);
  setRightSpeed(-speed);
}

void Motor_Arduino_Driver::pivotRight(float speed) {
  setLeftSpeed(-speed);
  setRightSpeed(speed);
}


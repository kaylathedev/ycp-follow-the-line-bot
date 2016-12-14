#ifndef MOTOR_ARDUINO_DRIVER
#define MOTOR_ARDUINO_DRIVER

class Motor_Arduino_Driver {
  private:

    int motor_left_a;
    int motor_left_b;

    int motor_right_b;
    int motor_right_a;

    // PWM
    int motor_speed_left;
    int motor_speed_right;

  public:
    /**
     * Sets the speed of the left motor from -1.0 to +1.0
     * -1.0 will put the motor into reverse
     * +1.0 will put the motor moving forward
     */
    void setLeftSpeed(float speed);

    /**
     * Sets the speed of the right motor from -1.0 to +1.0
     * -1.0 will put the motor into reverse
     * +1.0 will put the motor moving forward
     */
    void setRightSpeed(float speed);

    Motor_Arduino_Driver(int left_a, int left_b, int right_b, int right_a, int speed_left, int speed_right);
    /*
     * Direction is from -1.0 to +1.0
     * A direction of -1.0 indicates maximum speed on only left motor
     * A direction of +1.0 indicates maximum speed on only right motor
     */
    void setVelocity(float direction, float speed);
    void pivotLeft(float speed);
    void pivotRight(float speed);
};

#endif


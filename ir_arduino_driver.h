#ifndef IR_ARDUINO_DRIVER
#define IR_ARDUINO_DRIVER

/**
 * Infrared sensor driver for the arduino.
 * 
 * Allows the user to see if the arduino is over white or black.
 */
class IR_Arduino_Driver {
  private:
    int ir_sensor_left;
    int ir_sensor_right;

  public:
    IR_Arduino_Driver(int ir_left, int ir_right);
    bool isLeftBlack();
    bool isRightBlack();
    int readLeft();
    int readRight();
};

#endif


/*
  SparkFun Inventor's Kit
  Example sketch 18

  Controlling a Motor using an Accelerometer

  Use the on-board acceleromter of the 101 board as an input to contol
  a motor based on its orientation in space. If you tilt the 101 to the left
  the motor spins in one direction, the right; the oposite direction and if it
  is flat the motor stops.

  This sketch was written by SparkFun Electronics, and based on the Orientation example
  in the CurieIMU Library Examples
  This code is completely free for any use.
  Visit http://learn.sparkfun.com/products/2 for SIK information.
  Visit http://www.arduino.cc to learn about the Arduino.
*/

#include "CurieIMU.h"

const int DIR_A = 4;
const int DIR_B = 5;
const int PWM = 6;

// previous orientation (for comparison). Start at (-1) to start with


void setup()
{
  //set motor control pins to OUTPUT
  pinMode(DIR_A, OUTPUT);
  pinMode(DIR_B, OUTPUT);
  pinMode(PWM, OUTPUT);

  // Start the acceleromter
  CurieIMU.begin();

  // Set the accelerometer range to 2G
  CurieIMU.setAccelerometerRange(2);
}

void loop()
{
  // read accelerometer:
  int x = CurieIMU.readAccelerometer(X_AXIS);
  int y = CurieIMU.readAccelerometer(Y_AXIS);
  int z = CurieIMU.readAccelerometer(Z_AXIS);

  // calculate the absolute values, to determine the largest
  int absX = abs(x);
  int absY = abs(y);
  int absZ = abs(z);

  if ( (absZ > absX) && (absZ > absY))
  {
    // base orientation on Z
    if (z > 0)
    {
      brake();
    }
  }

  //else if Y is greater than X and Z its on edge
  else if ( (absY > absX) && (absY > absZ))
  {
    // if Y is positive orientation (digital pins up)and is set to 1
    if (y > 0)
    {
      forward();
    }
    //the Y is in the negative orientation (analog pins up) and is set to 2
    else
    {
      reverse();
    }
  }
}
//custom function for driving the motor forward
void forward()
{
  digitalWrite(DIR_A, HIGH);
  digitalWrite(DIR_B, LOW);
  digitalWrite(PWM, HIGH);
}

//custom function for driving the motor in reverse
void reverse()
{
  digitalWrite(DIR_A, LOW);
  digitalWrite(DIR_B, HIGH);
  digitalWrite(PWM, HIGH);
}

//custom function for braking the motor
void brake()
{
  digitalWrite(DIR_A, LOW);
  digitalWrite(DIR_B, LOW);
  digitalWrite(PWM, LOW);
}


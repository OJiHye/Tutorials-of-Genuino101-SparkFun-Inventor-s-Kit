/*
  SparkFun Inventor's Kit
  Example sketch 19

  TAP DETECTION

  Use the 101 boards on-board IMU to detect a tap and double tap and react accordingly

  This sketch was written by SparkFun Electronics,
  with lots of help from the Arduino community.
  This code is completely free for any use.
  Visit http://learn.sparkfun.com/products/2 for SIK information.
  Visit http://www.arduino.cc to learn about the Arduino.
*/

#include "CurieIMU.h"

const int redPin = 5;
const int greenPin = 6;
const int bluePin = 9;
void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Initialise the IMU
  CurieIMU.begin();
  CurieIMU.attachInterrupt(eventCallback);

  // Increase Accelerometer range to allow detection of stronger taps (< 4g)
  CurieIMU.setAccelerometerRange(3);

  // Reduce threshold to allow detection of weaker taps (>= 750mg)
  CurieIMU.setDetectionThreshold(CURIE_IMU_TAP, 750); // (750mg)

  // Set the time window for 2 taps  as a double-tap (<= 250 milliseconds)
  CurieIMU.setDetectionDuration(CURIE_IMU_DOUBLE_TAP, 250);

  // Enable Double-Tap detection
  CurieIMU.interrupts(CURIE_IMU_DOUBLE_TAP);
}

void loop()
{
  // nothing happens in the loop because all the action happens
  // in the callback function.
}

static void eventCallback()
{
  if (CurieIMU.getInterruptStatus(CURIE_IMU_DOUBLE_TAP)) {
    if (CurieIMU.tapDetected(Z_AXIS, NEGATIVE))
    {
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, LOW);
      delay(250);
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      delay(250);
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, LOW);
      delay(250);
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      delay(250);
    }
    else if (CurieIMU.tapDetected(Z_AXIS, POSITIVE))
    {
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, HIGH);
      delay(250);
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      delay(250);
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, HIGH);
      delay(250);
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      delay(250);
    }
    else
    {
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, HIGH);
    }
  }
}


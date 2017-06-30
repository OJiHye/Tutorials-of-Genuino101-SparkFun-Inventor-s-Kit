/*
  SparkFun Inventor's Kit
  Example sketch 11

  SPINNING A MOTOR

  Use a transistor to spin a motor at different speeds.

  This sketch was written by SparkFun Electronics,
  with lots of help from the Arduino community.
  This code is completely free for any use.
  Visit http://learn.sparkfun.com/products/2 for SIK information.
  Visit http://www.arduino.cc to learn about the Arduino.
*/

// constant pin for the transistor connected to the motor
const int motorPin = 9;


void setup()
{
  //set motorPin as OUTPUT
  pinMode(motorPin, OUTPUT);
}


void loop()
{
  // Here we've used comments to disable some of the examples.
  // To try different things, uncomment one of the following lines
  // and comment the other ones. See the functions below to learn
  // what they do and how they work.

  motorOnThenOff();
  // motorOnThenOffWithSpeed();
  // motorAcceleration();
}


// This function turns the motor on and off like the blinking LED.
// Try different values to affect the timing.
void motorOnThenOff()
{
  // milliseconds to turn the motor on
  int onTime = 3000;
  // milliseconds to turn the motor off
  int offTime = 3000;

  // turn the motor on (full speed)
  digitalWrite(motorPin, HIGH);
  // delay for onTime milliseconds
  delay(onTime);
  // turn the motor off
  digitalWrite(motorPin, LOW);
  // delay for offTime milliseconds
  delay(offTime);
}


// This function alternates between two speeds.
// Try different values to affect the timing and speed.
void motorOnThenOffWithSpeed()
{
  // between 0 (stopped) and 255 (full speed)
  int Speed1 = 200;
  // milliseconds for speed 1
  int Time1 = 3000;

  // between 0 (stopped) and 255 (full speed)
  int Speed2 = 50;
  // milliseconds to turn the motor off
  int Time2 = 3000;

  // turns the motor On
  analogWrite(motorPin, Speed1);
  // delay for onTime milliseconds
  delay(Time1);
  // turns the motor Off
  analogWrite(motorPin, Speed2);
  // delay for offTime milliseconds
  delay(Time2);
}


// This function slowly accelerates the motor to full speed,
// then back down to zero.
void motorAcceleration()
{
  // milliseconds between each speed step
  int speed;
  int delayTime = 20;

  // accelerate the motor
  for (speed = 0; speed <= 255; speed++)
  {
    // set the new speed
    analogWrite(motorPin, speed);
    // delay between speed steps
    delay(delayTime);
  }

  // decelerate the motor
  for (speed = 255; speed >= 0; speed--)
  {
    // set the new speed
    analogWrite(motorPin, speed);
    // delay between speed steps
    delay(delayTime);
  }
}


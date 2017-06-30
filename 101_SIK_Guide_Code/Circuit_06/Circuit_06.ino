/*
  SparkFun Inventor's Kit
  Example sketch 06

  SPDT Switch

  Use a Single Pole Double Throw Switch (SPDT) to select an LED to blink

  This sketch was written by SparkFun Electronics,
  with lots of help from the Arduino community.
  This code is completely free for any use.
  Visit http://learn.sparkfun.com/products/2 for SIK information.
  Visit http://www.arduino.cc to learn about the Arduino.
*/


// Create constants for the pins we will be using
const int switchPin = 3;
const int led1Pin = 12;
const int led2Pin =  13;


void setup()
{
  // Set up the switch pins to be an input:
  pinMode(switchPin, INPUT);

  // Set up the LED pins to be an output:
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
}


void loop()
{
  // variables to hold the switch state
  int switchVal;

  // Since a switch has only two states, either HIGH (3.3V)
  // or LOW (GND) there is now way for you to have a floating point situation so there       //is no need for a pull-down resistor.

  //store the switch value to the switchVal variable
  switchVal = digitalRead(switchPin);

  //if switchVal is HIGH blink led1Pin
  if (switchVal == HIGH)
  {
    digitalWrite(led1Pin, HIGH);
    delay(500);
    digitalWrite(led1Pin, LOW);
    delay(500);
  }
  //else blink led2Pin
  else
  {
    digitalWrite(led2Pin, HIGH);
    delay(500);
    digitalWrite(led2Pin, LOW);
    delay(500);
  }
}


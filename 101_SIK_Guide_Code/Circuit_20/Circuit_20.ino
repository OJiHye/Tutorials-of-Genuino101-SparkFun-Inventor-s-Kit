/*
  SparkFun Inventor's Kit
  Example sketch 20

  DISPLAYING THE DATE AND TIME

  This sketch reads the RTC data and prints it on the LCD screen

  This sketch was written by SparkFun Electronics,
  with lots of help from the Arduino community.
  This code is completely free for any use.
  Visit http://learn.sparkfun.com/products/2 for SIK information.
  Visit http://www.arduino.cc to learn about the Arduino.
*/

//include the CurieTime Library
#include <CurieTime.h>
#include <LiquidCrystal.h>

//instantiate the lcd
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  //start lcd at 16 x 2
  lcd.begin(16, 2);

  //clear the lcd
  lcd.clear();

  //set time to 1:35:24 on April 4th, 2016. Please change to your time / date
  setTime(1, 35, 24, 4, 10, 2016);
}

void loop()
{
  //create a character array of 16 characters for the time
  char clockTime[16];
  //use sprintf to create a time string of the hour, minte and seconds
  sprintf(clockTime, "    %2d:%2d:%2d    ", hour(), minute(), second());

  //create a character array of 15 characters for the date
  char dateTime[16];
  //use sprintf to create a date string from month, day and year
  sprintf(dateTime, "   %2d/%2d/%4d   ", month(), day(), year());

  //set cursor to column 0, row 0
  lcd.setCursor(0, 0);
  //print the date string over lcd
  lcd.print(dateTime);
  //set cursor to column 0, row 1
  lcd.setCursor(0, 1);
  //print the time string over lcd
  lcd.print(clockTime);
}


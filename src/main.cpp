#include <Arduino.h>

// program to measure the speed of a ball using two IR sensors

// IR sensor pins
const int IR1 = 11;
const int IR2 = 8;

// variables to store the time when the ball passes the sensors
unsigned long t1 = 0;
unsigned long t2 = 0;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);

  // set the IR sensor pins as input
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  // read the IR sensor pins
  int ir1 = digitalRead(IR1);
  int ir2 = digitalRead(IR2);

  // check if the ball has passed the first sensor

  if (ir1 == LOW)
  {
    // store the time when the ball passes the first sensor
    t1 = millis();
  }

  // read the IR sensor pins

  // check if the ball has passed the second sensor

  if (ir2 == LOW)
  {
    // store the time when the ball passes the second sensor
    t2 = millis();

    // calculate the speed of the ball
    float speed = 0.1 / ((t2 - t1) / 1000.0);

    // print the speed of the ball
    Serial.print(speed);
    Serial.println(" m/s");

    // clear
    t1 = 0;
    t2 = 0;

    // wait for 1 second
    delay(1000);
  }

  // calculate the speed of the ball
}
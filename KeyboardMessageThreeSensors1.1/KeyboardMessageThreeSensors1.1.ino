#include "Keyboard.h"
#define THRESHOLD 750

const int power1 = 10;              // auxilary 3.3v power for sensor 1
const int power2 = 6;               // auxilary 3.3v power for sensor 2
const int power3 = 8;               // auxilary 3.3v power for sensor 3
 
const int buttonPin1 = 13;          // input pin for front cup

const int buttonPin2 = 12;          // input pin for middle cup 1
const int buttonPin3 = 11;          // input pin for middle cup 2

const int buttonPin4 = 10;          // input pin for back cup 1
const int buttonPin5 = 9;           // input pin for back cup 2
const int buttonPin6 = 7;           // input pin for back cup 3

const int sensorPin1 = A3;          // input from sensor 1
const int sensorPin2 = A4;          // input from sensor 2
const int sensorPin3 = A5;          // input from sensor 3


int previousSensorState1 = HIGH;   
int previousSensorState2 = HIGH;   
int previousSensorState3 = HIGH;     

int sensorState1;
int sensorState2;
int sensorState3;


int val1;
int val2;
int val3;

void setup() {
  //set pinMode for power pins
  pinMode(power1, OUTPUT);
  pinMode(power2, OUTPUT);
  pinMode(power3, OUTPUT);
  
  //Write Power pins High to give 3.3v to all IR Transmitters
  digitalWrite(power1,HIGH);
  digitalWrite(power2,HIGH);
  digitalWrite(power3,HIGH);
  
  //set pinMode for IR Sensors
  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);
  pinMode(sensorPin3, INPUT);

  
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  //Read the IR sensor values
  val1 = analogRead(sensorPin1);
  val2 = analogRead(sensorPin2);
  val3 = analogRead(sensorPin3);

  //Set state based on analog IR Sensor Threshold
  if (val1 < THRESHOLD)
  {
    sensorState1 = HIGH;
  }
 if (val2 < THRESHOLD)
  {
    sensorState2 = HIGH;
  }
 if (val3 < THRESHOLD)
  {
    sensorState3 = HIGH;
  }
 
  // if the button state has changed,
  if ((sensorState1 != previousSensorState1)
      // and it's currently pressed:
      && (sensorState1 == HIGH)) {
    // type out a message
    Keyboard.println("CUP_1_SCORED");
  }
  if ((sensorState2 != previousSensorState2)
      // and it's currently pressed:
      && (sensorState2 == HIGH)) {
    // type out a message
    Keyboard.println("CUP_2_SCORED");
  }
  if ((sensorState3 != previousSensorState3)
      // and it's currently pressed:
      && (sensorState3 == HIGH)) {
    // type out a message
    Keyboard.println("CUP_3_SCORED");
  }
 
  // save the current button state for comparison next time:
  previousSensorState1 = sensorState1;
  previousSensorState2 = sensorState2;
  previousSensorState3 = sensorState3;
  
}

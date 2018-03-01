/******************************************************************************
Heart_Rate_Display.ino
Demo Program for AD8232 Heart Rate sensor.
Casey Kuhns @ SparkFun Electronics
6/27/2014
https://github.com/sparkfun/AD8232_Heart_Rate_Monitor

The AD8232 Heart Rate sensor is a low cost EKG/ECG sensor.  This example shows
how to create an ECG with real time display.  The display is using Processing.
This sketch is based heavily on the Graphing Tutorial provided in the Arduino
IDE. http://www.arduino.cc/en/Tutorial/Graph

Resources:
This program requires a Processing sketch to view the data in real time.

Development environment specifics:
	IDE: Arduino 1.0.5
	Hardware Platform: Arduino Pro 3.3V/8MHz
	AD8232 Heart Monitor Version: 1.0

This code is beerware. If you see me (or any other SparkFun employee) at the
local pub, and you've found our code helpful, please buy us a round!

Distributed as-is; no warranty is given.
******************************************************************************/
 int analogI[6];
 int val[6];
 int h;
 
  
void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  pinMode(10, INPUT); // Setup for leads off detection LO +
  pinMode(11, INPUT); // Setup for leads off detection LO -
  pinMode(2, INPUT);
  for(int i=0;i<6;i++)
  {
    analogI[i] = i+1;
    val[i] = 0;     
    pinMode(analogI[i], INPUT);    
  }
  
  // begin sending over serial port
  Serial.begin(9600);
}

void loop() {
  int sensorState = digitalRead(2);
  //Serial.println(sensorState);
  
  if((digitalRead(10) == 1)||(digitalRead(11) == 1)){
    
  }
  else{
    // send the value of analog input 0:
      h = analogRead(A0);
  }
  //Wait for a bit to keep serial data from saturating
  delay(1000);
  for(int i=0;i<6;i++)
  {
    val[i] = analogRead(analogI[i]);
  }

  // print out value over the serial port
  /*
  for(int i=0;i<6;i++)
  {
    Serial.println("Muscle");
    Serial.println(10000 + i + 1); //prefix
    Serial.println(val[i]);
    Serial.println(10010); //end signal
    Serial.println("Heart");
    Serial.println(h);
    Serial.println("Piezo");
    Serial.println(sensorState);
    
  }
  */

  Serial.print(h);
  Serial.print(',');
  Serial.println(sensorState);
  // wait for a bit to not overload the port
  delay(500);
}


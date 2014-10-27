/****************************************************************
AmbientLightInterrupt.ino
APDS-9960 RGB and Gesture Sesnor
Shawn Hymel @ SparkFun Electronics
October 24, 2014
https://github.com/sparkfun/APDS-9960_RGB_and_Gesture_Sensor

Tests the ambient light interrupt abilities of the APDS-9960.
Configures the APDS-9960 over I2C and waits for an external
interrupt based on high or low light conditions.

Hardware Connections:

IMPORTANT: The APDS-9960 can only accept 3.3V!
 
 Arduino Pin  APDS-9960 Board  Function
 
 3.3V         VCC              Power
 GND          GND              Ground
 A4           SDA              I2C Data
 A5           SCL              I2C Clock
 2            INT              Interrupt

Resources:
Include Wire.h and SFE_APDS-9960.h

Development environment specifics:
Written in Arduino 1.0.5
Tested with SparkFun Arduino Pro Mini 3.3V

This code is beerware; if you see me (or any other SparkFun 
employee) at the local, and you've found our code helpful, please
buy us a round!

Distributed as-is; no warranty is given.
****************************************************************/

#include <Wire.h>
#include <SFE_APDS9960.h>

// Pins
#define APDS9960_INT    2 // Needs to be an interrupt pin

// Constants
#define LIGHT_INT_HIGH  500  // High light level for interrupt
#define LIGHT_INT_LOW   10   // Low light level for interrupt

// Global variables
SFE_APDS9960 apds = SFE_APDS9960();
int isr_flag = 0;

void setup() {
  
  // Initialize Serial port
  Serial.begin(115200);
  Serial.println();
  Serial.println(F("--------------------------------"));
  Serial.println(F("SparkFun APDS-9960 - GestureTest"));
  Serial.println(F("--------------------------------"));
  
  
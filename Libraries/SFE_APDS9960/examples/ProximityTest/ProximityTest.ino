/****************************************************************
ProximityTest.ino
APDS-9960 RGB and Gesture Sesnor
Shawn Hymel @ SparkFun Electronics
May 30, 2014
https://github.com/sparkfun/APDS-9960_RGB_and_Gesture_Sensor

Tests the proximity sensing abilities of the APDS-9960.
Configures the APDS-9960 over I2C and waits for a proximity
interrupt. Displays the proximity sensor value on a serial
console.

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

// Global Variables
SFE_APDS9960 apds = SFE_APDS9960();

void setup() {

  // Initialize Serial port
  Serial.begin(115200);
  Serial.println();
  Serial.println(F("----------------------------------"));
  Serial.println(F("SparkFun APDS-9960 - ProximityTest"));
  Serial.println(F("----------------------------------"));
  
  // Initialize interrupt service routine
  attachInterrupt(0, interruptRoutine, FALLING);

  // Initialize APDS-9960 (configure I2C and initial values)
  if ( apds.init() ) {
    Serial.println(F("APDS-9960 initialization complete"));
  } else {
    Serial.println(F("Something went wrong during APDS-9960 init!"));
  }
  
  //***TEST***
  uint8_t t;
  uint16_t u;
  apds.wireReadDataByte(APDS9960_CONTROL, t);
  Serial.println(t, BIN);
  
  Serial.println("LDRIVE");
  t = apds.getLEDDrive();
  Serial.println(t);
  apds.setLEDDrive(1);
  t = apds.getLEDDrive();
  Serial.println(t);
  
  Serial.println("PGAIN");
  t = apds.getProxGain();
  Serial.println(t);
  apds.setProxGain(3);
  t = apds.getProxGain();
  Serial.println(t);
  
  Serial.println("AGAIN");
  t = apds.getAmbientLightGain();
  Serial.println(t);
  apds.setAmbientLightGain(2);
  t = apds.getAmbientLightGain();
  Serial.println(t);
  
  apds.wireReadDataByte(APDS9960_CONTROL, t);
  Serial.println(t, BIN);
  
  Serial.println("PILT");
  t = apds.getProxIntLowThresh();
  Serial.println(t);
  apds.setProxIntLowThresh(5);
  t = apds.getProxIntLowThresh();
  Serial.println(t);

  Serial.println("PIHT");
  t = apds.getProxIntHighThresh();
  Serial.println(t);
  apds.setProxIntHighThresh(10);
  t = apds.getProxIntHighThresh();
  Serial.println(t);
  
  Serial.println("AILT");
  u = apds.getAmbientLightIntLowThresh();
  Serial.println(u, HEX);
  apds.setAmbientLightIntLowThresh(0x1234);
  u = apds.getAmbientLightIntLowThresh();
  Serial.println(u, HEX);
  
  Serial.println("AIHT");
  u = apds.getAmbientLightIntHighThresh();
  Serial.println(u, HEX);
  apds.setAmbientLightIntHighThresh(0xABCD);
  u = apds.getAmbientLightIntHighThresh();
  Serial.println(u, HEX);
  
  Serial.println("LED_BOOST");
  t = apds.getLEDBoost();
  Serial.println(t);
  apds.setLEDBoost(2);
  t = apds.getLEDBoost();
  Serial.println(t);
  
  Serial.println("PCMP");
  t = apds.getProxGainCompEnable();
  Serial.println(t);
  apds.setProxGainCompEnable(1);
  t = apds.getProxGainCompEnable();
  Serial.println(t);
  
  Serial.println("PROX_MASK");
  t = apds.getProxPhotoMask();
  Serial.println(t);
  apds.setProxPhotoMask(0x09);
  t = apds.getProxPhotoMask();
  Serial.println(t, HEX);
  
  Serial.println("GENTH");
  t = apds.getGestureEnterThresh();
  Serial.println(t);
  apds.setGestureEnterThresh(55);
  t = apds.getGestureEnterThresh();
  Serial.println(t);
  
  Serial.println("GEXTH");
  t = apds.getGestureExitThresh();
  Serial.println(t);
  apds.setGestureExitThresh(25);
  t = apds.getGestureExitThresh();
  Serial.println(t);
  
  Serial.println("GGAIN");
  t = apds.getGestureGain();
  Serial.println(t);
  apds.setGestureGain(3);
  t = apds.getGestureGain();
  Serial.println(t);
  
  Serial.println("GLDRIVE");
  t = apds.getGestureLEDDrive();
  Serial.println(t);
  apds.setGestureLEDDrive(3);
  t = apds.getGestureLEDDrive();
  Serial.println(t);
  
  Serial.println("GWTIME");
  t = apds.getGestureWaitTime();
  Serial.println(t);
  apds.setGestureWaitTime(7);
  t = apds.getGestureWaitTime();
  Serial.println(t);
  
  Serial.println("GIEN");
  t = apds.getGestureIntEnable();
  Serial.println(t);
  apds.setGestureIntEnable(1);
  t = apds.getGestureIntEnable();
  Serial.println(t);
  
  Serial.println("GMODE");
  t = apds.getGestureMode();
  Serial.println(t);
  apds.setGestureMode(1);
  t = apds.getGestureMode();
  Serial.println(t);
}

void loop() {

}

void interruptRoutine() {

}
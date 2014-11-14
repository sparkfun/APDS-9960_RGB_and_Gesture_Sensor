SparkFun_APDS9960
==============

Arduino library for the [Avago APDS-9960 Breakout Board](https://www.sparkfun.com/products/12787)

Version
-------

**v1.1**

Known Issues
------------

Getting Started
---------------

* Download the Git repository as a ZIP ("Download ZIP" button)
* Unzip
* Copy the entire library directory (SparkFun_APDS9960) to \<Arduino installation directory\>/libraries
* Open the Arduino program
* Select File -> Examples -> SparkFun_APDS9960 -> GestureTest
* Plug in your Arduino and APDS-9960 with the following connections

| Arduino Pin | APDS-9960 Board | Function |
|---|---|---| 
| 3.3V | VCC | Power |
| GND | GND | Ground |
| A4 | SDA | I2C Data |
| A5 | SCL | I2C Clock |
| 2 | INT | Interrupt |

* Go to Tools -> Board and select your Arduino board
* Go to Tools -> Serial Port and select the COM port of your Arduino board
* Click "Upload"
* Go to Tools -> Serial Monitor
* Ensure the baud rate is set at 9600 baud
* Swipe your hand over the sensor in various directions!

Version History
---------------

**v1.1**

* Updated GestureTest demo to not freeze with fast swipes

**v1.0**

* Initial release
* Ambient and RGB light sensing implemented
* Ambient light interrupts working
* Proximity sensing implemented
* Proximity interrupts working
* Gesture (UP, DOWN, LEFT, RIGHT, NEAR, FAR) sensing implemented

License
-------

This code is beerware; if you see me (or any other SparkFun employee) at the local, and you've found our code helpful, please buy us a round!

Distributed as-is; no warranty is given.
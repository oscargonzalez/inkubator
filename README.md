Inkubator
=========
Oscar Gonzalez - April 2013

Simple Arduino based egg incubator

Description of the operation
============================
Chicken eggs need to be turned a minimum of twice a day for 18 days then not turned for the last 3 days. The temperature must be constant and controlled between 37 and 38ºC day period. 
In addition, for the first 18 days the best circulated air humidity is 50 to 55 percent relative humidity then raised for last 3 days to 60 to 65 percent.

The Inkubator
=============
The system uses three custom made boards to control de whole thing. You can get the boards at batchpcb.com

- Controller board (https://www.batchpcb.com/pcbs/110949)
- Power board (https://www.batchpcb.com/pcbs/110958)
- LCD board (https://www.batchpcb.com/pcbs/110955)

Controller board
----------------
The main controller board is based on the ATMega328 microcontroller using the Arduino bootloader to load code into the chip.

Power board
-----------
Control of two relays to power on heating and air humidifier. Also the board controls air blowing fan and have the main power input.

LCD board
---------
Used to connect a uLCD-43Pt LCD serial display (used in serial command mode). Also have four push buttons to control the main menu.


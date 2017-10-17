#!/bin/bash
avr-g++ -std=c++11 -mmcu=attiny13 -Os -Wall main.cpp

if [ $? -eq 0 ]; then
  avr-size -C --mcu=attiny13 a.out
  objcopy -S -O ihex a.out hw.hex
  sudo avrdude -p t13 -c usbtiny -U flash:w:hw.hex:i
fi

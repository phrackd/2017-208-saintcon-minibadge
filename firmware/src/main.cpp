/*******************************************************************************
 * SAINTCON 208 MiniBadge
 ******************************************************************************/

#define F_CPU 800000UL // 1Mhz

#include <avr/io.h>
#include <util/delay.h>
uint8_t repeat = 120;
// Write to pins
void clear_and_enable(uint8_t vcc, uint8_t gnd, uint8_t repeat)
{
  for (uint8_t i = 0; i < repeat; i++)
  {
    // Clear pins and set up transition
    // Datasheet: 10.2.3
    PORTB = 0x00;
    DDRB = 0xFF;
    _delay_ms(1);
    // Set Direction
    DDRB = 0x00 | (1 << vcc) | (1 << gnd);
    // Set High
    PORTB = 0x00 | (1 << vcc);
    _delay_ms(1);
  }
}

// Main
int main(void)
{
    while (true)
    {
      clear_and_enable(PB0, PB1, repeat);  // LED 1
      clear_and_enable(PB1, PB0, repeat);  // LED 2
      clear_and_enable(PB1, PB2, repeat);  // LED 3
      clear_and_enable(PB2, PB1, repeat);  // LED 4
      clear_and_enable(PB2, PB3, repeat);  // LED 5
      clear_and_enable(PB3, PB2, repeat);  // LED 6
      clear_and_enable(PB3, PB4, repeat);  // LED 7
      clear_and_enable(PB4, PB3, repeat);  // LED 8
      clear_and_enable(PB0, PB2, repeat);  // LED 9
      clear_and_enable(PB2, PB0, repeat);  // LED 10
      clear_and_enable(PB1, PB3, repeat);  // LED 11
      clear_and_enable(PB3, PB1, repeat);  // LED 12
      clear_and_enable(PB2, PB4, repeat);  // LED 13
      clear_and_enable(PB4, PB2, repeat);  // LED 14
      clear_and_enable(PB0, PB3, repeat);  // LED 15
      clear_and_enable(PB3, PB0, repeat);  // LED 16
      clear_and_enable(PB1, PB4, repeat);  // LED 17
      clear_and_enable(PB4, PB1, repeat);  // LED 18
    }
    return(0);
}

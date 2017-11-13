// Quick Demo of light sensor

// ------- Preamble -------- //
#include <avr/io.h>
#include <util/delay.h>
#include "pinDefines.h"
#include "USART.h"
#include "a4988.h"

#define cB PB2
#define ccB PB1

// -------- Functions --------- //
static inline void initADC0(void) {
  ADMUX |= (1 << REFS0);                  /* reference voltage on AVCC */
  ADMUX |= (1 << ADLAR);     /* left-adjust result, return only 8 bits */
  ADCSRA |= (1 << ADPS2);                   /* ADC clock prescaler /16 */
  ADCSRA |= (1 << ADEN);                                 /* enable ADC */
}

int main(void) {

  // -------- Inits --------- //
  uint8_t pAdcValue;
  uint8_t adcValue;
  PORTB |= _BV(cB) | _BV(ccB);
  initUSART();
  initADC0();
  initStepper();

  // ------ Event loop ------ //
  while (1) {

    ADCSRA |= (1 << ADSC);                     /* start ADC conversion */
    loop_until_bit_is_clear(ADCSRA, ADSC);          /* wait until done */
    adcValue = ADCH;                                     /* read ADC in */
    while(bit_is_clear(PINB, cB)){
	  pulseC(200);
	}
    while(bit_is_clear(PINB, ccB)){
	  pulseCC(200);
	}
    _delay_ms(15);
  }                                                  /* End event loop */
  return 0;                            /* This line is never reached */
}

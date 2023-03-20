#ifndef _ASNX_LED_H_
#define _ASNX_LED_H_

/***** INCLUDES *******************************************************/
/*** STD ***/
#include <stdint.h>
#include <stddef.h>
/*** ASNX LIB ***/
#include "hw/hw.h"


/***** DEFINES ********************************************************/
/*! User LEDs DDR register */
#define LED_DDR                             DDRD
/*! User LEDs PORT register */
#define LED_PORT                            PORTD
/*! User LEDs PIN register */
#define LED_PIN                             PIND
/*! User LED1 portpin index */
#define LED1_GPIO                           PD5
/*! User LED2 portpin index */
#define LED2_GPIO                           PD4


/***** FUNCTION PROTOTYPES ********************************************/
void led_init(void);
void led1_low(void);
void led2_low(void);
void led1_high(void);
void led2_high(void);
void led1_toggle(void);
void led2_toggle(void);


#endif // _ASNX_LED_H_
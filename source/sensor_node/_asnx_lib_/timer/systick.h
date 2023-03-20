#ifndef _ASNX_SYSTICK_H_
#define _ASNX_SYSTICK_H_

/***** INCLUDES *******************************************************/
/*** STD ***/
#include <stdint.h>
#include <stddef.h>
/*** ASNX LIB ***/
#include "timer/timer.h"


/***** STRUCTURES *****************************************************/
/*!
 * A structure to store the elapsed time of the systick timer.
 */
typedef struct {
    uint16_t msec;      /**< Elapsed milliseconds (ms) */
    uint8_t sec;        /**< Elapsed seconds (sec) */
    uint8_t min;        /**< Elapsed minutes (min) */
    uint8_t hour;       /**< Elapsed hours (hour) */
    uint16_t day;       /**< Elapsed days (day) */
} systick_t;


/***** GLOBAL VARIABLES ***********************************************/
/*! Global struct for the elapsed time of the systick timer */
extern systick_t systime;


/***** FUNCTION PROTOTYPES ********************************************/
/* General */
void systick_init(void);
void systick_deinit(void);
void systick_reset(void);
/* Get time */
uint64_t systick_get_ticks(void);
uint16_t systick_get_msec(void);
uint8_t systick_get_sec(void);
uint8_t systick_get_min(void);
uint8_t systick_get_hour(void);
uint16_t systick_get_day(void);
/* Callbacks */
void systick_set_callback_msec(void (*func)(void));
void systick_set_callback_sec(void (*func)(void));
void systick_set_callback_min(void (*func)(void));
void systick_set_callback_hour(void (*func)(void));
void systick_clear_callback_msec(void);
void systick_clear_callback_sec(void);
void systick_clear_callback_min(void);
void systick_clear_callback_hour(void);


#endif // _ASNX_SYSTICK_H_

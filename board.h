/*
 function pattern
 function name   : should be using underscore
 function return : should be specify with return type and end of the function should return valid return value
 function arg    : should be common for all other uses
*/

/*
 comment pattern
 comment pattern : should be always in block comment pattern other are not allowed
                   every line should have a description
*/

#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include"ADC.h"
#include "PIC24F1XX_CORE.h"


#define ADC_CHANNLE0  PIC24F1XX_ADC0

/** \brief
 * Common structure for the store driver handler
 */

typedef struct common_strcut__{
    ADC_Handler handler;            //it will hold the ADC handler
}common_strcut;

extern common_strcut g_common_strcut;

/*driver initialization function*/
void driver_init(void);


#endif // BOARD_H_INCLUDED

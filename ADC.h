#ifndef ADC_H_INCLUDED
#define ADC_H_INCLUDED
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/*
   forward declaration for the ADC handler
*/
typedef struct ADC_Config__ *ADC_Handler;

typedef struct ADC_Param__{
   bool m_allocated;
}ADC_Param;
/*
  function pointer of ADC_OPEN
  return : will return ADC_Config structure
*/

typedef ADC_Handler (*ADC_OPEN)(ADC_Handler handler, ADC_Param *param);
typedef void (*ADC_INIT)(ADC_Handler handler);
typedef uint16_t (*ADC_SAMPLE)(ADC_Handler handler, uint16_t *value);

/*
   ADC Function pointer table
*/
typedef struct ADC_FUNCTION__{
   ADC_OPEN openFxn;
   ADC_INIT initFxn;
   ADC_SAMPLE sampleFxn;
}ADC_FUNCTION;


typedef struct ADC_Config__{
  ADC_FUNCTION const *fxnTable;  //it will hold the function table address
  void *Object;

}ADC_Config;


/** \brief
 * ADC_OPEN for user API
 * \param : index of ADC instance
 * \param : to store default param to param arg
 * \return : success on ADC_Handler
 *
 */

extern ADC_Handler adc_open(uint8_t adc_indx, ADC_Param *param);
extern void adc_default_init(ADC_Param *param);
extern void adc_init(void);
extern uint16_t readADCSample(ADC_Handler handler, uint16_t *value);

#endif // ADC_H_INCLUDED

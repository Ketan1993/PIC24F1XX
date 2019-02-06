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

/*
   ADC Function pointer table
*/
typedef struct ADC_FUNCTION__{
   ADC_OPEN openFxn;
   ADC_INIT initFxn;
}ADC_FUNCTION;


typedef struct ADC_Config__{
  ADC_FUNCTION const *fxnTable;  //it will hold the function table address
  void *Object;

}ADC_Config;

extern ADC_Handler adc_open(uint8_t adc_indx, ADC_Param *param);
extern void adc_default_init(ADC_Param *param);
extern void adc_init(void);

#endif // ADC_H_INCLUDED

#include"ADC.h"
#include<stdio.h>

extern const _u8 ADC_count;
extern const ADC_Config ADC_Instance[];

const ADC_Param ADC_defualtParam = {
    .m_allocated = true
};

ADC_Handler adc_open(_u8 adc_indx, ADC_Param *param)
{
    ADC_Handler handler = NULL;
   if(adc_indx > ADC_count)
   {
        printf("Index is out of the range\n\r");
        return NULL;
   }


   if(param == NULL)
   {
       param = (ADC_Param*) &ADC_defualtParam;
   }
   handler = (ADC_Handler)&ADC_Instance[adc_indx];
   handler = handler->fxnTable->openFxn(handler, param);

   return (handler);
}


void adc_init(void)
{
   _u8 count = 0;
   for(count = 0; count < ADC_count; count++)
   {
       ADC_Instance[count].fxnTable->initFxn((ADC_Handler)&(ADC_Instance[count]));
   }
}

void adc_default_init(ADC_Param *param)
{
   *param = ADC_defualtParam;
}
_u16 readADCSample(ADC_Handler handler, _u16 *value)
{
  return (handler->fxnTable->sampleFxn(handler, value));
}

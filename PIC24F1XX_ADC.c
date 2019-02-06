#include"ADC.h"
#include "PIC24F1XX_ADC.h"


//forward declaration for the ADC FUNCTION POINTER
ADC_Handler PIC24F1XX_ADC_OPEN(ADC_Handler handler, ADC_Param *param);
void PIC24F1XX_ADC_INIT(ADC_Handler handler);
uint16_t PIC24F1XX_ADC_SAMPLE(ADC_Handler handler, uint16_t *value);


const ADC_FUNCTION ADC_TABLE = {
    PIC24F1XX_ADC_OPEN,
    PIC24F1XX_ADC_INIT,
    PIC24F1XX_ADC_SAMPLE
};



ADC_Handler PIC24F1XX_ADC_OPEN(ADC_Handler handler, ADC_Param *param)
{
   ADC_Object *object = handler->Object;

   if(object->isOpen)
   {
       printf("ADC Is Already Open\n\r");
       return false;
   }
   object->isOpen = true;
   printf("ADC Open successfully\n\r");
   return (handler);
}


void PIC24F1XX_ADC_INIT(ADC_Handler handler)
{
   ((ADC_Object *)handler->Object)->isOpen = false;
}


uint16_t PIC24F1XX_ADC_SAMPLE(ADC_Handler handler, uint16_t *value)
{
   *value = 1;
    return true;
}

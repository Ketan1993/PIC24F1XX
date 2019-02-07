#include"PIC24F1XX_CORE.h"


/*=======================ADC============================== */
#include"ADC.h"
#include"PIC24F1XX_ADC.h"

ADC_Object PIC24F1XX_ADCObject[PIC24F1XX_TOTAL_ADC];

const ADC_Config ADC_Instance[PIC24F1XX_TOTAL_ADC] = {
 { // ADC_INSTANCE
     .fxnTable = &ADC_TABLE,
     .Object = &PIC24F1XX_ADCObject[PIC24F1XX_ADC0]
 }
};
const _u8 ADC_count = PIC24F1XX_TOTAL_ADC;

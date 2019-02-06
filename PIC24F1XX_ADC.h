#ifndef PIC24F1XX_ADC_H_INCLUDED
#define PIC24F1XX_ADC_H_INCLUDED
#include<stdbool.h>

extern const ADC_FUNCTION ADC_TABLE;

typedef struct ADC_Object_{
    bool isOpen;
}ADC_Object;

#endif // PIC24F1XX_ADC_H_INCLUDED

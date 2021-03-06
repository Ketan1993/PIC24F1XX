#ifndef ADC_H_INCLUDED
#define ADC_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>
#include"data_type.h"

/*
   forward declaration for the ADC handler
*/
typedef struct ADC_Config__ *ADC_Handler;

typedef struct ADC_Param__{
   bool m_allocated;
}ADC_Param;


/** \brief
 *  OPEN ADC driver
 * \param : handler of the ADC_instance
 * \param : param as a default argument
 * \return : return ADC Handler
 *
 */

typedef ADC_Handler (*ADC_OPEN)(ADC_Handler handler, ADC_Param *param);


/** \brief
 *  ADC_INIT
 * \param : ADC handler
 * \return : return with ADC object
 *
 */

typedef void (*ADC_INIT)(ADC_Handler handler);


/** \brief
 *  ADC_READING_SAMPLE
 * \param : ADC_Handler
 * \param : Return value
 * \return : true on success otherwise false
 *
 */

typedef _u16 (*ADC_SAMPLE)(ADC_Handler handler, _u16 *value);

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

extern ADC_Handler adc_open(_u8 adc_indx, ADC_Param *param);

/*!
 *  @brief  Function to initialize the ADC_Params struct to its defaults
 *
 *  @param  params      An pointer to ADC_Params structure for
 *                      initialization
 *
 *  Defaults values are:
 *      m_allocated = true
 */

extern void adc_default_init(ADC_Param *param);
extern void adc_init(void);
extern _u16 readADCSample(ADC_Handler handler, _u16 *value);

#endif // ADC_H_INCLUDED

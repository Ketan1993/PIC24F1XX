#include"board.h"
#include "ADC.h"

common_strcut g_common_strcut;
ADC_Param param;

static void boardInit(void)
{
    adc_init();         //initialize core ADC driver
}
static void open_driverAPI(void)
{
  adc_default_init(&param);        //initialize user ADC driver, should be call once in while
  g_common_strcut.handler = adc_open(ADC_CHANNLE0, &param);  //return ADC Handle will store as pointer in structure
}
void driver_init(void)
{
    _u16 number = 0;
    boardInit();      // creating board initialize
    open_driverAPI();
    readADCSample(g_common_strcut.handler, &number);
    printf("%d", number);

}

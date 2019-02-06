#include"board.h"
#include "ADC.h"

common_strcut g_common_strcut;
ADC_Param param;

static void boardInit(void)
{
    adc_init();
}
void driver_init(void)
{
    boardInit();
    adc_default_init(&param);
    g_common_strcut.handler = adc_open(0, &param);
}

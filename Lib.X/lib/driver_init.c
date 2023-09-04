#include "driver_init.h"
#include "../pic24fj256.h"

struct async_uart_descriptor async_uart1;
struct async_uart_descriptor async_uart2;
struct async_uart_descriptor async_uart3;

#define UART2_BUFFER_SIZE           250
uint8_t uart2Buffer[UART2_BUFFER_SIZE] = {0};

void UART1_Initialization(void) {
    //initialize the 
    async_uart_initialization(&async_uart2, UART2B, uart2Buffer, UART2_BUFFER_SIZE);
}

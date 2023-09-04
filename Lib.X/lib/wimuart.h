/* 
 * File:   wimuart.h
 * Author: Admin
 *
 * Created on September 5, 2022, 6:51 PM
 */

#ifndef WIMUART_H
#define	WIMUART_H

#include "wimbus.h"

#ifdef	__cplusplus
extern "C" {
#endif


#define DIVIDER_FACTOR                   4
#define UBRG_VALUE(frq, BAUD_RATE)           (((frq / BAUD_RATE) / DIVIDER_FACTOR) - 1)

#define TOTAL_MAX_UART                       3
#define MAX_UART_BAUDRATE                    (115200)

    typedef enum _UART_STOPbit {
        ONE_STOP_BIT = 0,
        TWO_STOP_BIT = 1
    } UART_STOPbits;

    typedef enum _UART_PARITY {
        EIGHT_BIT_PARITY = 0X00, //8 bit no parity
        EVEN_PARITY = 0X01, //8 bit even parity
        OLD_PARITY = 0X02, //8 bit odd parity
        NINE_BIT_PARITY = 0X03//9 bit no parity
    } UART_PARITYbits;

    typedef WIMBus *(WIMSerialUARTCreate_) (BusInstace inst, BusBaudateRate speed, UART_STOPbits stopBits, UART_PARITYbits parity,
            WMBusTimeoutMs readTimeoutMS, WMBusTimeoutMs watchdogTimeoutMS);
    WIMSerialUARTCreate_ WIMSerialUARTCreate;

#ifdef	__cplusplus
}
#endif

#endif	/* WIMUART_H */


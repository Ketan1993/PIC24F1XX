/* 
 * File:   driver_init.h
 * Author: Admin
 *
 * Created on September 6, 2022, 10:37 AM
 */

#ifndef DRIVER_INIT_H
#define	DRIVER_INIT_H

#include "async_uart.h"
#include "../common_def.h"

#ifdef	__cplusplus
extern "C" {
#endif


    extern struct async_uart_descriptor async_uart1;
    extern struct async_uart_descriptor async_uart2;
    extern struct async_uart_descriptor async_uart3;

    void UART1_Initialization(void);

#ifdef	__cplusplus
}
#endif

#endif	/* DRIVER_INIT_H */


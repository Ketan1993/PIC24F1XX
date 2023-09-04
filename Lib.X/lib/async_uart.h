/* 
 * File:   async_uart.h
 * Author: Admin
 *
 * Created on September 6, 2022, 10:29 AM
 */

#ifndef ASYNC_UART_H
#define	ASYNC_UART_H

#include <stddef.h>
#include "io.h"
#include "ringbuffer.h"
#include "../hal/hal_uart.h"

#ifdef	__cplusplus
extern "C" {
#endif

#define CONTAINER_OF(ptr, type, field_name) ((type *)(((uint8_t *)ptr) - offsetof(type, field_name)))

    //forward declaration

    struct async_uart_descriptor;

    typedef void (*usart_cb_t)(const struct async_uart_descriptor * const descr);

    enum usart_async_callback_type {
        USART_ASYNC_RXC_CB, USART_ASYNC_TXC_CB, USART_ASYNC_ERROR_CB
    };

    struct usart_async_callbacks {
        usart_cb_t tx_done;
        usart_cb_t rx_done;
        usart_cb_t error;
    };

    struct async_uart_descriptor {
        struct io_descriptor io;
        struct _uart_async_device device;
        struct usart_async_callbacks uart_cb;
        struct ringbuffer rb;
        uint32_t stat;
        uint16_t tx_por;
        uint8_t *tx_buffer;
        uint16_t tx_buffer_length;
    };

    int async_uart_initialization(struct async_uart_descriptor * const desc, void *const hw, uint8_t * const buffer, uint32_t size);

    int get_async_uart_serial_descriptor(struct async_uart_descriptor * const desc, struct io_descriptor **io);

    int async_uart_set_parity(struct async_uart_descriptor * const desc, unsigned int mask);

    int async_uart_set_stop_bits(struct async_uart_descriptor * const desc, unsigned int mask);

    int async_uart_enable(struct async_uart_descriptor * const desc);

    int async_uart_set_clock_speed(struct async_uart_descriptor * const desc, unsigned int speed);

    int usart_async_register_callback(struct async_uart_descriptor * const desc, const enum usart_async_callback_type type, usart_cb_t cb);
    
    int async_uart_buffer_flush(struct async_uart_descriptor * const desc);
    
#ifdef	__cplusplus
}
#endif

#endif	/* ASYNC_UART_H */


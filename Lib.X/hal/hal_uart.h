/* 
 * File:   hal_uart.h
 * Author: Admin
 *
 * Created on September 6, 2022, 11:19 AM
 */

#ifndef HAL_UART_H
#define	HAL_UART_H

#include "../pic24fj256.h"

#ifdef	__cplusplus
extern "C" {
#endif

    //forward declaration
    struct _uart_async_device;

    struct _uart_async_device_callback {
        void (*tx_byte_sent)(struct _uart_async_device *device);
        void (*rx_done_cb)(struct _uart_async_device *device, unsigned char data);
        void (*tx_done_cb)(struct _uart_async_device *device);
        void (*error_cb)(struct _uart_async_device *device);
    };

    struct _uart_async_device {
        struct _uart_async_device_callback uart_cb;
        unsigned char instNum;
        void *hw;
    };

    int _async_uart_init(struct _uart_async_device * const device, void *const hw);
    int _async_uart_set_parity(struct _uart_async_device * const device, unsigned int mask);
    int _async_uart_set_stop_bits(struct _uart_async_device * const device, unsigned int mask);
    int _async_uart_set_clock_speed(struct _uart_async_device * const device, unsigned int speed);
    int _async_uart_write_data(struct _uart_async_device * const device, unsigned char data);
    int _async_uart_wait_byte_sent_status_clear(struct _uart_async_device * const device);
    int _async_uart_enable(struct _uart_async_device * const device);
    int _async_uart_TX_interrupt_enable(struct _uart_async_device * const device, unsigned char mask);
    int _async_uart_TX_interrupt_disable(struct _uart_async_device * const device, unsigned char mask);
    int _async_uart_TX_interrupt_flag_clear(struct _uart_async_device * const device, unsigned char mask);

    int _async_uart_RX_interrupt_enable(struct _uart_async_device * const device, unsigned char mask);
    int _async_uart_RX_interrupt_clear(struct _uart_async_device * const device, unsigned char mask);
    int _async_uart_RX_interrupt_flag_clear(struct _uart_async_device * const device, unsigned char mask);

#ifdef	__cplusplus
}
#endif

#endif	/* HAL_UART_H */


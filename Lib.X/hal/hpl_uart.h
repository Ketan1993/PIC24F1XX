/* 
 * File:   hpl_uart.h
 * Author: Admin
 *
 * Created on September 6, 2022, 1:00 PM
 */

#ifndef HPL_UART_H
#define	HPL_UART_H

#include "../pic24fj256.h"

#ifdef	__cplusplus
extern "C" {
#endif

    static inline void _uart_set_parity_bits(void *const hw, unsigned int mask) {
        ((UART_TypeDef*) hw)->uxmode |= mask;
    }

    static inline void _uart_set_stop_bits(void *const hw, unsigned int mask) {
        ((UART_TypeDef*) hw)->uxmode |= mask;
    }

    static inline void _uart_enable(void *const hw) {
        ((UART_TypeDef*) hw)->uxmode |= 0x8000;
        ((UART_TypeDef*) hw)->uxsta |= 0x0400;
    }

    static inline void _uart_clock_set(void *const hw, unsigned int speed) {
        ((UART_TypeDef*) hw)->uxbrg = speed;
    }

    static inline void _uart_data_write(void *const hw, unsigned char data) {
        ((UART_TypeDef*) hw)->uxtxreg = data;
    }

    static inline void _uart_data_sent_wait(void *const hw) {
        while ((((UART_TypeDef*) hw)->uxsta & (1 << 9)) != 0);
    }

    static inline unsigned char _uart_read_data(void *const hw) {
        return ((UART_TypeDef*) hw)->uxrxreg;
    }

    static inline bool _uart_get_status_register(void *const hw) {
        volatile uint16_t txstatus = ((UART_TypeDef*) hw)->uxsta;
        return (txstatus & 0x0E) ? true : false;
    }

    static inline void _uart_clear_error_bits(void *const hw, unsigned char mask) {
        ((UART_TypeDef*) hw)->uxsta &= ~mask;
    }

    static inline bool _uart_get_buffer_status(void *const hw) {
        return (((UART_TypeDef*) hw)->uxsta & 0x1) ? true : false;
    }


#ifdef	__cplusplus
}
#endif

#endif	/* HPL_UART_H */


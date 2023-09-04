/* 
 * File:   pic24fj256.h
 * Author: Admin
 *
 * Created on September 6, 2022, 11:41 AM
 */

#ifndef PIC24FJ256_H
#define	PIC24FJ256_H

#include <stdint.h>
#include <stdbool.h>
#include <xc.h>

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct {
        volatile uint16_t uxmode;
        volatile uint16_t uxsta;
        volatile uint16_t uxtxreg;
        volatile uint16_t uxrxreg;
        volatile uint16_t uxbrg;
    } UART_TypeDef;

#define UART1_BASE          (0x0398ul)
#define UART1B              ((UART_TypeDef *) UART1_BASE)

#define UART2_BASE          (0x03AEul)
#define UART2B              ((UART_TypeDef *) UART2_BASE)

#define UART3_BASE          (0x03C4ul)
#define UART3B              ((UART_TypeDef *) UART3_BASE)

    void SetUARTRXIE(unsigned index, unsigned value);
    void SetUARTRXIF(unsigned index, unsigned value);
    void SetUARTRXIP(unsigned index, unsigned value);
    
    void SetUARTTXIE(unsigned index, unsigned value);
    void SetUARTTXIF(unsigned index, unsigned value);
    void SetUARTTXIP(unsigned index, unsigned value);



#ifdef	__cplusplus
}
#endif

#endif	/* PIC24FJ256_H */


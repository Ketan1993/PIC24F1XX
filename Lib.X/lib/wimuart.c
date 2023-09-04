#include "wimuart.h"
#include "driver_init.h"
#include "ringbuffer.h"
#include "io.h"
#include "../log.h"
#include <xc.h>

#ifdef __DEBUG
#define CheckInstance(pSerial, failValue) \
  do { \
    if (!pSerial || !pSerial->mbus.m_allocated) \
      return (failValue); \
  } while(0)
#else // not DEBUG
#define CheckInstance(pSerial, failValue)
#endif // not DEBUG

//forward declaration
WIMBusMasterWrite_t UARTMasterWrite;
WIMBusMasterRead_t UARTMasterRead;
WIMBusByteAvailable_ UARTByteAvailable;
WIMBusClockSet_t UARTClockRateSet;

static const FUN_EXEP_PTR uartBusFuncs[] = {
    (FUN_EXEP_PTR) UARTMasterWrite,
    (FUN_EXEP_PTR) UARTMasterRead,
    (FUN_EXEP_PTR) UARTByteAvailable,
    (FUN_EXEP_PTR) UARTClockRateSet,
    (FUN_EXEP_PTR) WMBusReadTimeoutSet,
    (FUN_EXEP_PTR) WMBusReadTimeoutGet,
};

typedef struct WIMBusUART {
    WIMBus mbus;
    struct async_uart_descriptor *async;
    struct io_descriptor *SerialIO; //from IO descriptor
    volatile uint16_t m_txDoneBytesSent, m_rxDoneBytesReceived;
} WIMBusUART;

static WIMBusUART uartInstance[TOTAL_MAX_UART] = {
    {//UART1
        {//MBUS
            {uartBusFuncs, 255},
            false,
        }
    },
    {//UART2
        {//MBUS
            {uartBusFuncs, 255},
            false,
        }
    },
    {//UART3
        {//MBUS
            {uartBusFuncs, 255},
            false,
        }
    },
};

static WIMBusUART *FindInstanceFromIODescriptor(const struct async_uart_descriptor * const io_descr) {
    int i;
    for (i = 0; i < TOTAL_MAX_UART; ++i) {
        WIMBusUART *pSerial = pSerial = &uartInstance[i];
        if (pSerial->mbus.m_allocated && (pSerial->async == io_descr))
            return pSerial; // SUCCESS: found a match to io_descr
    }
    return NULL; // FAIL: could not find io_descr in usartInstances[]
}

static void TxCompleteCb(const struct async_uart_descriptor * const io_descr) {

    if (io_descr->stat == 0) {
        WIMBusUART *pSerial = FindInstanceFromIODescriptor(io_descr);
        if (pSerial) {
            pSerial->m_txDoneBytesSent = io_descr->tx_por;
        }
    }
}

static void RxCompleteCb(const struct async_uart_descriptor * const io_descr) {
    WIMBusUART *pSerial = FindInstanceFromIODescriptor(io_descr);
    pSerial->m_rxDoneBytesReceived = ringbuffer_num(&pSerial->async->rb);
}

WIMBusLength UARTByteAvailable(WIMBus *pBus) {
    WIMBusUART *pSerial = (WIMBusUART*) pBus;
    CheckInstance(pSerial, -1);
    return ringbuffer_num(&pSerial->async->rb);
}

WIMBusLength UARTClockRateSet(WIMBus *pBus, BusBaudateRate speed) {
    WIMBusUART *pSerial = (WIMBusUART*) pBus;
    CheckInstance(pSerial, -1);

    BusBaudateRate core = FCY;

    uint16_t reg = UBRG_VALUE(core, speed);

    if (reg == 0) return -1; //failure.

    //set the speed
    return async_uart_set_clock_speed(pSerial->async, reg);
}

WIMBusLength UARTMasterWrite(WIMBus *pBus, const uint8_t *buf, const uint8_t len) {
    WIMBusUART *pSerial = (WIMBusUART*) pBus;

    CheckInstance(pSerial, -1);

    //check Length
    if (len > pSerial->mbus.m_const.MasterTrasferLength) {
        return -1; //failure
    }

    pSerial->m_txDoneBytesSent = 0;

    int ret = io_write(pSerial->SerialIO, buf, len);
    if (ret != len) return -1; //failure

    while (pSerial->m_txDoneBytesSent != len) {
        Nop();
    }
    return pSerial->m_txDoneBytesSent;
}

WIMBusLength UARTMasterRead(WIMBus *pBus, uint8_t *buf, const uint8_t len) {
    WIMBusUART *pSerial = (WIMBusUART*) pBus;
    CheckInstance(pSerial, -1);

    if (len > pSerial->mbus.m_const.MasterTrasferLength) {
        return -1; //failure
    }
    pSerial->m_rxDoneBytesReceived = 0;

    int byteCount = 0;

    while (byteCount < len) {
        int numberOfByte = io_read(pSerial->SerialIO, &buf[byteCount], len - byteCount);
        if (numberOfByte < 0) return -1; //failure

        byteCount += numberOfByte;
    }

    return len;
}

WIMBus *WIMSerialUARTCreate(BusInstace inst, BusBaudateRate speed, UART_STOPbits stopBits, UART_PARITYbits parity,
        WMBusTimeoutMs readTimeoutMS, WMBusTimeoutMs watchdogTimeoutMS) {

    WIMBusUART *pSerial = &uartInstance[inst];

    if (pSerial->mbus.m_allocated)
        return 0; //failure

    if (inst > TOTAL_MAX_UART)
        return 0; //failure

    if (speed > MAX_UART_BAUDRATE)
        return 0; //failure

    if (inst == 0) {
        pSerial->async = &async_uart1;
    } else if (inst == 1) {
        pSerial->async = &async_uart2;
    } else if (inst == 2) {
        pSerial->async = &async_uart3;
    } else {
        return 0; //failure
    }

    if (get_async_uart_serial_descriptor(pSerial->async, &pSerial->SerialIO) < 0)
        return 0; //failure

    //initialize 
    pSerial->mbus.m_allocated = true;

    //watch dog timer out
    pSerial->mbus.WMBusWatchdogTimer = watchdogTimeoutMS;

    if (WIMBusReadTimeoutSet((WIMBus*) pSerial, readTimeoutMS) < 0) return 0; //failure

    //set parity
    if (async_uart_set_parity(pSerial->async, parity) < 0) return 0; //failure

    //set stop bit
    if (async_uart_set_stop_bits(pSerial->async, stopBits) < 0) return 0; //failure

    //set UART speed.
    if (WIMBusClockSet((WIMBus*) pSerial, speed) < 0) return 0; //failure

    // Add MasterWrite callback
    if (usart_async_register_callback(pSerial->async, USART_ASYNC_TXC_CB, TxCompleteCb) < 0) return 0; //failure

    if (usart_async_register_callback(pSerial->async, USART_ASYNC_RXC_CB, RxCompleteCb) < 0) return 0; //failure

    //enable uart
    if (async_uart_enable(pSerial->async) < 0) return 0; //failure

    //flush ring buffer
    if (async_uart_buffer_flush(pSerial->async) < 0) return 0; //failure

    return (WIMBus*) pSerial;
}
#include "hal_uart.h"
#include "hpl_uart.h"
#include <assert.h>

static struct _uart_async_device *uart1;
static struct _uart_async_device *uart2;
static struct _uart_async_device *uart3;

static void _uart_TX_interrupt_IE_enable(struct _uart_async_device * const device, unsigned char mask);
static void _uart_TX_interrupt_IE_disable(struct _uart_async_device * const device, unsigned char mask);
static void _uart_TX_interrupt_flag_clear(struct _uart_async_device * const device, unsigned char mask);

static void _uart_RX_interrupt_IE_enable(struct _uart_async_device * const device, unsigned char mask);
static void _uart_RX_interrupt_IE_disable(struct _uart_async_device * const device, unsigned char mask);
static void _uart_RX_interrupt_flag_clear(struct _uart_async_device * const device, unsigned char mask);

static int _uart_init(void *const hw) {
    ((UART_TypeDef*) hw)->uxmode = 0x0008;
    ((UART_TypeDef*) hw)->uxsta = 0x0000;
    ((UART_TypeDef*) hw)->uxbrg = 0;
    return 1;
}

static void _uart_RX_interrupt_IE_enable(struct _uart_async_device * const device, unsigned char mask) {
    SetUARTRXIE(device->instNum, mask);
}

static void _uart_RX_interrupt_IE_disable(struct _uart_async_device * const device, unsigned char mask) {
    SetUARTRXIE(device->instNum, mask);
}

static void _uart_RX_interrupt_flag_clear(struct _uart_async_device * const device, unsigned char mask) {
    SetUARTRXIF(device->instNum, mask);
}

static void _uart_TX_interrupt_IE_enable(struct _uart_async_device * const device, unsigned char mask) {
    SetUARTTXIE(device->instNum, mask);
}

static void _uart_TX_interrupt_IE_disable(struct _uart_async_device * const device, unsigned char mask) {
    SetUARTTXIE(device->instNum, mask);
}

static void _uart_TX_interrupt_flag_clear(struct _uart_async_device * const device, unsigned char mask) {
    SetUARTTXIF(device->instNum, mask);
}

static void _uart_handler_init(const void *const hw, void *dev) {
    if (hw == UART1B) {
        uart1 = (struct _uart_async_device*) dev;
    }
    if (hw == UART2B) {
        uart2 = (struct _uart_async_device*) dev;
    }
    if (hw == UART3B) {
        uart3 = (struct _uart_async_device*) dev;
    }
}

int _async_uart_init(struct _uart_async_device * const device, void *const hw) {

    int status = -1;
    assert(device);

    status = _uart_init(hw);
    device->hw = hw;
    if (hw == UART1B) {
        device->instNum = 0;
    } else if (hw == UART2B) {
        device->instNum = 1;
    } else if (hw == UART3B) {
        device->instNum = 2;
    } else {
        return status;
    }

    _uart_handler_init(hw, (void*) device);

    //set the interrupt
    _async_uart_RX_interrupt_flag_clear(device, 0);
    _async_uart_RX_interrupt_enable(device, 1);
    return status;
}

int _async_uart_set_parity(struct _uart_async_device * const device, unsigned int mask) {
    _uart_set_parity_bits(device->hw, mask);
    return 1;
}

int _async_uart_set_stop_bits(struct _uart_async_device * const device, unsigned int mask) {
    _uart_set_stop_bits(device->hw, mask);
    return 1;
}

int _async_uart_set_clock_speed(struct _uart_async_device * const device, unsigned int speed) {
    _uart_clock_set(device->hw, speed);
    return 1;
}

int _async_uart_enable(struct _uart_async_device * const device) {
    _uart_enable(device->hw);
    return 1;
}

int _async_uart_write_data(struct _uart_async_device * const device, unsigned char data) {
    _uart_data_write(device->hw, data);
    return 1;
}

int _async_uart_wait_byte_sent_status_clear(struct _uart_async_device * const device) {
    _uart_data_sent_wait(device->hw);
    return 1;
}

int _async_uart_TX_interrupt_enable(struct _uart_async_device * const device, unsigned char mask) {
    _uart_TX_interrupt_IE_enable(device, mask);
    return 1;
}

int _async_uart_TX_interrupt_disable(struct _uart_async_device * const device, unsigned char mask) {
    _uart_TX_interrupt_IE_disable(device, mask);
    return 1;
}

int _async_uart_TX_interrupt_flag_clear(struct _uart_async_device * const device, unsigned char mask) {
    _uart_TX_interrupt_flag_clear(device, mask);
    return 1;
}

int _async_uart_RX_interrupt_enable(struct _uart_async_device * const device, unsigned char mask) {
    _uart_RX_interrupt_IE_enable(device, mask);
    return 1;
}

int _async_uart_RX_interrupt_disable(struct _uart_async_device * const device, unsigned char mask) {
    _uart_RX_interrupt_IE_disable(device, mask);
    return 1;
}

int _async_uart_RX_interrupt_flag_clear(struct _uart_async_device * const device, unsigned char mask) {
    _uart_RX_interrupt_flag_clear(device, mask);
    return 1;
}

static void uart_tx_interrupt_hander(struct _uart_async_device *device) {
    _async_uart_TX_interrupt_flag_clear(device, 0);
    device->uart_cb.tx_byte_sent(device);
}

static void uart_rx_interrupt_hander(struct _uart_async_device *device) {
    void *hw = device->hw;

    while (_uart_get_buffer_status(hw) == 1) {
        device->uart_cb.rx_done_cb(device, _uart_read_data(hw));

        //check if any error occur during reading.
        if (_uart_get_status_register(hw) == 1) {
            //clear the error
            _uart_clear_error_bits(hw, 0x02);
        }
    }
    _async_uart_RX_interrupt_flag_clear(device, 0);
}

void __attribute__((interrupt, no_auto_psv)) _U1TXInterrupt(void) {
    uart_tx_interrupt_hander(uart1);
}

void __attribute__((interrupt, no_auto_psv)) _U1RXInterrupt(void) {
    uart_rx_interrupt_hander(uart1);
}

void __attribute__((interrupt, no_auto_psv)) _U2TXInterrupt(void) {
    uart_tx_interrupt_hander(uart2);
}

void __attribute__((interrupt, no_auto_psv)) _U2RXInterrupt(void) {
    uart_rx_interrupt_hander(uart2);
}

void __attribute__((interrupt, no_auto_psv)) _U3TXInterrupt(void) {
    uart_tx_interrupt_hander(uart3);
}

void __attribute__((interrupt, no_auto_psv)) _U3RXInterrupt(void) {
    uart_rx_interrupt_hander(uart3);
}


#include <assert.h>
#include "io.h"
#include "async_uart.h"
#include "ringbuffer.h"


int async_uart_write(struct io_descriptor * const io_desc, const uint8_t * const buf, const uint8_t len);
int async_uart_read(struct io_descriptor * const io_desc, uint8_t * const buf, const uint8_t len);
static void async_tx_byte_sent(struct _uart_async_device *device);
static void async_tx_sent_done(struct _uart_async_device *device);
static void async_rx_filling_done(struct _uart_async_device *device, unsigned char data);
static void async_uart_error(struct _uart_async_device *device);

int async_uart_initialization(struct async_uart_descriptor * const desc, void *const hw, uint8_t * const buffer, uint32_t size) {

    int status = -1;

    status = ringbuffer_init(&desc->rb, buffer, size);
    status = _async_uart_init(&desc->device, hw);

    desc->io.write = async_uart_write;
    desc->io.read = async_uart_read;

    desc->device.uart_cb.tx_byte_sent = async_tx_byte_sent;
    desc->device.uart_cb.tx_done_cb = async_tx_sent_done;
    desc->device.uart_cb.rx_done_cb = async_rx_filling_done;
    desc->device.uart_cb.error_cb = async_uart_error;

    return status;
}

int async_uart_write(struct io_descriptor * const io_desc, const uint8_t * const buf, const uint8_t len) {

    assert(io_desc && buf && len);
    struct async_uart_descriptor *desc = CONTAINER_OF(io_desc, struct async_uart_descriptor, io);

    if (desc->tx_por != desc->tx_buffer_length) return -1; //failure

    desc->tx_buffer = (uint8_t*) buf;
    desc->tx_buffer_length = len;
    desc->tx_por = 0;
    desc->stat = 1;
    //write the data to register so interrupt will start generating.
    _async_uart_write_data(&desc->device, desc->tx_buffer[desc->tx_por++]);
    _async_uart_TX_interrupt_enable(&desc->device, 1);
    return len;
}

int async_uart_read(struct io_descriptor * const io_desc, uint8_t * const buf, const uint8_t len) {

    struct async_uart_descriptor *desc = CONTAINER_OF(io_desc, struct async_uart_descriptor, io);

    assert(desc && buf && len);

    int get_count = ringbuffer_num(&desc->rb);
    int was_read = 0;

    while ((was_read < get_count) && (was_read < len)) {
        ringbuffer_get(&desc->rb, &buf[was_read++]);
    }
    return was_read;
}

static void async_tx_byte_sent(struct _uart_async_device *device) {
    assert(device);
    struct async_uart_descriptor *desc = CONTAINER_OF(device, struct async_uart_descriptor, device);

    if (desc->tx_por != desc->tx_buffer_length) {
        //enable write
        _async_uart_write_data(&desc->device, desc->tx_buffer[desc->tx_por++]);
    } else {
        _async_uart_TX_interrupt_disable(&desc->device, 0);
        _async_uart_TX_interrupt_flag_clear(&desc->device, 0);
        desc->device.uart_cb.tx_done_cb(&desc->device);
    }
}

static void async_tx_sent_done(struct _uart_async_device *device) {
    struct async_uart_descriptor *descr = CONTAINER_OF(device, struct async_uart_descriptor, device);

    descr->stat = 0;
    if (descr->uart_cb.tx_done) {
        descr->uart_cb.tx_done(descr);
    }
}

static void async_rx_filling_done(struct _uart_async_device *device, unsigned char data) {

    struct async_uart_descriptor *descr = CONTAINER_OF(device, struct async_uart_descriptor, device);

    ringbuffer_put(&descr->rb, data);

    if (descr->uart_cb.rx_done)
        descr->uart_cb.rx_done(descr);
}

static void async_uart_error(struct _uart_async_device *device) {
}

int get_async_uart_serial_descriptor(struct async_uart_descriptor * const desc, struct io_descriptor **io) {
    assert(desc && io);
    *io = &desc->io;
    return 1;
}

int async_uart_set_parity(struct async_uart_descriptor * const desc, unsigned int mask) {
    assert(desc);
    return _async_uart_set_parity(&desc->device, mask);
}

int async_uart_set_stop_bits(struct async_uart_descriptor * const desc, unsigned int mask) {
    assert(desc);
    return _async_uart_set_stop_bits(&desc->device, mask);
}

int async_uart_enable(struct async_uart_descriptor * const desc) {
    assert(desc);
    return _async_uart_enable(&desc->device);
}

int async_uart_set_clock_speed(struct async_uart_descriptor * const desc, unsigned int speed) {
    assert(desc);
    return _async_uart_set_clock_speed(&desc->device, speed);
}

int usart_async_register_callback(struct async_uart_descriptor * const desc, const enum usart_async_callback_type type, usart_cb_t cb) {
    assert(desc);

    switch (type) {
        case USART_ASYNC_RXC_CB:
            desc->uart_cb.rx_done = cb;
            break;
        case USART_ASYNC_TXC_CB:
            desc->uart_cb.tx_done = cb;
            break;
        case USART_ASYNC_ERROR_CB:
            desc->uart_cb.error = cb;
            break;
        default:
            return -1;
    }
    return 1;
}

int async_uart_buffer_flush(struct async_uart_descriptor * const desc) {
    assert(desc);
    return ringbuffer_flush(&desc->rb);
}
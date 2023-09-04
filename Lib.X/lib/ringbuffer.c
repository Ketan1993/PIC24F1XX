#include "ringbuffer.h"
#include "io.h"
#include <assert.h>

int ringbuffer_init(struct ringbuffer * const rb, void *buf, uint32_t size) {

    assert(buf && size);
    rb->buffer = (uint8_t*) buf;
    rb->buffer_size = size;
    rb->read_index = 0;
    rb->write_index = rb->read_index;
    return 1;
}

int ringbuffer_get(struct ringbuffer * const rb, uint8_t *data) {
    assert(rb && data);
    if (rb->write_index != rb->read_index) {
        *data = rb->buffer[rb->read_index];
        rb->read_index++;
    }
    return 1;
}

int ringbuffer_put(struct ringbuffer * const rb, uint8_t data) {
    assert(rb);
    rb->buffer[rb->write_index] = data;

    if ((rb->write_index - rb->read_index) > rb->buffer_size) {
        rb->read_index = rb->write_index - rb->buffer_size;
    }
    rb->write_index++;

    return 1;
}

int ringbuffer_num(struct ringbuffer * const rb) {

    assert(rb);
    return rb->write_index - rb->read_index;
}

int ringbuffer_flush(struct ringbuffer * const rb) {
    assert(rb);
    rb->read_index = 0;
    rb->write_index = rb->read_index;
    return 1;
}

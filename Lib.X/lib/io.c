#include "io.h"
#include <assert.h>

int io_write(struct io_descriptor * const io_desc, const uint8_t * const buf, const uint8_t len) {
    assert(io_desc && buf);
    return io_desc->write(io_desc, buf, len);
}

int io_read(struct io_descriptor * const io_desc, uint8_t * const buf, const uint8_t len) {
    assert(io_desc && buf);
    return io_desc->read(io_desc, buf, len);
}

/* 
 * File:   ringbuffer.h
 * Author: Admin
 *
 * Created on September 9, 2022, 12:24 PM
 */

#ifndef RINGBUFFER_H
#define	RINGBUFFER_H

#include <stdint.h>

#ifdef	__cplusplus
extern "C" {
#endif

    struct ringbuffer {
        uint8_t *buffer;
        uint32_t buffer_size;
        uint32_t write_index;
        uint32_t read_index;
    };

    int ringbuffer_init(struct ringbuffer * const rb, void *buf, uint32_t size);
    int ringbuffer_get(struct ringbuffer *const rb, uint8_t *data);
    int ringbuffer_put(struct ringbuffer *const rb, uint8_t data);
    int ringbuffer_num(struct ringbuffer *const rb);
    int ringbuffer_flush(struct ringbuffer *const rb);
    
#ifdef	__cplusplus
}
#endif

#endif	/* RINGBUFFER_H */


/* 
 * File:   io.h
 * Author: Admin
 *
 * Created on September 5, 2022, 6:22 PM
 */

#ifndef IO_H
#define	IO_H

#include <stdint.h>

#ifdef	__cplusplus
extern "C" {
#endif


    //IO structure
    struct io_descriptor;

    //typedef function for IO write
    typedef int (*write_t)(struct io_descriptor * const io_desc, const uint8_t *const buf, const uint8_t len);
    typedef int (*read_t)(struct io_descriptor * const io_desc, uint8_t *const buf, const uint8_t len);

    struct io_descriptor {
        write_t write;
        read_t read;
    };

    //typedef main function for invoke IO core function
    int io_write(struct io_descriptor * const io_desc, const uint8_t *const buf, const uint8_t len);
    int io_read(struct io_descriptor * const io_desc, uint8_t *const buf, const uint8_t len);

#ifdef	__cplusplus
}
#endif

#endif	/* IO_H */


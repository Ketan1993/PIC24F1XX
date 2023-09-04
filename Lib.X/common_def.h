/* 
 * File:   common_def.h
 * Author: Admin
 *
 * Created on September 6, 2022, 2:40 PM
 */

#ifndef COMMON_DEF_H
#define	COMMON_DEF_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define FOSC                            (long)32000000

#define FCY                             (long)(FOSC/2)

#ifdef	__cplusplus
}
#endif

#endif	/* COMMON_DEF_H */


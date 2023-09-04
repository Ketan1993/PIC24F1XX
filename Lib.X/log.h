/* 
 * File:   log.h
 * Author: Admin
 *
 * Created on September 9, 2022, 4:04 PM
 */

#ifndef LOG_H
#define	LOG_H

#include <string.h>
#include "board.h"
#include "lib/wimbus.h"

#ifdef	__cplusplus
extern "C" {
#endif

#define F(x)           x
#define WMLog(level, s) \
        do{ \
            WIMBus *pDebugSerial = gBoardGlobal.pSerialBus; \
            if(pDebugSerial){\
                WIMBusMasterWrite(pDebugSerial,  (const uint8_t*)s, strlen(s)); \
                WIMBusMasterWrite(pDebugSerial,  (const uint8_t*)"\n", 1); \
            }\
        }while(0)

#define WMLogError(s)  WMLog(F("ERR: "),  (s))
#define WMLogWarn(s)   WMLog(F("Warn: "), (s))

#ifdef	__cplusplus
}
#endif

#endif	/* LOG_H */


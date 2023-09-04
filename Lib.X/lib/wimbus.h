/* 
 * File:   wimbus.h
 * Author: Admin
 *
 * Created on September 5, 2022, 6:35 PM
 */

#ifndef WIMBUS_H
#define	WIMBUS_H

#include <stdbool.h>
#include <stdint.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define WIM_BUS_MASTER_WRITE                0
#define WIM_BUS_MASTER_READ                 1
#define WIM_BUS_BYTE_AVAILABLE              2
#define WIM_BUS_CLOCK_SETUP                 3
#define WIM_BUS_TIME_OUT_SET                4
#define WIM_BUS_TIME_OUT_GET                5

    //forward declaration for length
    typedef int16_t WIMBusLength;
    typedef uint32_t BusBaudateRate;
    typedef uint8_t BusInstace;
    typedef uint32_t WMBusTimeoutMs;

    //forward declaration of the main bus st.
    typedef struct WIMBus WIMBus;

    //master write function
    typedef WIMBusLength(WIMBusMasterWrite_t)(WIMBus *pBus, const uint8_t *buf, const uint8_t len);
    WIMBusMasterWrite_t WIMBusMasterWrite;

    //master read function
    typedef WIMBusLength(WIMBusMasterRead_t)(WIMBus *pBus, uint8_t *buf, const uint8_t len);
    WIMBusMasterRead_t WIMBusMasterRead;

    //set speed
    typedef WIMBusLength(WIMBusClockSet_t)(WIMBus *pBus, BusBaudateRate speed);
    WIMBusClockSet_t WIMBusClockSet;

    //set time out
    typedef bool (WIMBusReadTimeoutSet_) (WIMBus *pBus, WMBusTimeoutMs time);
    WIMBusReadTimeoutSet_ WIMBusReadTimeoutSet;

    //get time out
    typedef WMBusTimeoutMs(WIMBusReadTimeoutGet_)(WIMBus *pBus);
    WIMBusReadTimeoutGet_ WIMBusReadTimeoutGet;

    typedef WIMBusLength(WIMBusByteAvailable_)(WIMBus *pBus);
    WIMBusByteAvailable_ WIMBusByteAvailable;

    //function pointer array
    typedef void (*FUN_EXEP_PTR)(void);

    struct WIMBus {

        const struct {
            const FUN_EXEP_PTR *m_array;
            WIMBusLength MasterTrasferLength;
        } m_const;

        //driver initialization status
        bool m_allocated;

        //time-out to read function
        WMBusTimeoutMs WMBusReadTimeout;
        //watch-dog reset time out
        WMBusTimeoutMs WMBusWatchdogTimer;
    };

    //forward
    WIMBusReadTimeoutSet_ WMBusReadTimeoutSet;
    WIMBusReadTimeoutGet_ WMBusReadTimeoutGet;


#ifdef	__cplusplus
}
#endif

#endif	/* WIMBUS_H */


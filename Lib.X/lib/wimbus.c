#include "wimbus.h"

#ifdef __DEBUG
#define CheckInstance(pBus, failValue) \
  do { \
    if (!pBus || !pBus->m_allocated) \
      return (failValue); \
  } while(0)
#else // not DEBUG
#define CheckInstance(pBus, failValue)
#endif // not DEBUG

WIMBusLength WIMBusMasterWrite(WIMBus *pBus, const uint8_t *buf, const uint8_t len) {

    if (!pBus) return -1;

    const WIMBusMasterWrite_t *func = (const WIMBusMasterWrite_t *) pBus->m_const.m_array[WIM_BUS_MASTER_WRITE];

    if (!func) return -1;

    return (*func)(pBus, buf, len);
}

WIMBusLength WIMBusMasterRead(WIMBus *pBus, uint8_t *buf, const uint8_t len) {
    if (!pBus) return -1;

    const WIMBusMasterRead_t *func = (const WIMBusMasterRead_t *) pBus->m_const.m_array[WIM_BUS_MASTER_READ];

    if (!func) return -1;

    return (*func)(pBus, buf, len);
}

WIMBusLength WIMBusByteAvailable(WIMBus *pBus) {
    if (!pBus) return -1;

    const WIMBusByteAvailable_ *func = (const WIMBusByteAvailable_ *) pBus->m_const.m_array[WIM_BUS_BYTE_AVAILABLE];

    if (!func) return -1;

    return (*func)(pBus);
}

WIMBusLength WIMBusClockSet(WIMBus *pBus, BusBaudateRate speed) {

    if (!pBus) return -1;

    const WIMBusClockSet_t *func = (const WIMBusClockSet_t *) pBus->m_const.m_array[WIM_BUS_CLOCK_SETUP];

    if (!func) return -1;

    return (*func)(pBus, speed);
}

bool WIMBusReadTimeoutSet(WIMBus *pBus, WMBusTimeoutMs time) {

    if (!pBus) return -1;

    const WIMBusReadTimeoutSet_ *func = (const WIMBusReadTimeoutSet_ *) pBus->m_const.m_array[WIM_BUS_TIME_OUT_SET];

    if (!func) return -1;

    return (*func)(pBus, time);
}

WMBusTimeoutMs WIMBusReadTimeoutGet(WIMBus *pBus) {

    if (!pBus) return -1;

    const WIMBusReadTimeoutGet_ *func = (const WIMBusReadTimeoutGet_ *) pBus->m_const.m_array[WIM_BUS_TIME_OUT_GET];

    if (!func) return -1;

    return (*func)(pBus);
}

bool WMBusReadTimeoutSet(WIMBus *pBus, WMBusTimeoutMs time) {
    CheckInstance(pBus, -1);
    pBus->WMBusReadTimeout = time;
    return true;
}

WMBusTimeoutMs WMBusReadTimeoutGet(WIMBus *pBus) {
    CheckInstance(pBus, -1);
    return pBus->WMBusReadTimeout;
}

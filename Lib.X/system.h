/* 
 * File:   system.h
 * Author: Admin
 *
 * Created on September 5, 2022, 6:15 PM
 */

#ifndef SYSTEM_H
#define	SYSTEM_H

#ifdef	__cplusplus
extern "C" {
#endif



    /**
     * @brief clock initialization.
     * 
     * This function is used to initialize the clock for the MCU.
     * 
     * @param        none
     * @return       none
     * 
     */
    void WMB_ClockInitialization(void);

    /**
     * Error codes
     */

    typedef enum {
        /* ----- Traps ----- */
        TRAPS_OSC_FAIL = 0, /** Oscillator Fail Trap vector */
        TRAPS_STACK_ERR = 1, /** Stack Error Trap Vector */
        TRAPS_ADDRESS_ERR = 2, /** Address Error Trap Vector */
        TRAPS_MATH_ERR = 3, /** Math Error Trap Vector */
        TRAPS_NVM_ERR = 7, /** NVM Error Trap Vector */
    } TRAPS_ERROR_CODE;

    /**
     * @brief traps handler
     * 
     * This function is for the traps error.
     * Device will reset if any kind of the traps error generated.
     * 
     * @param code      [in] traps code
     * @return               none
     * 
     */
    void TRAPS_halt_on_error(TRAPS_ERROR_CODE code);


#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_H */


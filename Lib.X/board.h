/* 
 * File:   board.h
 * Author: Admin
 *
 * Created on September 6, 2022, 2:54 PM
 */

#ifndef BOARD_H
#define	BOARD_H

#ifdef	__cplusplus
extern "C" {
#endif


#define CLI_UART_INDEX                       1 //it's uart 2s
#define CLI_UART_SPEED                       115200

    typedef struct {
        struct WIMBus *pSerialBus; //CLI UART //debug UART
        struct WIMBus *pSerialModbus; //MODBUS UART
    } BoardGlobal;

    extern BoardGlobal gBoardGlobal;

    void board_system_initialization(void);
    void board_initialization(void);
    void board_application(void);

#ifdef	__cplusplus
}
#endif

#endif	/* BOARD_H */


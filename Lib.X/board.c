#include "common_def.h"
#include <libpic30.h>
#include "board.h"
#include "system.h"
#include "pic24fj256.h"
#include "lib/driver_init.h"
#include "lib/async_uart.h"
#include "lib/wimuart.h"
#include "log.h"

BoardGlobal gBoardGlobal;

void _Assert(const char *file, const char *line) {
    while (1) {

    }
}

void board_system_initialization(void) {
    WMB_ClockInitialization();
}

#define INPUT                                         1
#define OUTPUT                                        0

#define DIGITAL                                       0
#define ANALOG                                        1

#define RB14_SetPinAsIntputOutput(direction, mode)    do { TRISBbits.TRISB14 = direction; Nop(); ANSBbits.ANSB14 = mode;  Nop(); } while(0)
#define RB15_SetPinAsIntputOutput(direction, mode)    do { TRISBbits.TRISB15 = direction; Nop(); ANSBbits.ANSB15 = mode;  Nop(); } while(0)

//UART RX
#define PRINTF_UART_TX_PIN_MODE(direction, mode)      RB15_SetPinAsIntputOutput(direction, mode)
#define PRINTF_UART_RX_PIN_MODE(direction, mode)      RB14_SetPinAsIntputOutput(direction, mode)

void board_initialization(void) {

    PRINTF_UART_TX_PIN_MODE(INPUT, DIGITAL);
    PRINTF_UART_RX_PIN_MODE(INPUT, DIGITAL);

    /****************************************************************************
     * Set the PPS
     ***************************************************************************/
    __builtin_write_OSCCONL(OSCCON & 0xbf); // unlock PPS

    _U2RXR = 14; //RB14->RX2->UART2            
    _RP29R = _RPOUT_U2TX; //RB15->TX2->UART2   

    __builtin_write_OSCCONL(OSCCON | 0x40); // lock PPS

    UART1_Initialization();
}

#define CSI_YELLOW  "\33[34m"

void board_application(void) {

    board_initialization();
    char logBuffer[250 + 50];

    gBoardGlobal.pSerialBus = WIMSerialUARTCreate(CLI_UART_INDEX, CLI_UART_SPEED, ONE_STOP_BIT, EIGHT_BIT_PARITY, 3000, 3000);

    while (1) {
        ClrWdt();

        uint16_t byteCout = WIMBusByteAvailable(gBoardGlobal.pSerialBus);

        if (byteCout > 0) {
            char buffer[byteCout];
            byteCout = WIMBusMasterRead(gBoardGlobal.pSerialBus, (uint8_t*) buffer, byteCout);
            buffer[byteCout] = '\0';
        }

        sprintf(logBuffer, "%s total readable byte count %d %s \n\r", CSI_YELLOW, byteCout, CSI_YELLOW);
        WMLogError(logBuffer);

        __delay_ms(500);
    }
}
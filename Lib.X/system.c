#include "system.h"
#include <xc.h>

#define ERROR_HANDLER __attribute__((interrupt,no_auto_psv))
#define FAILSAFE_STACK_GUARDSIZE 8

// FBOOT
#pragma config BTMODE = SINGLE          //Boot Mode Configuration bits->Device is in Single Boot (legacy) mode
// FSEC
#pragma config BWRP = ON                // Boot Segment Write-Protect bit (Boot Segment is write protected)
#pragma config BSS = DISABLED           // Boot Segment Code-Protect Level bits (No Protection (other than BWRP))
#pragma config BSEN = OFF               // Boot Segment Control bit (No Boot Segment)
#pragma config GWRP = OFF               // General Segment Write-Protect bit (General Segment may be written)
#pragma config GSS = DISABLED           // General Segment Code-Protect Level bits (No Protection (other than GWRP))
#pragma config CWRP = OFF               // Configuration Segment Write-Protect bit (Configuration Segment may be written)
#pragma config CSS = DISABLED           // Configuration Segment Code-Protect Level bits (No Protection (other than CWRP))
#pragma config AIVTDIS = OFF            // Alternate Interrupt Vector Table bit (Disabled AIVT)

// FBSLIM
#pragma config BSLIM = 0x1FFF         // Boot Segment Flash Page Address Limit bits (Enter Hexadecimal value)

// FOSCSEL
#pragma config FNOSC = PRIPLL           // Oscillator Source Selection (Primary Oscillator with PLL module (XT + PLL, HS + PLL, EC + PLL))
#pragma config PLLMODE = PLL96DIV2      // PLL Mode Selection (96 MHz PLL. Oscillator input is divided by 2 (8 MHz input))
#pragma config IESO = OFF               // Two-speed Oscillator Start-up Enable bit (Start up with user-selected oscillator source)

// FOSC
#pragma config POSCMD = XT              // Primary Oscillator Mode Select bits (XT Crystal Oscillator mode)
#pragma config OSCIOFCN = OFF           // OSC2 Pin Function bit (RC15 (CLKO) outputs CPU clock)
#pragma config SOSCEN = OFF              // SOSC Power Selection Configuration bits (SOSC crystal driver is enabled (SOSCI/SOSCO mode))
#pragma config PLLSS = FRC              // PLL Secondary Selection Configuration bit (PLL is fed by the Primary oscillator)
#pragma config IOL1WAY = ON             // Peripheral pin select configuration bit (Allow only one reconfiguration)
#pragma config FCKSM = CSECME           // Clock Switching Mode bits (Both Clock switching and Fail-safe Clock Monitor are enabled)

// FWDT
#pragma config WDTPS = PS1024          // Watchdog Timer Postscaler bits (1:32,768)
#pragma config FWPSA = PR128            // Watchdog Timer Prescaler bit (1:128)
#pragma config FWDTEN = ON              // Watchdog Timer Enable bits (WDT is always enabled (cannot be controlled by SWDTEN))
#pragma config WINDIS = OFF             // Watchdog Timer Window Enable bit (WDT in non-windowed mode)
#pragma config WDTWIN = WIN75           // Watchdog Timer Window Select bits (WDT window is 75% of WDT period)
#pragma config WDTCMX = WDTCLK          // WDT MUX Source Select bits (WDT clock source is determined by the WDTCLK Configuration bits)
#pragma config WDTCLK = LPRC            // WDT Clock Source Select bits (WDT uses LPRC)

// FPOR
#pragma config BOREN = ON               // Brown Out Enable bit (Brown Out is enabled)
#pragma config LPREGEN = OFF            // Low power regulator control (Low power regulator is disabled)
#pragma config LPBOREN = ON             // Downside Voltage Protection Enable bit (Low power BOR is enabled when BOR is inactive)

// FICD
#pragma config ICS = PGD2               // ICD Communication Channel Select bits (Communicate on PGEC2 and PGED2)
#pragma config JTAGEN = OFF             // JTAG Enable bit (JTAG is disabled)
#pragma config BTSWP = OFF              // BOOTSWP Instruction Enable bit (BOOTSWP instruction is disabled)

// FDMTIVTL
#pragma config DMTIVTL = 0xFFFF         //  (Enter Hexadecimal value)

// FDMTIVTH
#pragma config DMTIVTH = 0xFFFF         //  (Enter Hexadecimal value)

// FDMTCNTL
#pragma config DMTCNTL = 0xFFFF         //  (Enter Hexadecimal value)

// FDMTCNTH
#pragma config DMTCNTH = 0xFFFF         //  (Enter Hexadecimal value)

// FDMT
#pragma config DMTDIS = OFF             //  (Dead Man Timer is disabled and can be enabled by software)

// FDEVOPT1
#pragma config ALTCMPI = OFF            // Alternate Comparator Input Enable bit (C2INC and C3INC are on RG9 and RD11)
#pragma config TMPRPIN = OFF            // Tamper Pin Enable bit (TMPRN pin function is disabled)
#pragma config SOSCHP = ON              // SOSC High Power Enable bit (valid only when SOSCSEL = 1 (SOSC high power mode (default))
#pragma config ALTI2C1 = ON             // Alternate I2C pin Location (ASDA1 and ASCL1 on RB5 and RB4)
#pragma config SMB3EN = ON              // SMBus 3 Enable bit (SMBus 3.0 input levels)

//static function
static void SOSC_Configuration(void);

static void SOSC_Configuration(void) {
    char a, b, c, *p;

    a = 2;
    b = 0x46;
    c = 0x57;
    p = (char *) &OSCCON;

    asm volatile ("mov.b %1,[%0] \n" // writing first unclock sequence 0x46
            "mov.b %2,[%0] \n" // writing second unlock sequence 0x57
            "mov.b %3,[%0] \n" : /* no outputs */ : "r"(p), "r"(b), "r"(c),
            "r"(a));
}

//system 

void WMB_ClockInitialization(void) {
    OSCTUN = 0b000000; // setting the oscillator frequency to default
    // Clock switch to incorporate PLL
    __builtin_write_OSCCONH(0x03); // initiate clock switch
    __builtin_write_OSCCONL(OSCCON | 0x01); // start the clock switching operation

    while (OSCCONbits.COSC != 0b011); // checking that the current oscillator has switched to primary osc with PLL
    while (OSCCONbits.LOCK != 1); // waiting for the PLL to get locked
}



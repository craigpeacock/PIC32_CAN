
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes


#define LED1_DIR    TRISGbits.TRISG15
#define LED2_DIR    TRISGbits.TRISG14
#define LED3_DIR    TRISGbits.TRISG13
#define LED4_DIR    TRISGbits.TRISG12

#define LED1        LATGbits.LATG15
#define LED2        LATGbits.LATG14
#define LED3        LATGbits.LATG13
#define LED4        LATGbits.LATG12

#define S1_DIR      TRISCbits.TRISC1
#define S2_DIR      TRISCbits.TRISC2
#define S3_DIR      TRISCbits.TRISC3

#define S1          PORTCbits.RC1
#define S2          PORTCbits.RC2
#define S3          PORTCbits.RC3

int main ( void )
{
    LED1_DIR = 0;
    LED2_DIR = 0;
    LED3_DIR = 0;
    LED4_DIR = 0;
    
    LED1 = 1;
    LED2 = 1;
    LED3 = 1;
    LED4 = 1;
    
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    printf("Hello World\r\n");

    while ( true )
    {
        LED1 = S1;
        LED2 = S2;
        LED3 = S3;

        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
    }

    /* Execution should not come here during normal operation */
    return ( EXIT_FAILURE );
}

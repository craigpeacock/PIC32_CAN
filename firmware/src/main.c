
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

void CAN2_Transmit_Test(void);

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
    printf("\r\nPIC32MX795F CAN Example\r\n");

    while ( true )
    {
        if (!S1) {
            LED1 = 1;
            CAN2_Transmit_Test();
            while (!S1);
            LED1 = 0;
        }  
        
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
    }

    /* Execution should not come here during normal operation */
    return ( EXIT_FAILURE );
}

void CAN2_Transmit_Test(void)
{
    uint8_t     i;
    uint32_t    messageID = 0x555;                  
    uint8_t     message[] = {0,1,2,3,4,5,6,7};      
    uint8_t     DLC = 8;                  

    if (CAN2_MessageTransmit(messageID, DLC, message, 0, CAN_MSG_TX_DATA_FRAME)){
        printf("CAN2 TX Msg: ID = 0x%03X, Length = %d, [",messageID, DLC);
        for (i = 0; i < DLC; i++)
            printf(" %02X", message[i]);
        printf(" ]\r\n");
    } else {
        printf("CAN2 Error Transmit Failed\r\n");
    }
}
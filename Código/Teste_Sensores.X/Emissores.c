/* ************************************************************************** */
/** Leitor de Sensores IR

  @Company
 Pedro Magalhães || Amélia Ramos 

  @File Name
    source_sensores.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#define _SUPPRESS_PLIB_WARNING 1
#include <p32xxxx.h>
#include <plib.h>

#define SYSCLK 80000000L // System clock frequency, in Hz
#define PBUSCLK 40000000L // Peripheral bus clock


/*
 
 */

int main(int argc, char** argv) {
   
    // Performance optimization (flash access time, enable instruct and data cache,... and PBClock setup
    SYSTEMConfigPerformance(SYSCLK);
    mOSCSetPBDIV( OSC_PB_DIV_2 ); // This is necessary since SYSTEMConfigPerformance defaults FPBDIV to DIV_1

    // Set Dx IOs
    TRISBbits.TRISB6 = 0; // D0 as digital output
    TRISBbits.TRISB5 = 0;
    TRISBbits.TRISB4 = 0;
    TRISBbits.TRISB3 = 0;
    TRISBbits.TRISB2 = 0;
    TRISBbits.TRISB1 = 0;
    TRISBbits.TRISB0 = 0;
    

    // Main loop
    while(1) {
        
        // Set RD0 according with RD1
        LATBbits.RB0 = 1;
        delay(1000);
        LATBbits.RB0 = 0;
    }

    return (EXIT_SUCCESS);
}

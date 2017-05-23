/* ************************************************************************** */
/** Leitor de Sensores IR

  @Company
 Pedro Magalhães || Amélia Ramos 

*/
#include <stdio.h>
#include <stdlib.h>
#define _SUPPRESS_PLIB_WARNING 1
#include <p32xxxx.h>
#include <plib.h>

#define SYSCLK 80000000L // System clock frequency, in Hz
#define PBUSCLK 40000000L // Peripheral bus clock
#define TPS_256 7 // TCKPS code for xx pre-scaler
#define TPS_64  6
#define TPS_32  5
#define TPS_16  4
#define TPS_8   3
#define TPS_4   2
#define TPS_2   1
#define TPS_1   0


void delay(unsigned int n_intervalos);
int _mon_getc(int canblock);
void _mon_putc(char c);
int main(int argc, char** argv) {
   
    // Performance optimization (flash access time, enable instruct and data cache,... and PBClock setup
    SYSTEMConfigPerformance(SYSCLK);
    mOSCSetPBDIV( OSC_PB_DIV_2 ); // This is necessary since SYSTEMConfigPerformance defaults FPBDIV to DIV_1
  

 // Set IOsTRISBbits.TRISB6 = 0;
    TRISBbits.TRISB7 = 0; // D0 as digital output
    TRISBbits.TRISB8 = 0;
    TRISBbits.TRISB9 = 0;
    TRISBbits.TRISB10= 1; //pino entrada demux
    int v= 0;
    
    // Remove input/output buffering
    setbuf(stdin, NULL); //no input buffer (for scanf)
    setbuf(stdout, NULL); //no output buffer (for printf)
    // Main loop
    while(1){
        
        
        printf("\n inserir inteiro");
        scanf("%d",&v);
        printf("\n Valor digitado: %d",v);
            switch(v) {

                   case 0:
                   {
                   LATBbits.LATB9 = 0;//A
                   LATBbits.LATB8 = 0;//B
                   LATBbits.LATB7 = 0;//C
                   break;
                   }
	
                   case 1:
                   {
                   LATBbits.LATB9 = 1;
                   LATBbits.LATB8 = 0; 
                   LATBbits.LATB7 = 0;
                   break; 
                   }
                   case 2:
                   {
                   LATBbits.LATB9 = 0;
                   LATBbits.LATB8 = 1; 
                   LATBbits.LATB7 = 0;
                   break; 
                   }
                   case 3:
                   {
                   LATBbits.LATB9 = 1;
                   LATBbits.LATB8 = 1; 
                   LATBbits.LATB7 = 0;
                   break; 
                   }
                   case 4:
                   {
                   LATBbits.LATB9 = 0;
                   LATBbits.LATB8 = 0; 
                   LATBbits.LATB7 = 1;
                   break; 
                   }
                   case 5:
                   {
                   LATBbits.LATB9 = 1;
                   LATBbits.LATB8 = 0; 
                   LATBbits.LATB7 = 1;
                   break; 
                   }
                   case 6:
                   {
                       printf("Case 6\n");
                   LATBbits.LATB9 = 0;
                   LATBbits.LATB8 = 1; 
                   LATBbits.LATB7 = 1;
                   break; 
                   }
                   default : /* Optional */
                   //do nothing
                   printf("\nDo_Nothing");
                   return 0;
            }
            printf("\nResultado:");
            int a = PORTBbits.RB10;
            
            printf("\nValor lido %d",a);
    }
    return(EXIT_SUCCESS);
}

void delay(unsigned int n_intervalos)
{	
	volatile unsigned int i;

	for(;n_intervalos != 0; n_intervalos--)
		for(i = 4997; i != 0; i--);
}
void _mon_putc(char c) {
    while (U1STAbits.UTXBF); // Wait till buffer available (TX Buffer Full)
    U1TXREG = c; // Put char in Tx buffer
    return;
}

int _mon_getc(int canblock) {    
    // Reset Overrun Eror Flag - if set UART does not receive any chars
    if (U1STAbits.OERR)
        U1STAbits.OERR;

    if (canblock == 0) {
        if (U1STAbits.URXDA) {            
            return (int) U1RXREG;;
        }
    }
    else {
        while (!U1STAbits.URXDA);
        return (int) U1RXREG;
    }
    return -1;
}
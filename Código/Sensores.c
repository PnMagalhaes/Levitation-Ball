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
#define TPS_256 7 // TCKPS code for xx pre-scaler
#define TPS_64  6
#define TPS_32  5
#define TPS_16  4
#define TPS_8   3
#define TPS_4   2
#define TPS_2   1
#define TPS_1   0

void signalPWM(unsigned int dutyCycle);
void delay(unsigned int n_intervalos);
int get_position();
void setMux(unsigned int num);
int _mon_getc(int canblock);
void _mon_putc(char c);


int Y [7];  //saida
int d = 0;
int i = 0;
static char ledsIV[]={0x0001,0x0002,0x0004,0x0008,0x0010,0x0020,0x0040,0x0000};

int main(int argc, char** argv) {
   
    // Performance optimization (flash access time, enable instruct and data cache,... and PBClock setup
    SYSTEMConfigPerformance(SYSCLK);
    mOSCSetPBDIV( OSC_PB_DIV_2 ); // This is necessary since SYSTEMConfigPerformance defaults FPBDIV to DIV_1
 
         
 // Set timer
    T2CONbits.ON = 0; // Stop timer
    //T2CONbits.TCS = 0; // Internal clock
    T2CONbits.TCKPS = 5; //Select pre-scaler 1:16 - 1 250 000Hz
    T2CONbits.T32 = 0; // 16 bit timer operation
    PR2=24;
    TMR2=0;
    // Timer on
    T2CONbits.TON=1;

    // Set OC1
    OC1CONbits.OCM = 6; // Operation mode
    OC1CONbits.OCTSEL=0; // Select clock source T2/T3
        
    OC1CONbits.ON=1;
 
 // Set IOs 
    /*TRISBbits.TRISB6 = 0; // D0 as digital output
    TRISBbits.TRISB5 = 0;
    TRISBbits.TRISB4 = 0;
    TRISBbits.TRISB3 = 0;
    TRISBbits.TRISB2 = 0;
    TRISBbits.TRISB1 = 0;
    TRISBbits.TRISB0 = 0;*/
    TRISBbits.TRISB7 = 0; // D0 as digital output
    TRISBbits.TRISB8 = 0;
    TRISBbits.TRISB9 = 0;
    TRISEbits.TRISE7= 1; //pino entrada demux
    TRISB = TRISB & 0XFF80;  // Coloca do RB0 ao RB6 como output do RB15 ao RB7 como input
    int temp = 100;

 
    // Position of reference
    char reference;
    // Main loop
    while(1)
    {
        
        int a = get_position();
        //printf("P[%d]", a);
        delay(1000);
        
    }
    return(EXIT_SUCCESS);
}
//##############################################################################################################################
//##############################################################################################################################
int get_position() 
{
    int numLeds=7;
    int pos = 7;
    int temp = 0;
    
    for(i=0; i < numLeds; i++)
		{
            //ligar emissores
            //printf("forSetLeds\n \r");
			LATB = LATB & 0xFF00;           
            LATB = LATB | ledsIV[i];
            
            //ler sensores
            setMux(i);
            Y[i] = PORTEbits.RE7;
			
            delay(100);
            
		}
    if (Y[0] == 0)
    {
        printf("X");
        //Y[6]=0; 
        //Y[0]=1;
    }
    else if(Y[6] == 0)
    {
        printf("Y");
        //Y[0]=0;
        //Y[6]=1;
    }
    else
    {
        printf("k");
    for(temp = 0 ; temp < 8 ;temp++)
    {        
        if(Y[temp] == 0)
        {
            pos = temp;
            break;
        }        
        //printf("P[%d]", pos);        
    }     
    }
    return temp;
}
void setMux(unsigned int num)
{
    
    switch(num) {

                   case 0:
                   {
                   printf("-\n \r");
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
                   LATBbits.LATB9 = 0;
                   LATBbits.LATB8 = 1; 
                   LATBbits.LATB7 = 1;
                   break; 
                   }
                   //default : /* Optional */
                   //do nothing
                   //printf("\nDo_Nothing");
                  
                   
                   
                   
            }
    //read[num] = PORTEbits.RE7;
  
    printf("P[%d] = %d\n\r", num, Y[num] );

}
void delay(unsigned int n_intervalos)
{	
	volatile unsigned int i;

	for(;n_intervalos != 0; n_intervalos--)
		for(i = 4997; i != 0; i--);
}

void signalPWM(unsigned int dutyCycle)
{  
 OC1RS=(PR2 +1)*dutyCycle/100; 
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

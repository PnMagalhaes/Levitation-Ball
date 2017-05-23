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
unsigned int setMux(unsigned int num);
int _mon_getc(int canblock);
void _mon_putc(char c);


int Y [7];  //saida
int d = 0;
int i = 0;
int leitura = 0;
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
    TRISEbits.TRISE6 = 0; //A as digital output
    TRISEbits.TRISE5 = 0; //B
    TRISEbits.TRISE4 = 0; //C
    TRISEbits.TRISE7 = 1; //pino entrada demux
    TRISB = TRISB & 0XFF80;  // Coloca do RB0 ao RB6 como output do RB15 ao RB7 como input
    
    
    
    int temp = 100;    
    // Main loop
    while(1)
    {
        
        int a = get_position();
        //printf("-----\n\r");
        delay(100);
        printf("pos = %d\n\r",a);
        
    } 
    return(EXIT_SUCCESS);
}
//##############################################################################################################################
//##############################################################################################################################
int get_position() 
{
    int i = 0;
    int numLeds = 7;
    int pos = 10;
    for(i=0; i < numLeds; i++)
	{
            //ligar emissores            
			LATB = LATB & 0xFF00;   //apaga todos        
            //ler sensores            
            Y[i] = setMux(i);                   //aponta o mux e liga o emissor respectivo
            //printf("P[%d]=%d\n\r", i, Y[i]);
			//printf("P[%d]\n\r", Y[i]); 
            delay(1); 
            if(Y[i]==0)
            {
                //posição encontrada
                pos = i;
                break;
            }            
	}   
    return pos;
}
unsigned int setMux(unsigned int num)
{    
    switch(num) {
                   case 6:
                   {
                   //printf("-\n \r");
                   LATEbits.LATE6 = 0;//A
                   LATEbits.LATE5 = 0;//B
                   LATEbits.LATE4 = 0;//C
                   
                   LATBbits.LATB0 = 1;//E1
                   break;
                   }
	
                   case 0:
                   {
                   LATEbits.LATE6 = 1;
                   LATEbits.LATE5 = 0; 
                   LATEbits.LATE4 = 0;
                   
                   LATBbits.LATB0 = 0;//E1
                   LATBbits.LATB1 = 1;//E1
                   
                   break; 
                   }
                   case 1:
                   {
                   LATEbits.LATE6 = 0;
                   LATEbits.LATE5 = 1; 
                   LATEbits.LATE4 = 0;
                   
                   LATBbits.LATB2 = 1;//E1
                   break; 
                   }
                   case 2:
                   {
                   LATEbits.LATE6 = 1;
                   LATEbits.LATE5 = 1; 
                   LATEbits.LATE4 = 0;
                   
                   LATBbits.LATB3 = 1;//E1
                   break; 
                   }
                   case 3:
                   {
                   LATEbits.LATE6 = 0;
                   LATEbits.LATE5 = 0; 
                   LATEbits.LATE4 = 1;
                   
                   LATBbits.LATB4 = 1;//E1
                   break; 
                   }
                   case 4:
                   {
                   LATEbits.LATE6 = 1;
                   LATEbits.LATE5 = 0; 
                   LATEbits.LATE4 = 1;
                   
                   LATBbits.LATB5 = 1;//E1
                   break; 
                   }
                   case 5:
                   {
                   LATEbits.LATE6 = 0;
                   LATEbits.LATE5 = 1; 
                   LATEbits.LATE4 = 1;
                   
                   LATBbits.LATB6 = 1;//E1
                   break; 
                   }   
            }
   
    leitura = PORTEbits.RE7;
    return leitura;
    
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

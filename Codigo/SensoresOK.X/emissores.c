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

void setReg();
void regulatorPWM(unsigned int dutyCycle);
void delay(unsigned int n_intervalos);
int get_position();
unsigned int setMux(unsigned int num);
int _mon_getc(int canblock);
void _mon_putc(char c);
void tmr2(void);


int Y [7];  //saida
int d = 0;
int i = 0;
int leitura = 0;
static char ledsIV[]={0x0001,0x0002,0x0004,0x0008,0x0010,0x0020,0x0040,0x0000};
int flag = 0;
float Kp;
float Ti;
float Td;

int main(int argc, char** argv) {
   
    //Performance optimization (flash access time, enable instruct and data cache,... and PBClock setup
    SYSTEMConfigPerformance(SYSCLK);
    mOSCSetPBDIV( OSC_PB_DIV_2 ); // This is necessary since SYSTEMConfigPerformance defaults FPBDIV to DIV_1
    INTEnableSystemMultiVectoredInt();

    setbuf(stdin, NULL); //no input buffer (for scanf)
    setbuf(stdout, NULL); //no output buffer (for printf)
    
  // Set timer
    T3CONbits.ON = 0; // Stop timer
    //T2CONbits.TCS = 0; // Internal clock
    T3CONbits.TCKPS = 5; //Select pre-scaler 1:16 - 1 250 000Hz
    //T3CONbits.T32 = 0; // 16 bit timer operation
    PR3=24;
    TMR3=0;
    // Timer on
    T3CONbits.TON=1;
    // Set OC1
    OC1CONbits.OCM = 6; // Operation mode
    OC1CONbits.OCTSEL=1; // Select clock source T2/T3        
    OC1CONbits.ON=1;
    
    //Set timer ti interrupt    
    long pr_value;
    long period_us;
    T2CONbits.ON = 0; // Stop timer
    
    void __attribute__( (interrupt(IPL2AUTO), vector(_TIMER_2_VECTOR))) tmr2(void);
    IFS0bits.T2IF=0; // Reset interrupt flag
    IPC2bits.T2IP=2; //set interrupt priority (1..7) *** Make sure it matches iplx in isr declaration above ***
    IEC0bits.T2IE = 1; // Enable T2 interrupts
    // Timer period configuration
    period_us=10000/2; // Toggles every half-period - period in microseconds
    pr_value = period_us/(256/(float)(PBUSCLK/1000000)); // Compute PR value    
    T2CONbits.TCKPS = TPS_256; //Select pre-scaler
    T2CONbits.T32 = 0; // 16 bit timer operation
    PR2=pr_value;
    TMR2=0;
    T2CONbits.TON=1; // Start the timer
    
    
    
    
    // Set IOs 
    TRISEbits.TRISE6 = 0; //A as digital output
    TRISEbits.TRISE5 = 0; //B
    TRISEbits.TRISE4 = 0; //C
    TRISEbits.TRISE3 = 0;
    TRISEbits.TRISE7 = 1; //pino entrada demux
    TRISB = TRISB & 0XFF80;  // Coloca do RB0 ao RB6 como output do RB15 ao RB7 como input
    
    
    int setPos =0;
    int temp = 100;   
    int vp = 0;
    int erro = 0;
    int Vmax=18;    // Tens?o m?xima entregue ? bobine (ajustar)
    int DCmax=100;  //Duty-cycle maximo a aplicar no PWM
    int dutyC;
    // Main loop
    
    Kp = 120;
    Td = 0.3;
    Ti = 1;
    
    int u_p;
    int u_d;
    int u_i;
    int erro_anterior;
    int u_i_a;
    int ei;
    int u;
    int h = 0.1;
    unsigned char in;
    int c;
    while(1)
    {
        printf("inserir");
        scanf("%d", &c);
        switch(c)
        {
            case 1:
            {
                printf("aumentarKP");
                Kp = Kp+0.01;
            }
            case 2:
            {
                Kp = Kp-0.01;
            }
        }
        
        regulatorPWM(50);
        erro_anterior = ei;
        u_i_a = u_i;
        delay(10);
        setPos = 3;
        int y = get_position();
        //printf("POS=%d\n\r",y);   
        erro = setPos - y;
        u_p = Kp*erro;
        u_d = Kp*Td*(erro-erro_anterior)/h;
        //u_i = erro*Ti*4/Kp + u_i_a;
        u = u_p + u_d;
        
        setReg(u);
        
    } 
    return(EXIT_SUCCESS);
}
//##############################################################################################################################
//##############################################################################################################################
void tmr2(void)
{
    //printf("interrupt");
    
    if(flag==1)
    {
        LATEbits.LATE3 = 1;
        flag = 0;
    }
    else
    {
        LATEbits.LATE3 = 0;
        flag = 1;
    }
    
    IFS0bits.T2IF = 0;
}
void setReg(int t)
{
    //t = t*(-1);
    //printf("u=%d\n\r",t);
}
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
void regulatorPWM(unsigned int dutyCycle)
{  
 OC1RS=(PR3 +1)*dutyCycle/100; 
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

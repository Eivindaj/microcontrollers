#include<xc.h>
unsigned char count;

void delay()
{
    TRISB = 0;
    PORTB = 0;
    /*    500 ms delay calculation
    1/20Mhz = 5e-8
    5e-8 * 2^16 = 3.28ms
    5e-8 * 256 * 2^16 = 840ms
    (0.5/(5e-8 * 256)) - 2^16 = 26
    */
    T1CON = 0B00111101;
    TMR1H = 0X0B;
    TMR1L = 0XDC;
    TMR1IE = 1;
    INTCONbits.GIE = 1;
    T1CONbits.TMR1ON = 1;
}


int main(void){

    
    TRISC = 0x00;
    count = 1;
    
    delay();
    while(1){
       PORTC = count;
       
    }
}

void __interrupt() isr(void){
        count++;
        TMR1H = 0X0B;
        TMR1L = 0XDC;
        TMR1IF = 0;
        PORTAbits.RA0 ^= 1;
}
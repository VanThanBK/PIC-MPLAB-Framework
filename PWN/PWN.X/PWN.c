/*
 * File:   PWN.c
 * Author: Van Than
 *
 * Created on June 7, 2017, 2:39 PM
 */


// PIC16F877A Configuration Bit Settings
// 'C' source line config statements
// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <stdlib.h>
#include <stdio.h>

//Oscillator define
#define _XTAL_FREQ 20000000

//Library
#include "D:\PIC_MPlap\LCD\MyLCD.h"
//#include "D:\PIC_MPlap\ADC\MyADC.h"
//#include "D:\PIC_MPlap\7SEG\My_7seg.h"
void PWMInit();
void Timer2Init();
void PWMControl(unsigned char percent, char sig);
void main(void) {
    __delay_ms(200);
    LCDInit();
    LCDClear();
    LCDPrint(1,1,"PWM Period:");
    PWMInit();
    while(1){
        PWMControl(60,0);
    }
    return;
}
//Init CCP
void PWMInit(){
    //Pin config
    TRISC2 = 0;
    RC2 = 1;
    //PWM Mode select
    CCP1M3 = 1;
    CCP1M2 = 1;
    CCP1M1 = 1;
    CCP1M0 = 1;
    //Timer2 Init
    Timer2Init();
    //PWM Duty circle
    //CCPR1L = 0x7D;
    //Timer2 Start
    TMR2ON = 1;
}

void Timer2Init(){
    //Set PR2 value
    PR2 = 0xff;
    //Postscaler
    /*TOUTPS3 = 0;
    TOUTPS2 = 0;
    TOUTPS1 = 0;
    TOUTPS0 = 0;*/
    //Prescaler
    T2CKPS1 = 1;
    T2CKPS0 = 1;
    //Timer2 Start
    //TMR2ON = 1;
}
void PWMControl(unsigned char percent, char sig){
    unsigned int PWM_Reg;
    if(sig==0) PWM_Reg = (100-percent)*10.23;
    else PWM_Reg = percent*10.23;
    CCPR1L = (PWM_Reg>>2);
    CCP1X =  (PWM_Reg>>1)&0x01;
    CCP1Y =  PWM_Reg&0x01;
}

/*
 * File:   NEW.c
 * Author: Van Than
 *
 * Created on November 1, 2017, 8:00 AM
 */
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)


#include <xc.h>
#include <stdlib.h>
#include <stdio.h>

#define _XTAL_FREQ 4000000
#include "A:\PIC_MPlap\LCD\MyLCD.h"
//#define EN      RD6
//#define DIR     RD5
//#define CLK     RD4

void RBInit();
void PWMInit();
void Timer2Init();
void PWMControl(unsigned char percent, char sig);
//float Volt = 10;
unsigned char i;
void main(void) {
   // __delay_ms(200);
    LCDInit();
    LCDClear();
    //RBInit();
   // TRISE1 = 0;
   // TRISA1 = 0;
   // TRISE0 = 0;
    TRISC2 = 0;
    TRISC1 = 0;
    LCDPrint(1,1,"NG.V.THAN");
    LCDPrint(2,1,"TR.X.HAI");
    //RA1 = 1;
    //RE0 = 1;
    
    //PWMInit();
    
   // RC1 = 1;
    //TRISD4 = 0;
    //TRISD5 = 0;
    //TRISD6 = 0;
    //EN = 0;
    //DIR = 1;
    while(1){
        //CLK = 1;
        //__delay_us(4);
        //CLK = 0;
       // __delay_ms(200);
        RC1 = 1;
        PWMControl(20,1);
        __delay_ms(2000);
        PWMControl(90,1);
        __delay_ms(2000);
        
    }
    return;
}
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
/*
void interrupt ext_int(void){
    if(INTF){
        i++;
        if(i>100) i = 0;
        INTF = 0;
    }
}


void INTInit(){
    TRISB0  = 1;        //Cau hinh cho PIN ngat
    GIE     = 1;        //Bat ngat toan cuc
    PEIE = 1;
    INTE    = 1;        //Cho phep ngat ngoai
    INTEDG  = 0;        //Chon suon ngat (falling time)
    OPTION_REG &= 0x7f; //Keo tro treo cho PORTB
    nRBPU = 0;
    INTF    = 0;        //Xoa co ngat
}*/
/*********************************************
 Su kien cho ngat */
/*
void interrupt ext_RB(void){
    if(RBIF){
        if(!RB4){
            i++;
            if(i>100) i = 100;
        }
        else if(!RB5){
            if(i<=0) i = 0;
            else i--;
        }
        RBIF = 0;
    }
}*/
/*************************************
 Khoi dong ngat */
/*
void RBInit(){
    TRISB4  = 1;
    TRISB5  = 1;        //Cau hinh cho PIN ngat
    GIE     = 1;        //Bat ngat toan cuc
    RBIE    = 1;        //Cho phep ngat RB
    OPTION_REG &= 0x7f; //Keo tro treo cho PORTB
    RBIF    = 0;        //Xoa co ngat
} */
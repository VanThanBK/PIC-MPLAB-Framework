/*
 * File:   Delay.c
 * Author: Van Than
 *
 * Created on July 22, 2017, 10:15 AM
 */
// PIC12F675 Configuration Bit Settings
// 'C' source line config statements
// CONFIG
#pragma config FOSC = INTRCIO   // Oscillator Selection bits (INTOSC oscillator: I/O function on GP4/OSC2/CLKOUT pin, I/O function on GP5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-Up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // GP3/MCLR pin function select (GP3/MCLR pin function is MCLR)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD enabled)
#pragma config CP = OFF         // Code Protection bit (Program Memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <stdlib.h>
#include <stdio.h>

#define _XTAL_FREQ 4000000

#define Start GPIO5
#define Start_dir TRISIO5
#define Stop GPIO4
#define Stop_dir TRISIO4
#define Relay GPIO2
#define Relay_dir TRISIO2
#define SW1 GPIO0
#define SW1_dir TRISIO0
#define SW2 GPIO1
#define SW2_dir TRISIO1

volatile int Time_Delay = 0;
volatile int Buf1s = 0;
volatile int Buf1p = 0;
short Start_Stop = 0;
void TimerInit();
void ReadSW();
void main(void) {
    ReadSW();
    OPTION_REG &= 0x7f;
    CM2 = 1;
    CM1 = 1;
    CM0 = 1;
    Start_dir = 1;
    Stop_dir = 1;
    SW1_dir = 1;
    SW2_dir = 1;
    Relay_dir = 0;
   
    TimerInit();
    
    while(1){
        ReadSW();
        if(Start==0){Start_Stop = 1;Buf1p=0;Buf1s=0;}
        else if(Stop==0){Start_Stop = 0;}
    }
    return;
}
void ReadSW(){                                                  //chinh so phut de lay
    if(SW1==0&&SW2==0){
        Time_Delay = 2;
    } else if(SW1==1&&SW2==0){
        Time_Delay = 3;
    } else if(SW1==0&&SW2==1){
        Time_Delay = 4;
    } else if(SW1==1&&SW2==1){
        Time_Delay = 5;
    }
}

void TimerInit(){
    GIE = 1;
    T0IE = 1;
    PS2 = 0;PS1 = 1;PS0 = 1;
    T0CS = 0;
    PSA = 0;
    T0IF = 0;
    TMR0 = 6;
}
void interrupt Timer0Int(void){
    if(T0IF){
        TMR0 = 6;
        Buf1s ++;
        if(Buf1s > 249){
            Buf1p++;
            Buf1s = 0;
        }
        if(Start_Stop==1){
           if(Buf1p>(Time_Delay*60)){
                Relay = 1;Start_Stop=0;
            } else {
                Relay = 0;
            }
        } else {
            Relay = 1;
        }
        T0IF = 0;
    }
}

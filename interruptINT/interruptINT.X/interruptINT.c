/*
 * File:   interruptINT.c
 * Author: Van Than
 *
 * Created on August 4, 2016, 8:00 AM
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
#include "D:\PIC_MPlap\7SEG\My_7seg.h"
//Valriable
unsigned char i;
//Function
void INTInit();
//Chuong trinh chinh
void main(void){
    PCFG3 = 0;
    PCFG2 = 1;
    PCFG1 = 1;
    PCFG0 = 0;
    /*****************************************
     Khoi dong ngat*/
    INTInit();
    /*****************************************
     Khoi dong 7SEG LED*/
    SegInit();
    i = 0;
    while(1){
        SegNumber(i);
    }
    return;
}
void interrupt ext_int(void){
    if(INTF){
        i++;
        if(i>100) i = 0;
        INTF = 0;
    }
}
/*************************************
 Khoi dong ngat*/
void INTInit(){
    TRISB0  = 1;        //Cau hinh cho PIN ngat
    GIE     = 1;        //Bat ngat toan cuc
    INTE    = 1;        //Cho phep ngat ngoai
    INTEDG  = 0;        //Chon suon ngat (falling time)
    nRBPU = 0;
    INTF    = 0;        //Xoa co ngat
}
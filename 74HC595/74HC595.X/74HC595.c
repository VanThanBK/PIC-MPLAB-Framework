/*
 * File:   74HC595.c
 * Author: Van Than
 *
 * Created on June 7, 2017, 2:42 PM
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
//#include "D:\PIC_MPlap\LCD\MyLCD.h"
//#include "D:\PIC_MPlap\ADC\MyADC.h"
//#include "D:\PIC_MPlap\7SEG\My_7seg.h"

//Dinh nghia cac chan giao tiep
#define SHCP          RE0    //Chan 11
#define STCP          RE1    //Chan 12
#define DS            RE2    //Chan 14
#define SHCP_Dir      TRISE0    //Chan 11
#define STCP_Dir      TRISE1    //Chan 12
#define DS_Dir        TRISE2    //Chan 14
//khai bao ham
void HC595Init();
void Output595(unsigned char dt);
void Output2595(unsigned char dt1, unsigned char dt2);
//*************************************
//Chuong trinh chinh
void main(void){
    /****************************************
     Tat tat ca chuc nang Analog tren cac chan*/
     PCFG3 = 0;
     PCFG2 = 1;
     PCFG1 = 1;
     PCFG0 = 0;
     HC595Init();
    while(1){
        Output595(0x55);
        __delay_ms(100);
        //Output595(0xaa);
        //__delay_ms(100);
    }
    return;
}
void HC595Init(){
 //Config tat ca cac chan la output
 SHCP_Dir = 0;
 STCP_Dir = 0;
 DS_Dir = 0;
 //Keo tro noi len Vcc
 SHCP = 1;
 STCP = 1;
 DS = 1;
}
void Output595(unsigned char dt){
 int i;
 unsigned char ch;
 STCP = 0;
 for(i=0;i<8;i++){
  SHCP = 0;
  ch = dt;
  if((ch&0x80)==0x80) DS = 1;
   else DS =0;
  dt <<= 1;
  __delay_us(1);
  SHCP = 1;
 }
 STCP = 1;
}
void Output2595(unsigned char dt1, unsigned char dt2){
 Output595(dt1);
 Output595(dt2);
}

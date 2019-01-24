/*
 * File:   ADC_Demo.c
 * Author: Van Than
 *
 * Created on October 6, 2016, 7:45 PM
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

#define _XTAL_FREQ 4000000

//Library
#include "D:\PIC_MPlap\LCD\MyLCD.h"
//#include "D:\PIC_MPlap\ADC\MyADC.h"
//#include "D:\PIC_MPlap\7SEG\My_7seg.h"
unsigned int adc;
float Volt = 10;
void main(void) {
    __delay_ms(200);
    LCDInit();
    LCDClear();
    //adcInit();
    LCDPrint(1,4,"Volt meter ");
    LCDPrint(2,1,"Voltage:");
    LCDPrint(2,16,"V");
    while(1){
        //adc = adcRead(0);
        //Volt = ((float)adcRead(0)/1023)*5;
        LCDPrintFNumber(2,10,Volt,2);
        //LCDPrintNumber(2,8,adcRead(0));
    }
    return;
}

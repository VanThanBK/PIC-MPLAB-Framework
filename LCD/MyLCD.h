/********************************************
* LCD Library
* Header file "MyLCD.h"
********************************************/

#define LCD_RS       RD1
#define LCD_RW       RD2
#define LCD_E        RD3
#define LCD_D4       RD4
#define LCD_D5       RD5
#define LCD_D6       RD6
#define LCD_D7       RD7
#define LCD_RS_DDR   TRISD1
#define LCD_RW_DDR   TRISD2
#define LCD_E_DDR    TRISD3
#define LCD_D4_DDR   TRISD4
#define LCD_D5_DDR   TRISD5
#define LCD_D6_DDR   TRISD6
#define LCD_D7_DDR   TRISD7

//char str[15];
void LCDInit(); //Khoi dong LCD
void LCDMode4Bit(); //Chon LCD hoat dong LCD o che do 4 bit
void LCDWriteByte(unsigned char ch);
void LCDWriteData(unsigned char dt);
void LCDWriteCommand(unsigned char dt);
void LCDLatchData();
void LCDClear();
void LCDMove(unsigned char y, unsigned char x);
void LCDPutChar(unsigned char ch);
void LCDPrint(char y, char x, char* str);   //In chuoi ky tu str tai dong x, cot y
void LCDPrintNumber(char y, char x, int num); //Hien thi so nguyen num tai dong x, cot y
void LCDPrintFNumber(char y, char x, float fnum, char f); //Hien thi so thuc fnum o dong x cot y

/********************************************
* Include source file
********************************************/
#include "MyLCD.c"
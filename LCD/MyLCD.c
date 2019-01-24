/********************************************
* LCD Library
* Source file "MyLCD.c"
********************************************/
void LCDInit()
   {
      LCD_RS_DDR  =0;
      LCD_RW_DDR  =0;
      LCD_E_DDR   =0;
      LCD_D4_DDR  =0;
      LCD_D5_DDR  =0;
      LCD_D6_DDR  =0;
      LCD_D7_DDR  =0;
      //__delay_ms(200);
      LCDMode4Bit();
      LCDWriteCommand(0x28);
      LCDWriteCommand(0x0C);
      LCDWriteCommand(0x06);
   }
void LCDMode4Bit()
   {
      LCD_RS=0;
      LCD_RW=0;
      LCD_D4=0;
      LCD_D5=1;
      LCD_D6=0;
      LCD_D7=0;
      LCDLatchData();
   }
void LCDWriteByte(unsigned char ch)
   {
      LCD_D7 = (ch>>7)&0x01;
      LCD_D6 = (ch>>6)&0x01;
      LCD_D5 = (ch>>5)&0x01;
      LCD_D4 = (ch>>4)&0x01;
      LCDLatchData();
      LCD_D7 = (ch>>3)&0x01;
      LCD_D6 = (ch>>2)&0x01;
      LCD_D5 = (ch>>1)&0x01;
      LCD_D4 = ch&0x01;
      LCDLatchData();
   }
void LCDWriteData(unsigned char dt)
   {
      LCD_RS=1;
      //LCD_RW=0;
      LCDWriteByte(dt);
   }
void LCDWriteCommand(unsigned char dt)
   {
      LCD_RS=0;
      //LCD_RW=0;
      LCDWriteByte(dt);
   }
void LCDLatchData()
   {
      //LCD_RW=0;
      LCD_E=1;
      LCD_E=0;
      __delay_ms(2);
   }
void LCDClear()
   {
      LCDWriteCommand(0x01);
   }
void LCDMove(unsigned char y, unsigned char x)
   {
      unsigned int Ad;
      Ad = 64*(y-1)+(x-1)+0x80;
      LCDWriteCommand(Ad);
   }
void LCDPutChar(unsigned char ch)
   {
      LCDWriteData(ch);
   }
void LCDPrint(char y, char x, char *str)
   {
      LCDMove(y,x);
      while(*str)
         {
            LCDPutChar(*str);
            str++;
         }
   }
void LCDPrintNumber(char y, char x, int num)
   {
      char i;
      char str[7];
      //itoa(str,num,16);
      sprintf(str,"%d",num);
      /*while(str[0]==' '){
       for(i=0;i<7;i++){
        if(str[i+1]==0){str[i] = ' '; break;}
        else str[i] = str[i+1];
       }
      }*/
      LCDPrint(y,x,str);
   }
void LCDPrintFNumber(char y, char x, float fnum, char f){
 char i;
 char *str;
 //sprintf(str,"%4.2f",fnum);
 int status=0;
 str = ftoa(fnum, status);
 
 for(i=0;i<15;i++){
  if(str[i] == '.') break;
 }
 i = (i+f+1);
 str[i] = ' ';
 i++;
 while(str[i]){
  str[i] = ' ';
  i++;
 }
 LCDPrint(y,x,str);
}

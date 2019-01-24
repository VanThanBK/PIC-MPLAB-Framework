/********************************************
* LCD Library
* Source file "MyADC.c"
********************************************/

//Khoi dong ADC
void adcInit(){
 //AN0 input
 TRISA0 = 1;
 //AN0 select
 PCFG3 = 1;
 PCFG2 = 1;
 PCFG1 = 1;
 PCFG0 = 0;
 //Chon kenh ADC trong ADC read
 //Chon xung clock = Fosc/16
 ADCS2 = 0;
 ADCS1 = 0;
 ADCS0 = 0;
 //Dinh dang ket qua dich phai
 ADFM = 1;
 //Enable ADC Module
 ADON = 1;
 //Khong su dung ngat
 //Cho mot khoang thoi gian
 __delay_ms(1);
 //Bat dau chuyen doi trong ham ADC read
}
//************************************************
//Doc ADC
unsigned int adcRead(unsigned short channel){
 unsigned int AdcData;
 __delay_us(2);
 switch(channel){
  case 0: {CHS2=0; CHS1=0; CHS0=0; break;}
  case 1: {CHS2=0; CHS1=0; CHS0=1; break;}
  case 2: {CHS2=0; CHS1=1; CHS0=0; break;}
  case 3: {CHS2=0; CHS1=1; CHS0=1; break;}
  case 4: {CHS2=1; CHS1=0; CHS0=0; break;}
  case 5: {CHS2=1; CHS1=0; CHS0=1; break;}
  case 6: {CHS2=1; CHS1=1; CHS0=0; break;}
  case 7: {CHS2=1; CHS1=1; CHS0=1; break;}
 }
 __delay_us(100);
 GO = 1;
 while(GO){}
 __delay_us(100);
 AdcData = ADRESH;
 return (AdcData<<8)|ADRESL;
}
//void adcButton(
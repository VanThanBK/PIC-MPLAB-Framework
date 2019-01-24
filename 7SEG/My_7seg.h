#define SEG_PORT        PORTD
#define SEG_PORT_Dir    TRISD
#define seg_1           RA0
#define seg_1_dir       TRISA0
#define seg_2           RA1
#define seg_2_dir       TRISA1
#define seg_3           RA2
#define seg_3_dir       TRISA2
volatile unsigned int num = 0;
void SegInit();
void SegLed(char num);
void SegNumber(int number);

#include "My_7seg.c"
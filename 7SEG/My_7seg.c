/***********************************************
* 7SEG Library
* Source file "My_7seg.c"
***********************************************/
void SegInit()
    {
        SEG_PORT_Dir     =0x00;
        SEG_PORT         =0xff;
        seg_1_dir        =0;
        seg_2_dir        =0;
        seg_3_dir        =0;
        //seg_4_dir        =0;
        seg_1            =1;
        seg_2            =1;
        seg_3            =1;
        //seg_4            =1;
    }
void SegLed(char num)
    {
        switch(num)
            {
            case 0: {SEG_PORT = 0x03; break;}//so 0
            case 1: {SEG_PORT = 0x9f; break;}//so 1
            case 2: {SEG_PORT = 0x25; break;}//so 2
            case 3: {SEG_PORT = 0x0D; break;}//so 3
            case 4: {SEG_PORT = 0x99; break;}//so 4
            case 5: {SEG_PORT = 0x49; break;}//so 5
            case 6: {SEG_PORT = 0x41; break;}//so 6
            case 7: {SEG_PORT = 0x1f; break;}//so 7
            case 8: {SEG_PORT = 0x01; break;}//so 8
            case 9: {SEG_PORT = 0x09; break;}//so 9
            }
    }
void SegNumber(int number)
    {
        unsigned int a,b,c,d,e;
        //Lay ra tung so de hien thi
        a = (number/10000);
        b = (number - a*10000)/1000;
        c = (number - a*10000 - b*1000)/100;
        d = (number - a*10000 - b*1000 - c*100)/10;
        e = (number - a*10000 - b*1000 - c*100 - d*10);

        //Hien thi len tung Led
        //Led 1
        seg_1=0;
        SegLed(c);
        __delay_ms(2);
        seg_1=1;
        //Led 2
        seg_2=0;
        SegLed(d);
        __delay_ms(2);
        seg_2=1;
        //Led 3
        seg_3=0;
        SegLed(e);
        __delay_ms(2);
        seg_3=1;
    }
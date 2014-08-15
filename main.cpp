#include <fmod.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#define pf printf
void time_main(int,int,int);
void play();
void drawing();
void list();
void change(int);

void TextColor(int color){
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

void col(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}

void wait ( int seconds )
{
    clock_t endwait;
    endwait = clock () + seconds ;
    while (clock() < endwait) {}
}

void co( int x, int y )
{
    COORD p = { x, y };
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p );
}


FSOUND_STREAM *handle;
float a;
int pos;
int main()
{
    system("cls");
    col(6,0);
    drawing();
    FSOUND_Init(44100,32,0);
    int q;
    co(20,5);pf("**************************************");
    co(20,6);pf("**         SELECT YOUR SONG         **");
    co(20,7);pf("**          FORM THE LIST           **");
    co(20,8);pf("**************************************");
    list();
}

void play ()
{
    system("cls");
    drawing();
    col(12,0);
    co(17,16);pf("%c%c%c%c%c%c%c%c%",201,205,205,205,205,205,205,187);
    co(17,17);pf("%c      %c",186,186);
    co(17,18);pf("%c TIME %c",186,186);
    co(17,19);pf("%c      %c",186,186);
    co(17,20);pf("%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,188);
    col(10,0);
    co(61,8); pf("%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,187);
    co(61,9); pf("%c VOLUME %c",186,186);
    co(61,10);pf("%c PRESS  %c",186,186);
    co(61,11);pf("%c %c UP   %c",186,30,186);
    co(61,12);pf("%c %c DOWN %c",186,31,186);
    co(61,13);pf("%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,188);

    co(5,3);pf("Press [SPACE] To Pause.");
    co(8,4);pf("Press [ENTER] To Play.");
    co(4,22);pf("Press [ESC] To Go Back...");
    co(45,18);pf("%c%c%c CHANGE SONG %c%c%c",14,14,14,14,14,14);
    co(35,20);pf(" Press [LEFT ARROW] & [RIGHT ARROW] %c%c%c",14,14,14);
    co(45,10);pf("%c",14);
    co(43,12);pf("%c",14);
    co(42,15);pf("%c",14);
    co(46,13);pf("%c",14);
    co(47,11);pf("%c",14);
    co(40,17);pf("%c",14);
    co(37,18);pf("%c",14);
    co(34,17);pf("%c",14);
    co(30,18);pf("%c",14);
    co(27,19);pf("%c",14);
    //handle=FSOUND_Stream_OpenFile("sample1.mp3",0,0);
    FSOUND_Init(44100,32,0);
    FSOUND_Stream_Play(0,handle);
    //cout<<FSOUND_GetFrequency(FSOUND_ALL);
    col(12,0);
    int o,main_pos=8;
    co(50,16);pf("%c%c%c%c%c%c%c%c%c",220,220,220,220,220,220,220,220,220);
    co(60,16);for(o=15;o>=8;o--){co(50,o);pf("%c %c   %c %c",220,220,220,220);}
    int k=150,d=0,e;
    while(1)
    {
        FSOUND_SetVolume(FSOUND_ALL,k);
        int q;
        while(!_kbhit())
        {
           co(29,22);col(10,0);
            int a,a_i;
            a=FSOUND_Stream_GetTime(handle)/(1000);
            int b=a/60;
            e=a%60;
            if(d==a){
                d=a+1;
                int f,g;
                f=e/10;
                g=e%10;
           co(5,6);for(a_i=6;a_i<=15;a_i++){co(5,a_i);pf("         ");}
           co(5,6);time_main(5,6,b);
           co(16,6);time_main(16,6,10);
           co(20,6);for(a_i=6;a_i<=15;a_i++){co(20,a_i);pf("          ");}
           co(20,6);time_main(20,6,f);
           co(31,6);for(a_i=6;a_i<=15;a_i++){co(31,a_i);pf("          ");}
           co(31,6);time_main(30,6,g);
            }
        }
        q=getch();
        col(12,0);
        if(q==80){
            k-=20;
            if(k<1)k=0;
            main_pos+=1;
            if(main_pos>16)main_pos=16;
        for(o=15;o>=3;o--){co(50,o);pf("           ");}
        for(o=15;o>=main_pos;o--){co(50,o);pf("%c %c   %c %c",220,220,220,220);}
        }
        if(q==72){
        k+=20;
        if(k>250)k=250;
        main_pos-=1;
            if(main_pos<3)main_pos=3;
        for(o=15;o>=3;o--){co(50,o);pf("           ");}
        for(o=15;o>=main_pos;o--){co(50,o);pf("%c %c   %c %c",220,220,220,220);}
        }
        if(q==32){
        FSOUND_SetPaused(FSOUND_ALL,true);
        }
        if(q==13)
        {
        FSOUND_SetPaused(FSOUND_ALL,false);
        }
        if(q==27)
        {
            FSOUND_Close();
            main();
        }
        if(q==75)
        {
            change(75);
        }
        if(q==77)
        {
            change(77);
        }
    }
    getch();
}

void list()
{
    co(30,11);pf("[1]  MANUS MANUSAR JONNA.");
    co(30,13);pf("[2]  CYCOLON.");
    co(30,15);pf("[3]  ANDROID");
    co(30,17);pf("[4]  THE RHYTHEM");
    co(30,19);pf("[5]  WHERE YOU ARE");
    co(30,21);pf("[ ]  EXIT");
    int k=11;
    pos=1;
    co(28,k);pf("%c",16);
    co(0,0);
    key_m:
    while(1)
    {
        int s,a_i;
        s=getch();
        co(0,0);
        switch(s){
        case 72:
        k-=2;pos-=1;
        if(pos<1){k=21;pos=6;}
        co(28,11);for(a_i=11;a_i<=21;a_i++){co(28,a_i);pf("  ");}
        co(28,k);pf("%c",16);
        co(0,0);
        goto key_m;
        case 80:
        k+=2;pos+=1;
        if(pos>6){k=11;pos=1;}
        co(28,11);for(a_i=11;a_i<=21;a_i++){co(28,a_i);pf("  ");}
        co(28,k);pf("%c",16);
        co(0,0);
        goto key_m;
        case 13:
        co(0,0);
        break;
        default:
        goto key_m;
        }

    switch(pos)
    {
        case 1:
        handle=FSOUND_Stream_OpenFile("sample.mp3",0,0);
        play();
        case 2:
        handle=FSOUND_Stream_OpenFile("sample1.mp3",0,0);
        play();
        case 3:
        handle=FSOUND_Stream_OpenFile("android.mp3",0,0);
        play();
        case 4:
        handle=FSOUND_Stream_OpenFile("the_rhythm.mp3",0,0);
        play();
        case 5:
        handle=FSOUND_Stream_OpenFile("where_you_are.mp3",0,0);
        play();
        case 6:
        system("cls");
        exit(EXIT_SUCCESS);
        break;
    }
    if(pos==6)
    break;
    }
}

void change(int c)
{
    if(c==75)
    {
        pos-=1;
        if(pos<1)pos=5;
    }
    if(c==77)
    {
        pos+=1;
        if(pos>5)pos=1;
    }
    switch(pos)
    {
        case 1:
        FSOUND_Close();
        FSOUND_Init(44100,32,0);
        handle=FSOUND_Stream_OpenFile("sample.mp3",0,0);
        FSOUND_Stream_Play(0,handle);
        play();
        case 2:
        FSOUND_Close();
        FSOUND_Init(44100,32,0);
        handle=FSOUND_Stream_OpenFile("sample1.mp3",0,0);
        FSOUND_Stream_Play(0,handle);
        play();
        case 3:
        FSOUND_Close();
        FSOUND_Init(44100,32,0);
        handle=FSOUND_Stream_OpenFile("android.mp3",0,0);
        FSOUND_Stream_Play(0,handle);
        play();
        case 4:
        FSOUND_Close();
        FSOUND_Init(44100,32,0);
        handle=FSOUND_Stream_OpenFile("the_rhythm.mp3",0,0);
        FSOUND_Stream_Play(0,handle);
        play();
        case 5:
        FSOUND_Close();
        FSOUND_Init(44100,32,0);
        handle=FSOUND_Stream_OpenFile("where_you_are.mp3",0,0);
        FSOUND_Stream_Play(0,handle);
        play();
    }
}

void drawing()
{
    int i;
    co(1,1);
    pf("%c",201);for(i=0;i<76;i++)pf("%c",205);
    pf("%c",187);
    for(i=2;i<23;i++)
    {
        co(1,i);pf("%c",186);
        co(78,i);pf("%c",186);
    }
    co(1,23);pf("%c",200);for(i=0;i<76;i++)pf("%c",205);
    co(78,23);pf("%c",188);
}

void time_main(int x,int y,int z)
{
    int k=x,l=y;
    if(z==1){
    co(k,l++);pf("  __   ");
    co(k,l++);pf(" /  \\  ");
    co(k,l++);pf(" \\/) ) ");
    co(k,l++);pf("   | | ");
    co(k,l++);pf("   | | ");
    co(k,l++);pf("   | | ");
    co(k,l++);pf(" __) (_");
    co(k,l++);pf(" \\____/");
    }
if(z==2){
    co(k,l++);pf(" _______ ");
    co(k,l++);pf("/ ___   \)");
    co(k,l++);pf("\\/   \)  |");
    co(k,l++);pf("    /   )");
    co(k,l++);pf("  _/   / ");
    co(k,l++);pf(" /   _/  ");
    co(k,l++);pf("\(   \(__/\\");
    co(k,l++);pf("\\_______/");
}
if(z==3){
    co(k,l++);pf(" ______  ");
    co(k,l++);pf("/ ___  \\ ");
    co(k,l++);pf("\\/   \\  \\");
    co(k,l++);pf("   ___\) /");
    co(k,l++);pf("  \(___ \( ");
    co(k,l++);pf("      \) \\");
    co(k,l++);pf("/\\___/  /");
    co(k,l++);pf("\\______/ ");
}
if(z==4){
    co(k,l++);pf("    ___   ");
    co(k,l++);pf("   /   \)  ");
    co(k,l++);pf("  / /\) |  ");
    co(k,l++);pf(" / \(_\) \(_ ");
    co(k,l++);pf("\(____   _\)");
    co(k,l++);pf("     \) \(  ");
    co(k,l++);pf("     | |  ");
    co(k,l++);pf("     \(_\)  ");
}
if(z==5){
    co(k,l++);pf(" _______ ");
    co(k,l++);pf("\(  ____ \\");
    co(k,l++);pf("| \(    \\/");
    co(k,l++);pf("| \(____  ");
    co(k,l++);pf("\(_____ \\ ");
    co(k,l++);pf("      \) \)");
    co(k,l++);pf("/\\____\) \)");
    co(k,l++);pf("\\______/ ");
}
if(z==6){
    co(k,l++);pf("  ______ ");
    co(k,l++);pf(" / ____ \\");
    co(k,l++);pf("\( \(    \\/");
    co(k,l++);pf("| \(____  ");
    co(k,l++);pf("|  ___ \\ ");
    co(k,l++);pf("| \(   \) \)");
    co(k,l++);pf("\( \(___\) \)");
    co(k,l++);pf(" \\_____/ ");
}
if(z==7){
    co(k,l++);pf(" ______  ");
    co(k,l++);pf("/ ___  \\ ");
    co(k,l++);pf("\\/   \)  \)");
    co(k,l++);pf("    /  / ");
    co(k,l++);pf("   /  /  ");
    co(k,l++);pf("  /  /   ");
    co(k,l++);pf(" /  /    ");
    co(k,l++);pf(" \\_/     ");
}
if(z==8){
    co(k,l++);pf("  _____  ");
    co(k,l++);pf(" / ___ \\ ");
    co(k,l++);pf("\( \(___\) \)");
    co(k,l++);pf(" \\     / ");
    co(k,l++);pf(" / ___ \\ ");
    co(k,l++);pf("\( \(   \) \)");
    co(k,l++);pf("\( \(___\) \)");
    co(k,l++);pf(" \\_____/ ");
}
if(z==9){
    co(k,l++);pf("  _____  ");
    co(k,l++);pf(" / ___ \\ ");
    co(k,l++);pf("\( \(   \) \)");
    co(k,l++);pf("\( \(___\) |");
    co(k,l++);pf(" \\____  |");
    co(k,l++);pf("      \) |");
    co(k,l++);pf("/\\____\) \)");
    co(k,l++);pf("\\______/ ");
}
if(z==0){
    co(k,l++);pf(" _______ ");
    co(k,l++);pf("\(  __   \)");
    co(k,l++);pf("| \(  \)  |");
    co(k,l++);pf("| | /   |");
    co(k,l++);pf("| \(/ /\) |");
    co(k,l++);pf("|   / | |");
    co(k,l++);pf("|  \(__\) |");
    co(k,l++);pf("\(_______\)");
}
if(z==10){
    co(k,l++);pf("   ");
    co(k,l++);pf("   ");
    co(k,l++);pf(" _ ");
    co(k,l++);pf("(_)");
    co(k,l++);pf("   ");
    co(k,l++);pf(" _ ");
    co(k,l++);pf("(_)");
    co(k,l++);pf("   ");
}
}

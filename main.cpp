#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <stdlib.h>
#include <time.h>
#include "buttons.h"
#include <mmsystem.h>
#include <conio.h>
using namespace std;

#define ScreenWidth 1080
#define ScreenHeight 720
//*************************************************USER VARIABLES AREA*************************************************************
POINT pos;
int mX,mY;
bool isClick;
bool init=true;
bool init2=false;
bool onePlayer=false;
bool twoPlayers=false;
bool restart_game=false;
bool NeewGame=false;
bool isStarted=false;
bool Input=true;
bool isClickedSound=false;
bool Sound=true;
bool clicked=false;
bool nextAction=false;
bool incorect=false;
bool restart=false;
bool isClickedInput=false;
bool isNotOver=false;
bool isClickedMenu=false;
bool isClicked1Player =false;
bool reincepere=false;
bool isClicked2Players =false;
bool isClickedExit=false;
bool isTouchingNrMutari=false;
int nr_mutari=0;
int numar;
int nr_introdus=0;
int nr_jocuri=1;
int record=0;
bool firsttime=true;
int nr_actual_mutari;
int nrpermis;
//*/************************************************************************************************************************************


//*************************************************MAIN MENU AREA***************************************************************
bool touching(const int mouseX,const int mouseY,const int x,int y,const int xF,const int yF)
{
    return (mouseX>=x&&mouseX<=xF&&mouseY>=y&&mouseY<=yF);
}

void next_action()
{


    if(ismouseclick(WM_LBUTTONDOWN))
    {

        clearmouseclick(WM_LBUTTONDOWN);
        clicked=true;
        if(Sound)
                PlaySound(TEXT("CLICK.wav"),NULL,SND_SYNC);

        mX=mousex();
        mY=mousey();
        // if( GetAsyncKeyState(VK_LBUTTON))
        //{
        {
            isStarted= touching(mX,mY,150,150,325,250);
            isClickedSound=touching(mX,mY,260,260,435,360);
            if(isClickedSound)
            {
                Sound=!Sound;


            }
            isClickedInput=touching(mX,mY,370,370,545,470);
            if(isClickedInput)
            {
                Input=!Input;
            }
            isClickedExit=touching(mX,mY,480,480,655,580);
            if(isClickedExit)
            {
                isNotOver=true;


            }

        }


    }

}
void compose_title_screen()
{
    setbkcolor(BLACK);
    setcolor(WHITE);
    settextstyle(SCRIPT_FONT,HORIZ_DIR,20);
    outtextxy(230,20,"Bine ai venit !");
    settextstyle(SCRIPT_FONT,HORIZ_DIR,5);
    outtextxy(550,200,"Alege o optiune ");
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
    start_button(150,150);
    sound_button(260,260);
    input_button(370,370);
    exit_button(480,480);
    setbkcolor(BLACK);
    outtextxy(1020,700,"Ver 2.1");
}
void clear_screen(int UpLeftX,int UpLeftY,int BottomRightX,int BottomRightY)

{
    setfillstyle(SOLID_FILL,BLACK);
    bar(UpLeftX,UpLeftY,BottomRightX,BottomRightY);
}

void update_title_screen()
{

    setbkcolor(RED);


    setbkcolor(RED);
    setfillstyle(SOLID_FILL,RED);
    if(init)
    {
        clicked=true;
        init=false;
    }
    if(clicked)
    {

        if(Sound)
        {
            clicked=false;

            //bar(360,350,300,390);
            bar(260,260,435,360);
            outtextxy(300,300,"Sound ");
            outtextxy(360,300,"ON");

        }
        else if(!Sound)
        {
            clicked=false;
            // sound_button(260,260);
            bar(260,260,435,360);
            outtextxy(300,300,"Sound ");
            outtextxy(360,300,"OFF");

        }

        setbkcolor(MAGENTA);
        setfillstyle(SOLID_FILL,MAGENTA);
        if(Input)

        {

            // input_button(370,370);
            clicked=false;

            bar(370,370,545,470);
            outtextxy(400,390,"Metoda de control: \n ");
            outtextxy(430,420,"Tastatura ");
            //S/eep(300);
        }
        else if(!clicked)
        {


            clicked=false;
            // input_button(370,370);
            bar(370,370,545,470);
            outtextxy(400,390,"Metoda de control: \n ");
            outtextxy(430,420,"Mouse");
            //Sleep(300);
        }

    }
}

void Launch_main_menu()
{
    compose_title_screen();



}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//*******************************************************LOADING SCREEN AREA*****************************************************
void launch_loading_screen()
{
    int xaux=406;
    int yaux=700;
    int x=500,y=336;
    bool over=false;
    int v1=0,v2=0,v3=0,num=0,n=0,counter=0;
    setfillstyle(SOLID_FILL,BLACK);

    while(!over)
    {
        putpixel(xaux,yaux,RED);
        putpixel(xaux,yaux-1,RED);
        putpixel(xaux,yaux-2,RED);
        putpixel(xaux,yaux-3,RED);
        putpixel(xaux,yaux-4,RED);
        putpixel(xaux,yaux-5,RED);
        putpixel(xaux,yaux-6,RED);
        putpixel(xaux,yaux-7,RED);
        putpixel(xaux,yaux-8,RED);
        putpixel(xaux,yaux-9,RED);
        putpixel(xaux,yaux-10,RED);

        xaux++;
        counter++;
        bar(1,1,950,650);
        setcolor(LIGHTGRAY);
        if(counter==1)
        {
            outtextxy(500,336,"-");
            outtextxy(500,336,"-");
        }
        if(counter==2)
        {

            outtextxy(500,336,"//");
            outtextxy(500,336,"\\");
        }
        if(counter==3)
        {

            outtextxy(500,336,"|");

        }
        if(counter==4)
        {


            outtextxy(500,336,"/");
        }
        if(counter>4)
            counter=0;


        setcolor(YELLOW);
        outtextxy(470,30,"Loading...");
        setlinestyle(0,0,3);
        setcolor(GREEN);
        arc(x,y,270+v2,90+v2,80);
        setcolor(LIGHTRED);
        arc(x,y,320-v2,120-v2,110);
        arc(x,y,320-v2,120-v2,112);
        setcolor(CYAN);
        arc(x,y,30+v1,160+v1,132);
        setcolor(BLUE);
        arc(x,y,300-v1,40-v1,151);
        setcolor(LIGHTMAGENTA);
        arc(x,y,300+v3,140+v3,171);
        arc(x,y,300+v3,140+v3,173);



        if(num>=100)
        {
            //   Sleep (10000);
            num+=0;
            delay(500);
            clear_screen(1,1,1080,50);
            setcolor(YELLOW);
            outtextxy(430,30,"Loading Completed !!!");
            setcolor(WHITE);
            outtextxy(882,685,"Press any key to continue");
            over=true;
            isStarted=true;
            getch();


        }

        v1+=4+rand()%8;
        v2+=6+rand()%8;
        v3+=6+rand()&8;
        num=num+n;
        n=rand()%2;
        delay(30);
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//********************************************************GAME CODE AREA*********************************************************
bool fara_cifre_identice(int x)
{
    int index,vf[10];
    for(index=0; index<=9; index++) //initializam vectorul cu 0;
        vf[index]=0;
    while(x)
    {
        vf[x%10]++;
        x/=10;
    }
    for(index=0; index<=9; index++)
        if(vf[index]>=2)
            return false;
    return true;
}
int generare_numar()
{
    int x;
dinnou:
    do
    {
        x=rand()%99999+10000;
    }
    while(fara_cifre_identice(x)==false);
    if(x%10==0|| x/10%10==0|| x/100%10==0)
        goto dinnou;
    return x;
}

void e_pe_pozitie(int v1[10],int v2[10],int &nr_poz_id)
{
    nr_poz_id=0;
    for(int index=0; index<5; index++)
        if(v1[index]==v2[index])
            nr_poz_id++;
}
void exista_in_tablou(int v1[10],int v2[10],int &nr_comune)
{

    int i,vf1[10],vf2[10];

    nr_comune=0;

    for(i=0; i<10; i++)
    {
        vf1[i]=0;
        vf2[i]=0;
    }
    for(i=0; i<5; i++)
    {
        vf1[v1[i]]++;
        vf2[v2[i]]++;
    }


    for(i=0; i<=9; i++)
    {
        if(vf1[i]!=0)
            if(vf1[i]==vf2[i])
                nr_comune++;
    }

}
void descompunere_in_tablou(int nr,int v[10])
{
    int index;
    for(index=4; index>=0; index--)
    {
        v[index]=nr%10;
        nr/=10;
    }

}


//////////////////////////////////////////////////////////////GAMEPLAY INTERFACE AREA/////////////////////////////////////////////
void create_border()
{


    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
    setlinestyle(SOLID_LINE,0,20);
    setcolor(BLUE);
    rectangle(0,0,1080,710);
    settextstyle(SCRIPT_FONT,HORIZ_DIR,3);
    setcolor(WHITE);
    // setbkcolor(BLUE);
    outtextxy(450,700,"Cinci cifre");
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
}
void draw_buttons()
{
    exit_button2(980,700);
    main_menu_button(0,700);
    Limita(880,700);
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
    setcolor(WHITE);

    if(Input)
    {
        change_output(100,700);
        outtextxy(115,700," Tastatura ");
    }
    else if(!Input)
    {
        change_output(101,700);
        outtextxy(121,700,"Mouse ");
    }
    setbkcolor(MAGENTA);
    if (firsttime)
   {
     outtextxy(880,700,"Lim. mut. N/E ");
     firsttime=false;}
    else
         if(nr_mutari==25)
                outtextxy(880,700,"Lim. mut. N/E ");
            if(nr_mutari==20)
                outtextxy(880,700,"Lim. mut. 20");
            if(nr_mutari==15)
                outtextxy(880,700,"Lim. mut. 15");
            if(nr_mutari==10)
                outtextxy(880,700,"Lim. mut. 10");
            if(nr_mutari==5)
                outtextxy(880,700,"Lim. mut. 5");

    Restart(200,700);
    NewGame(780,700);
}
void draw_scoreboard()
{

    setlinestyle(SOLID_LINE,0,5);
    setfillstyle(SOLID_FILL,RED);
    bar(10,55,1070,0);
}
void fill_screen()
{

    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(9,14,1069,699);
    setlinestyle(SOLID_LINE,0,2);
    setcolor (BLACK);
    rectangle(10,15,1070,700);

}
void draw_grid()
{
    setlinestyle(SOLID_LINE,0,1);
    setcolor(BLACK);
    setfillstyle(SOLID_FILL,WHITE);
    setbkcolor(WHITE);

    int aux_x=280,aux_y=420;
    char text[2];
    int index=0;
    for(int i=1; i<4; i++)
    {
        aux_y+=75;
        aux_x-=225;
        for(int j=1; j<4; j++)
        {
            index++;
            if(index==1)
                grid_button(aux_x,aux_y,30,"1");

            if(index==2)
                grid_button(aux_x,aux_y,30,"2");

            if(index==3)
                grid_button(aux_x,aux_y,30,"3");

            if(index==4)
                grid_button(aux_x,aux_y,30,"4");

            if(index==5)
                grid_button(aux_x,aux_y,30,"5");

            if(index==6)
                grid_button(aux_x,aux_y,30,"6");

            if(index==7)
                grid_button(aux_x,aux_y,30,"7");

            if(index==8)
                grid_button(aux_x,aux_y,30,"8");

            if(index==9)
                grid_button(aux_x,aux_y,30,"9");
            aux_x+=75;



        }
    }
}
void additional_text()
{

    settextstyle(SCRIPT_FONT,HORIZ_DIR,3);
    setbkcolor(RED);
    setcolor(YELLOW);
    outtextxy(25,1,"Jocul nr. ");
    outtextxy(450,1,"Cinci Cifre");

    outtextxy(960,1,"Record");



}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////INTERACTIVE INTERFACE AREA///////////////////////////////////////////
void numar_introdus()
{
    setcolor(BLACK);
    setbkcolor(LIGHTGRAY);
    settextstyle(BOLD_FONT,HORIZ_DIR,4);
    outtextxy(30,130,"NUMARUL ");
    outtextxy(70,160,"INTRODUS: ");
    outtextxy(30,380,"Introduceti numarul: ");
    setbkcolor(BLACK);
    setlinestyle(SOLID_LINE,0,1);
    for(int i=0; i<250; i+=50)
    {
        cifra_input(255+i,200);
    }
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
}
void change_a_bunch_of_buttons()
{
    if(ismouseclick(WM_LBUTTONDOWN))
    {

        clearmouseclick(WM_LBUTTONDOWN);
        clicked=true;
        mX=mousex();
        mY=mousey();
        //cout<<mX<<" "<<mY;
        isClickedExit=touching(mX,mY,980,700,1080,770);
        isTouchingNrMutari=touching(mX,mY,880,700,980,770);
        if(isTouchingNrMutari)
        {
            if(Sound)
                PlaySound(TEXT("CLICK.wav"),NULL,SND_SYNC);
            settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
            isTouchingNrMutari=false;
            nr_mutari+=5;
            Limita(880,700);
            setbkcolor(MAGENTA);
            if(nr_mutari==25)
                outtextxy(880,700,"Lim. mut. N/E ");
            if(nr_mutari==20)
                outtextxy(880,700,"Lim. mut. 20");
            if(nr_mutari==15)
                outtextxy(880,700,"Lim. mut. 15");
            if(nr_mutari==10)
                outtextxy(880,700,"Lim. mut. 10");
            if(nr_mutari==5)
                outtextxy(880,700,"Lim. mut. 5");
            if(nr_mutari>25)
                nr_mutari=0;
        }
        restart=touching(mX,mY,200,700,300,770);
        if(restart&& clicked)
        {
            if(Sound)
                PlaySound(TEXT("CLICK.wav"),NULL,SND_SYNC);
            nr_jocuri++;
            restart_game=true;
        }
        NeewGame=touching(mX,mY,780,700,880,770);
        if(NeewGame && clicked)
        {
            if(Sound)
                PlaySound(TEXT("CLICK.wav"),NULL,SND_SYNC);

            clicked=false;
            isClick=true;
            clear_screen(1,1,1080,1080);

        }
        isClickedMenu=touching(mX,mY,0,700,100,770);
        if(clicked&& isClickedMenu)
        {
            if(Sound)
                PlaySound(TEXT("CLICK.wav"),NULL,SND_SYNC);

            clear_screen(1,1,1080,1080);
            reincepere=true;
        }
        isNotOver=touching(mX,mY,980,700,1080,770);
        if(isNotOver)
        {

            if(Sound)
                PlaySound(TEXT("CLICK.wav"),NULL,SND_SYNC);
            closegraph();
        }
    }

}
void introducere_numar_tastatura()  // este nevoie de conditie de opriere la 5 cifre
{
    setbkcolor(LIGHTGRAY);
    setcolor(BLACK);
    char c;
    c=getch();
    if(Sound)
        PlaySound(TEXT("CLICK.wav"),NULL,SND_SYNC);


    if((int)c==49)
    {

        nr_introdus=nr_introdus*10+1;
        // nr_introdus/=10;
        if(nr_introdus<10)
            outtextxy(275,215,"1");
        else if(nr_introdus<100)

            outtextxy(325,215,"1");
        else if(nr_introdus<1000)

            outtextxy(375,215,"1");
        else if(nr_introdus<10000)

            outtextxy(425,215,"1");
        else if(nr_introdus<100000)

            outtextxy(475,215,"1");

    }
    if((int)c==50)
    {

        nr_introdus=nr_introdus*10+2;
        // nr_introdus/=10;
        if(nr_introdus<10)
            outtextxy(275,215,"2");
        else if(nr_introdus<100)

            outtextxy(325,215,"2");
        else if(nr_introdus<1000)

            outtextxy(375,215,"2");
        else if(nr_introdus<10000)

            outtextxy(425,215,"2");
        else if(nr_introdus<100000)

            outtextxy(475,215,"2");

    }
    if((int)c==51)
    {


        nr_introdus=nr_introdus*10+3;
        //  nr_introdus/=10;
        if(nr_introdus<10)
            outtextxy(275,215,"3");
        else if(nr_introdus<100)

            outtextxy(325,215,"3");
        else if(nr_introdus<1000)

            outtextxy(375,215,"3");
        else if(nr_introdus<10000)

            outtextxy(425,215,"3");
        else if(nr_introdus<100000)

            outtextxy(475,215,"3");
    }


    if((int)c==52)
    {

        nr_introdus=nr_introdus*10+4;
        //nr_introdus/=10;
        if(nr_introdus<10)
            outtextxy(275,215,"4");
        else if(nr_introdus<100)

            outtextxy(325,215,"4");
        else if(nr_introdus<1000)

            outtextxy(375,215,"4");
        else if(nr_introdus<10000)

            outtextxy(425,215,"4");
        else if(nr_introdus<100000)

            outtextxy(475,215,"4");

    }
    if((int)c==53)
    {
        nr_introdus=nr_introdus*10+5;
        // nr_introdus/=10;
        if(nr_introdus<10)
            outtextxy(275,215,"5");
        else if(nr_introdus<100)

            outtextxy(325,215,"5");
        else if(nr_introdus<1000)

            outtextxy(375,215,"5");
        else if(nr_introdus<10000)

            outtextxy(425,215,"5");
        else if(nr_introdus<100000)

            outtextxy(475,215,"5");

    }
    if((int)c==54)
    {
        nr_introdus=nr_introdus*10+6;
        // nr_introdus/=10;
        if(nr_introdus<10)
            outtextxy(275,215,"6");
        else if(nr_introdus<100)

            outtextxy(325,215,"6");
        else if(nr_introdus<1000)

            outtextxy(375,215,"6");
        else if(nr_introdus<10000)

            outtextxy(425,215,"6");
        else if(nr_introdus<100000)

            outtextxy(475,215,"6");

    }
    if((int)c==55)
    {
        nr_introdus=nr_introdus*10+7;
        // nr_introdus/=10;
        if(nr_introdus<10)
            outtextxy(275,215,"7");
        else if(nr_introdus<100)

            outtextxy(325,215,"7");
        else if(nr_introdus<1000)

            outtextxy(375,215,"7");
        else if(nr_introdus<10000)

            outtextxy(425,215,"7");
        else if(nr_introdus<100000)

            outtextxy(475,215,"7");

    }
    if((int)c==56)
    {

        nr_introdus=nr_introdus*10+8;
        // nr_introdus/=10;
        if(nr_introdus<10)
            outtextxy(275,215,"8");
        else     if(nr_introdus<100)

            outtextxy(325,215,"8");
        else if(nr_introdus<1000)

            outtextxy(375,215,"8");
        else  if(nr_introdus<10000)

            outtextxy(425,215,"8");
        else if(nr_introdus<100000)

            outtextxy(475,215,"8");

    }
    if((int)c==57)
    {
        nr_introdus=nr_introdus*10+9;
        //nr_introdus/=10;
        if(nr_introdus<10)
            outtextxy(275,215,"9");
        else  if(nr_introdus<100)

            outtextxy(325,215,"9");
        else if(nr_introdus<1000)

            outtextxy(375,215,"9");
        else if(nr_introdus<10000)

            outtextxy(425,215,"9");
        else if(nr_introdus<100000)

            outtextxy(475,215,"9");

    }

}
void introducere_numar_mouse()
{
    setbkcolor(LIGHTGRAY);
    setcolor(BLACK);
    if(ismouseclick(WM_LBUTTONDOWN))
    {

        clearmouseclick(WM_LBUTTONDOWN);
        mX=mousex();
        mY=mousey();

        // touched1=touching(mX,mY,25,460,85,520);
        if(touching(mX,mY,25,460,85,520))
        {
            if(Sound)
                PlaySound(TEXT("CLICK.wav"),NULL,SND_SYNC);


            nr_introdus=nr_introdus*10+1;
            if(nr_introdus<10)
                outtextxy(275,215,"1");
            else if(nr_introdus<100)

                outtextxy(325,215,"1");
            else if(nr_introdus<1000)

                outtextxy(375,215,"1");
            else if(nr_introdus<10000)

                outtextxy(425,215,"1");
            else if(nr_introdus<100000)

                outtextxy(475,215,"1");

        }
        if(touching(mX,mY,100,460,160,520))
        {
            if(Sound)
                PlaySound(TEXT("CLICK.wav"),NULL,SND_SYNC);


            nr_introdus=nr_introdus*10+2;
            if(nr_introdus<10)
                outtextxy(275,215,"2");
            else if(nr_introdus<100)

                outtextxy(325,215,"2");
            else if(nr_introdus<1000)

                outtextxy(375,215,"2");
            else if(nr_introdus<10000)

                outtextxy(425,215,"2");
            else if(nr_introdus<100000)

                outtextxy(475,215,"2");

        }
        if(touching(mX,mY,175,460,235,520))
        {
            if(Sound)
                PlaySound(TEXT("CLICK.wav"),NULL,SND_SYNC);


            nr_introdus=nr_introdus*10+3;
            if(nr_introdus<10)
                outtextxy(275,215,"3");
            else if(nr_introdus<100)

                outtextxy(325,215,"3");
            else if(nr_introdus<1000)

                outtextxy(375,215,"3");
            else if(nr_introdus<10000)

                outtextxy(425,215,"3");
            else if(nr_introdus<100000)

                outtextxy(475,215,"3");
        }


        if(touching(mX,mY,25,540,85,600))
        {
            if(Sound)
                PlaySound(TEXT("CLICK.wav"),NULL,SND_SYNC);


            nr_introdus=nr_introdus*10+4;
            if(nr_introdus<10)
                outtextxy(275,215,"4");
            else if(nr_introdus<100)

                outtextxy(325,215,"4");
            else if(nr_introdus<1000)

                outtextxy(375,215,"4");
            else if(nr_introdus<10000)

                outtextxy(425,215,"4");
            else if(nr_introdus<100000)

                outtextxy(475,215,"4");

        }
        if(touching(mX,mY,100,540,160,600))
        {
            if(Sound)
                PlaySound(TEXT("CLICK.wav"),NULL,SND_SYNC);

            nr_introdus=nr_introdus*10+5;
            if(nr_introdus<10)
                outtextxy(275,215,"5");
            else if(nr_introdus<100)

                outtextxy(325,215,"5");
            else if(nr_introdus<1000)

                outtextxy(375,215,"5");
            else if(nr_introdus<10000)

                outtextxy(425,215,"5");
            else if(nr_introdus<100000)

                outtextxy(475,215,"5");

        }
        if(touching(mX,mY,175,540,235,600))
        {
            if(Sound)
                PlaySound(TEXT("CLICK.wav"),NULL,SND_SYNC);

            nr_introdus=nr_introdus*10+6;
            if(nr_introdus<10)
                outtextxy(275,215,"6");
            else if(nr_introdus<100)

                outtextxy(325,215,"6");
            else if(nr_introdus<1000)

                outtextxy(375,215,"6");
            else if(nr_introdus<10000)

                outtextxy(425,215,"6");
            else if(nr_introdus<100000)

                outtextxy(475,215,"6");

        }
        if(touching(mX,mY,25,615,85,675))
        {
            if(Sound)
                PlaySound(TEXT("CLICK.wav"),NULL,SND_SYNC);

            nr_introdus=nr_introdus*10+7;
            if(nr_introdus<10)
                outtextxy(275,215,"7");
            else if(nr_introdus<100)

                outtextxy(325,215,"7");
            else if(nr_introdus<1000)

                outtextxy(375,215,"7");
            else if(nr_introdus<10000)

                outtextxy(425,215,"7");
            else if(nr_introdus<100000)

                outtextxy(475,215,"7");

        }
        if(touching(mX,mY,100,615,160,675))
        {
            if(Sound)
                PlaySound(TEXT("CLICK.wav"),NULL,SND_SYNC);


            nr_introdus=nr_introdus*10+8;
            if(nr_introdus<10)
                outtextxy(275,215,"8");
            else     if(nr_introdus<100)

                outtextxy(325,215,"8");
            else if(nr_introdus<1000)

                outtextxy(375,215,"8");
            else  if(nr_introdus<10000)

                outtextxy(425,215,"8");
            else if(nr_introdus<100000)

                outtextxy(475,215,"8");

        }
        if(touching(mX,mY,175,615,235,675))
        {
            if(Sound)
                PlaySound(TEXT("CLICK.wav"),NULL,SND_SYNC);

            nr_introdus=nr_introdus*10+9;
            if(nr_introdus<10)
                outtextxy(275,215,"9");
            else  if(nr_introdus<100)

                outtextxy(325,215,"9");
            else if(nr_introdus<1000)

                outtextxy(375,215,"9");
            else if(nr_introdus<10000)

                outtextxy(425,215,"9");
            else if(nr_introdus<100000)

                outtextxy(475,215,"9");

        }
    }

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////ONE PLAYER GAMEPLAY AREA////////////////////////////////////////////

void launch_one_player_gameplay()
{
    if(Sound)
        if(nr_jocuri==1)
    PlaySound(TEXT("Startup.wav"),NULL,SND_SYNC);
    fill_screen();
    create_border();
    draw_buttons();
    draw_scoreboard();
    draw_grid();
    additional_text();
    //Sleep(1500);

    numar_introdus();
    numar=generare_numar();
    char recordt[10];
    itoa(record,recordt,10);
    char nrjoc[10];
    itoa(nr_jocuri,nrjoc,10);
    setbkcolor(RED);
    setcolor(YELLOW);
     outtextxy(130,1,nrjoc);
     settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
    settextstyle(SCRIPT_FONT,HORIZ_DIR,3);
    setbkcolor(RED);
    setcolor(YELLOW);
    outtextxy(960,25,recordt);
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
    if(!Input)
    {
        nr_actual_mutari=0;
        int v_nr_de_aflat[10],v_nr_introdus[10];
        descompunere_in_tablou(numar,v_nr_de_aflat);
        bool over=false;
        while(!over)
        {
            nr_introdus=0;
            while(nr_introdus<9999)
            {
                introducere_numar_mouse();
                if(!(fara_cifre_identice(nr_introdus)))
                {
                    nr_introdus=0;
                    setbkcolor(LIGHTGRAY);
                    setcolor(BLACK);
                    outtextxy(255,255,"NUMARUL INTRODUS NU TREBUIE SA AIBA CIFRE IDENTICE! REINTRODU NUMARUL! ");
                    if(Sound)
                        PlaySound(TEXT("ERROR.wav"),NULL,SND_SYNC);

                    Sleep(1000);
                    setfillstyle(SOLID_FILL,LIGHTGRAY);
                    bar(255,255,1000,280);

                    setfillstyle(SOLID_FILL,LIGHTGRAY);
                    bar(255,135,1000,280);
                    for(int i=0; i<250; i+=50)
                    {
                        cifra_input(255+i,200);
                    }


                }
            }


            nrpermis++;

            if(nr_mutari!=25)
                if(nrpermis>nr_mutari && nr_mutari!=0)
            {
                over=true;
               // settextstyle(SCRIPT_FONT,HORIZ_DIR,3);
                outtextxy(440,385,"Ai depasit numarul de mutari...Reincepe jocul. ");

           while(!nextAction)
                {

                    change_a_bunch_of_buttons();
                    nextAction=true;
                }

            }
            descompunere_in_tablou(nr_introdus,v_nr_introdus);

            int nr_poz_identice,nr_comune;
            e_pe_pozitie(v_nr_de_aflat,v_nr_introdus,nr_poz_identice);
            for(int i=0; i<5; i++)
                cout<<v_nr_de_aflat[i]<<" ";
            for(int i=0; i<5; i++)
                cout<<v_nr_introdus[i]<<" ";
            exista_in_tablou(v_nr_de_aflat,v_nr_introdus,nr_comune);
            char ind1[10],ind2[10];
            itoa(nr_poz_identice,ind1,10);
            itoa(nr_comune,ind2,10);

            outtextxy (70,255,"Numarul de cifre pe pozitii identice este: ");
            outtextxy(350,255,ind1);
            outtextxy(100,285,"Numarul de cifre comune este: " );
            outtextxy(320,285,ind2);
            change_a_bunch_of_buttons();
            Sleep(1500);
            if(nr_poz_identice<5)
            {
                nr_actual_mutari++;
                setfillstyle(SOLID_FILL,LIGHTGRAY);
                bar(20,200,1000,350);
                for(int i=0; i<250; i+=50)
                {
                    cifra_input(255+i,200);
                }
            }
            cout<<numar;
            if(nr_poz_identice==5)
            {
                if(record==0)
                    record=nr_actual_mutari;
                if(nr_actual_mutari<record)
                    record=nr_actual_mutari;
                over=true;

               // settextstyle(SCRIPT_FONT,HORIZ_DIR,3);
                outtextxy(420,385,"Felicitari, ai incheiat cu succes jocul!!! " );
                //outtextxy(620,285,ind2);
                if(Sound)
                    PlaySound(TEXT("TADA.wav"),NULL,SND_SYNC);

                Sleep(2000);
                settextstyle(BOLD_FONT,HORIZ_DIR,3);
                restartG_button(480,480);
                while(!nextAction)
                {

                    change_a_bunch_of_buttons();
                    nextAction=true;
                }




            }

        }


    }


    else
    {
        nr_actual_mutari=0;
        int v_nr_de_aflat[10],v_nr_introdus[10];
        descompunere_in_tablou(numar,v_nr_de_aflat);
        bool over=false;
        while(!over)
        {
            nr_introdus=0;
            while(nr_introdus<9999)
            {
                introducere_numar_tastatura();
                if(!(fara_cifre_identice(nr_introdus)))
                {
                    nr_introdus=0;
                    setbkcolor(LIGHTGRAY);
                    setcolor(BLACK);
                    outtextxy(255,255,"NUMARUL INTRODUS NU TREBUIE SA AIBA CIFRE IDENTICE! REINTRODU NUMARUL! ");
                    if(Sound)
                        PlaySound(TEXT("ERROR.wav"),NULL,SND_SYNC);

                    Sleep(1000);
                    setfillstyle(SOLID_FILL,LIGHTGRAY);
                    bar(255,255,1000,280);

                    setfillstyle(SOLID_FILL,LIGHTGRAY);
                    bar(255,135,1000,280);
                    for(int i=0; i<250; i+=50)
                    {
                        cifra_input(255+i,200);
                    }


                }
            }

             nrpermis++;

            if(nr_mutari!=25)
                if(nrpermis>nr_mutari&& nr_mutari !=0)
            {
                over=true;
                //settextstyle(SCRIPT_FONT,HORIZ_DIR,3);
                outtextxy(440,385,"Ai depasit numarul de mutari...Reincepe jocul. ");

            while(!nextAction)
                {

                    change_a_bunch_of_buttons();
                    nextAction=true;
                }

            }

            descompunere_in_tablou(nr_introdus,v_nr_introdus);

            int nr_poz_identice,nr_comune;
            e_pe_pozitie(v_nr_de_aflat,v_nr_introdus,nr_poz_identice);
            for(int i=0; i<5; i++)
                cout<<v_nr_de_aflat[i]<<" ";
            for(int i=0; i<5; i++)
                cout<<v_nr_introdus[i]<<" ";
            exista_in_tablou(v_nr_de_aflat,v_nr_introdus,nr_comune);
            char ind1[10],ind2[10];
            itoa(nr_poz_identice,ind1,10);
            itoa(nr_comune,ind2,10);
            outtextxy (70,255,"Numarul de cifre pe pozitii identice este: ");
            outtextxy(350,255,ind1);
            outtextxy(100,285,"Numarul de cifre comune este: " );
            outtextxy(320,285,ind2);
            change_a_bunch_of_buttons();
            Sleep(1500);
            if(nr_poz_identice<5)
            {
                nr_actual_mutari++;
                setfillstyle(SOLID_FILL,LIGHTGRAY);
                bar(20,200,1000,350);
                for(int i=0; i<250; i+=50)
                {
                    cifra_input(255+i,200);
                }
            }
            cout<<numar;
            if(nr_poz_identice==5)
            {
                if(record==0)
                    record=nr_actual_mutari;
                if(nr_actual_mutari<record)
                    record=nr_actual_mutari;
                over=true;

                settextstyle(SCRIPT_FONT,HORIZ_DIR,3);
                outtextxy(420,385,"Felicitari, ai incheiat cu succes jocul!!! " );
                //outtextxy(620,285,ind2);
                if(Sound)
                    PlaySound(TEXT("TADA.wav"),NULL,SND_SYNC);



                Sleep(2000);
                settextstyle(BOLD_FONT,HORIZ_DIR,3);
                restartG_button(480,480);
                while(!nextAction)
                {


                    /*  if(ismouseclick(WM_LBUTTONDOWN))
                      clearmouseclick(WM_LBUTTONDOWN);
                      mX=mousex();
                      mY=mousey();
                        change_a_bunch_of_buttons();
                        if(touching(mX,mY,480,480,655,580))
                          {
                              nextAction=true;
                              restart=true;
                          }*/
                    change_a_bunch_of_buttons();
                    nextAction=true;
                }
                /*
                      while(!nextAction)
                                {


                        if(ismouseclick(WM_LBUTTONDOWN))
                        clearmouseclick(WM_LBUTTONDOWN);
                        mX=mousex();
                        mY=mousey();
                          change_a_bunch_of_buttons();
                          if(touching(mX,mY,480,480,655,580))
                            {
                                nextAction=true;
                                restart=true;
                            }
                          }
                */
            }

        }


    }

}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////GAME MODE AREA///////////////////////////////////////////////////////
void choose_game_mode()
{
    setbkcolor(BLACK);
    settextstyle(SCRIPT_FONT,HORIZ_DIR,5);


    outtextxy(6,3,"Alege modul de joc: ");
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
    if(ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        clicked=true;
        mX=mousex();
        mY=mousey();
        if(Sound)
            PlaySound(TEXT("CLICK.wav"),NULL,SND_SYNC);

    }
    isClicked1Player=touching(mX,mY,140,220,315,320);
    isClicked2Players=touching(mX,mY,650,220,825,320);
    isStarted=touching(mX,mY,300,600,665,680);
    if(isStarted)
    {
        if(onePlayer==false && twoPlayers==false)
        {
            setbkcolor(BLACK);
            outtextxy(380,380,"Trebuie sa selectati o optiune! ");
            isStarted=false;
        }
        else
        {
            clicked=false;

        }
    }
    if(isClicked1Player)
        if(init)
        {
            onePlayer=-onePlayer;
            init=false;
        }

    if(isClicked2Players)
        if(init)
        {
            init=false;
            twoPlayers=-twoPlayers;
        }

    if(!init)
    {
        if(isClicked1Player)
        {
            onePlayer=true;
            twoPlayers=false;
        }
        if(isClicked2Players)
        {
            onePlayer=false;
            twoPlayers=true;
        }

    }

    if(init2)
    {
        init2=false;
        if(!onePlayer)
            one_player_button_free(140,220);
        else
            one_player_button_pressed(142,222);
        if(!twoPlayers)
            two_players_button_free(650,220);
        else
            two_players_button_pressed(652,222);
        incepe_jocul(300,600);

    }
    if(!init2)

        if(clicked&&(isClicked1Player|| isClicked2Players))
        {
            clear_screen(50,50,1080,720);
            if(!onePlayer)
            {
                one_player_button_free(140,220);
                clicked=false;
            }
            else if(onePlayer)
            {
                clicked=false;
                one_player_button_pressed(142,222);
            }
            if(!twoPlayers)
            {
                clicked=false;
                two_players_button_free(650,220);
            }
            else if(twoPlayers)
            {
                clicked=false;
                two_players_button_pressed(652,222);
            }
            incepe_jocul(300,600);
            clicked=false;
        }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
//    PlaySound(TEXT("Name.wav"),NULL,SND_SYNC);

    initwindow(ScreenWidth,ScreenHeight);
Reincepere:
    clear_screen(1,1,1080,1080);
    isStarted=false;
    isNotOver=false;
    nr_jocuri=1;
    Launch_main_menu();
    while(!isStarted && !isNotOver)
    {

        next_action();
        update_title_screen();
    }
newGame:
    nrpermis=0;
    //  isStarted=true;
    if(isStarted)
    {
        clear_screen(1,1,1080,720);
        choose_game_mode();
        isStarted=false;
        init=true;
        init2=true;
    }

    while(!isStarted)
    {
        choose_game_mode();
    }
    isStarted=false;


    clear_screen(1,1,1080,720);
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
    if(!isStarted)
    {
        launch_loading_screen();
    }

Restart:
    clear_screen(1,1,1080,720);
    setbkcolor(BLACK);
    nrpermis=0;
    if(onePlayer)
    {
        launch_one_player_gameplay();
        onePlayer=false;
        isNotOver=false;

        while(!isNotOver)
        {
            change_a_bunch_of_buttons();
            numar_introdus();

            if(reincepere)
            {
                isNotOver=true;
                reincepere=false;
                goto Reincepere;
            }
            if(isClick)
            {
                isNotOver=true;
                isClick=false;

                goto newGame;

            }
            if(restart_game)
            {
                isNotOver=true;
                restart_game=false;
                onePlayer=true;
                goto Restart;
            }

        }
    }
    if(twoPlayers)
    {
        //  launch_two_players_gameplay();
        twoPlayers=false;
        cout<<"2p";
    }

    getch();
    closegraph();
    return 0;


}







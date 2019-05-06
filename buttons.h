#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <string.h>
void draw_full_rectangle(unsigned const int starting_pointX,unsigned const int starting_pointY,const int dimension_x,const int dimension_y, char color[])
{
    if(strcmp(color,"red")==0)
    for(int i=starting_pointX;i<starting_pointX+dimension_x;i++)
      for(int j=starting_pointY;j<starting_pointY+dimension_y;j++)
         putpixel(i,j,RED);
         if(strcmp(color,"green")==0)
    for(int i=starting_pointX;i<starting_pointX+dimension_x;i++)
      for(int j=starting_pointY;j<starting_pointY+dimension_y;j++)
         putpixel(i,j,LIGHTGREEN);
         if(strcmp(color,"blue")==0)
    for(int i=starting_pointX;i<starting_pointX+dimension_x;i++)
      for(int j=starting_pointY;j<starting_pointY+dimension_y;j++)
         putpixel(i,j,BLUE);
    if(strcmp(color,"lightblue")==0)
    for(int i=starting_pointX;i<starting_pointX+dimension_x;i++)
      for(int j=starting_pointY;j<starting_pointY+dimension_y;j++)
         putpixel(i,j,LIGHTBLUE);
         if(strcmp(color,"yellow")==0)
    for(int i=starting_pointX;i<starting_pointX+dimension_x;i++)
      for(int j=starting_pointY;j<starting_pointY+dimension_y;j++)
         putpixel(i,j,YELLOW);
         if(strcmp(color,"magenta")==0)
    for(int i=starting_pointX;i<starting_pointX+dimension_x;i++)
      for(int j=starting_pointY;j<starting_pointY+dimension_y;j++)
         putpixel(i,j,MAGENTA);

         if(strcmp(color,"lightmagenta")==0)
    for(int i=starting_pointX;i<starting_pointX+dimension_x;i++)
      for(int j=starting_pointY;j<starting_pointY+dimension_y;j++)
         putpixel(i,j,LIGHTMAGENTA);
         if(strcmp(color,"gray")==0)
    for(int i=starting_pointX;i<starting_pointX+dimension_x;i++)
      for(int j=starting_pointY;j<starting_pointY+dimension_y;j++)
         putpixel(i,j,LIGHTGRAY);
}
void start_button(unsigned const int x,unsigned const int y)
{
    draw_full_rectangle(x,y,175,100,"green");
setbkcolor(LIGHTGREEN);

    outtextxy(225,190,"Start");

}

void sound_button(unsigned const int x,unsigned const int y)
{
    setbkcolor(RED);
    draw_full_rectangle(x,y,175,100,"red");
        outtextxy(300,300,"Sound ");


}
void exit_button(unsigned const int x,unsigned const int y)
{

     setbkcolor(BLUE);
    draw_full_rectangle(x,y,175,100,"blue");

    outtextxy(555,510,"Exit");
}
void input_button(unsigned const int x,unsigned const int y)
{
    setbkcolor(MAGENTA);
    draw_full_rectangle(x,y,175,100,"magenta");

    outtextxy(400,390,"Metoda de control: \n ");

}
void one_player_button_free(unsigned const int x,unsigned const int y)
{
    setbkcolor(LIGHTBLUE);
    draw_full_rectangle(x,y,175,100,"lightblue");

    outtextxy(191,252,"Un jucator");

}
void one_player_button_pressed(unsigned const int x,unsigned const int y)
{
    setbkcolor(BLUE);
    draw_full_rectangle(x,y,170,95,"blue");

    outtextxy(193,252,"Un jucator");

}
void two_players_button_free(unsigned const int x,unsigned const int y)
{
    setbkcolor(LIGHTMAGENTA);
    draw_full_rectangle(x,y,175,100,"lightmagenta");

    outtextxy(701,252,"Doi jucatori");

}
void two_players_button_pressed(unsigned const int x,unsigned const int y)
{
    setbkcolor(MAGENTA);
    draw_full_rectangle(x,y,170,95,"magenta");

    outtextxy(701,252,"Doi jucatori");
}
void incepe_jocul(unsigned const int x,unsigned const int y)
{
    setbkcolor(RED);
    draw_full_rectangle(x,y,365,80,"red");

    outtextxy(450,610,"Incepe jocul! ");
}
void exit_button2(unsigned const int x,unsigned const int y)
{
    setbkcolor(RED);
    draw_full_rectangle(x,y,100,80,"red");

    outtextxy(1020,700," EXIT ");

}
void main_menu_button(unsigned const int x,unsigned const int y)
{
    setbkcolor(MAGENTA);
    draw_full_rectangle(x,y,100,80,"magenta");

    outtextxy(15,700," MENIU ");
}
void grid_button(unsigned int x,unsigned int y,unsigned const int radius,char text[])
{
    fillellipse(x,y,radius,radius);
    outtextxy(x,y,text);

}
void change_output(unsigned const int x,unsigned const int y)
{
    setbkcolor(LIGHTBLUE);
    draw_full_rectangle(x,y,100,80,"lightblue");


}
void Limita(unsigned const int x,unsigned const int y)
{
    setbkcolor(MAGENTA);
    draw_full_rectangle(x,y,100,80,"magenta");

    outtextxy(15,700," MENIU ");
}
void Restart(unsigned const int x,unsigned const int y)
{
    setbkcolor(RED);
    draw_full_rectangle(x,y,100,80,"red");

    outtextxy(220,700," Restart");
}
void NewGame(unsigned const int x,unsigned const int y)
{
    setbkcolor(LIGHTGRAY);
    draw_full_rectangle(x,y,100,80,"gray");

    outtextxy(790,700," NewGame ");
}
void cifra_input(unsigned const int x,unsigned const int y)
{
    setcolor(BLACK);
    rectangle(x,y,x+50,y+50);
}
void restartG_button(unsigned const int x,unsigned const int y)
{
//    setfillstyle(SOLID_FILL,LIGHTGRAY);

  //   setbkcolor(LIGHTGRAY);
    // setcolor(LIGHTGRAY);
    //draw_full_rectangle(x,y,175,100,"blue");
    //outtextxy(515,510,"Restart");
    ;
}

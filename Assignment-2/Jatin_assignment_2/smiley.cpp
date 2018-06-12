#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<time.h>
using namespace std;

void drawSmile(int x,int y)
{
    // Face Circle
    setcolor(YELLOW);
    circle(x, y, 50);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(x, y, YELLOW);

    // Left Eye
    setcolor(BLACK);
    circle(x-20, y-15, 7);
    setfillstyle(SOLID_FILL,BLACK);
    floodfill(x-20, y-15, BLACK);

    // Right Eye
    setcolor(BLACK);
    circle(x+20, y-15,7);
    setfillstyle(SOLID_FILL,BLACK);
    floodfill(x+20, y-15, BLACK);

    // Smile
    setcolor(BLACK);
    line(x-25,y+24,x+25,y+24);
    line(x-25,y+25,x+25,y+25);
    line(x-25,y+26,x+25,y+26);
}


int mainSmiley()
{

    initwindow(800,600);
    int randomNumberX;
    int randomNumberY;

    while(1)
    {
        srand(time(NULL));
        randomNumberX = (rand()%600) + 100;
        randomNumberY = (rand()%400) + 100;
        drawSmile(randomNumberX,randomNumberY);
        delay(1000);
        cleardevice();
    }
    getch();
    closegraph();
}

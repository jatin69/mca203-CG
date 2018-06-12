#include<iostream>
#include<graphics.h>
#include<conio.h>
using namespace std;


void drawAxis()
{
    // Y-Axis
    line(100,100,100,500);
    // X-Axis
    line(100,500,600,500);
}

void drawBars()
{
    // drawing Bars
    setfillstyle(WIDE_DOT_FILL,YELLOW);
    bar(150,500,200,200);

    setfillstyle(CLOSE_DOT_FILL,WHITE);
    bar(225,500,275,300);

    setfillstyle(WIDE_DOT_FILL,GREEN);
    bar(300,500,350,250);

    setfillstyle(CLOSE_DOT_FILL,BLUE);
    bar(375,500,425,175);

    setfillstyle(CLOSE_DOT_FILL,CYAN);
    bar(450,500,500,275);
}

int mainBarChart()
{
    initwindow(800,600);
    drawAxis();
    drawBars();
    getch();
    closegraph();
    return 0;
}

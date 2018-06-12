#include<iostream>
#include <graphics.h>
#include <dos.h>
using namespace std;

void makeCar(int x1,int x2) {
    // Road
    line(0,615,1280,615);
    line(0,616,1280,616);
    line(0,617,1280,617);


    // Car
    line(x1,600,x2,575);
    line(x1,575,x2+10,575);
    line(x1+10,575,x2+20,550);
    line(x1+20,550,x2+120,550);
    line(x1+120,550,x2+130,575);
    line(x1+130,575,x2+140,575);
    line(x1+140,575,x2+140,600);
    line(x1+140,600,x2+120,600);
    line(x1+20,600,x2,600);
    circle(x1+105,600,15);
    line(x1+90,600,x2+50,600);
    circle(x1+35,600,15);
}


void makeTrafficSignal() {
    setcolor(WHITE);
    rectangle(825,50,875,130);
    line(849,0,849,50);
    line(850,0,850,50);
    line(851,0,851,50);

    // red circle
    circle(850,65,10);

    // yellow circle
    circle(850,90,10);

    // green circle
    circle(850,115,10);

}


void greenLight() {
    setcolor(GREEN);
    circle(850,115,10);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(850, 115,GREEN);
    setcolor(WHITE);
}


void redLight() {
    setcolor(RED);
    circle(850,65,10);
    setfillstyle(SOLID_FILL,RED);
    floodfill(850, 65,RED);
    setcolor(WHITE);
}


void yellowLight() {
    setcolor(YELLOW);
    circle(850,90,10);
    setfillstyle(SOLID_FILL,YELLOW);
    floodfill(850, 90,YELLOW);
    setcolor(WHITE);
}


void moveCar(bool slow=false,bool stop=false,int pos = 20) {
    int i;
    if(slow==true || stop == true) {
        for(i=pos; i<900; i++) {
            makeCar(i,i);
            makeTrafficSignal();
            greenLight();
            delay(15);
            cleardevice();
            if(i == 700) {
                break;
            }

            if(GetAsyncKeyState('r') ||GetAsyncKeyState('R')) {
                goto stopLabel;
            }

            else if(GetAsyncKeyState('y') ||GetAsyncKeyState('Y')) {
                goto slowLabel;
            }

            else if(GetAsyncKeyState('g') ||GetAsyncKeyState('G')) {
                moveCar(false,false,i);
            }

        }
    }

    else {
        for(i=pos; i<900; i++) {
            makeCar(i,i);
            makeTrafficSignal();
            greenLight();
            delay(15);
            cleardevice();
            if(i == 700) {
                /// stop the car at the end
                break;
            }

            if(GetAsyncKeyState('r') ||GetAsyncKeyState('R')) {
                goto stopLabel;
            }

            else if(GetAsyncKeyState('y') ||GetAsyncKeyState('Y')) {
                goto slowLabel;
            }

            else if(GetAsyncKeyState('g') || GetAsyncKeyState('G')) {
                moveCar(false,false,i);
            }
        }
    }

stopLabel:
    makeCar(i,i);
    makeTrafficSignal();
    redLight();
    getch();
    moveCar(false,true,i);


slowLabel:
    makeCar(i,i);
    makeTrafficSignal();
    yellowLight();
    getch();
    moveCar(true,false,i);
}


int maintraffic() {
    initwindow(900,700);
    int temp;
    moveCar();
    getch();
    closegraph();
    return 0;
}

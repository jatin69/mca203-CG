/*
Program - Mid Point Circle Algorithm
By - Jatin Rohilla
*/

#include <dos.h>
#include <graphics.h>
#include <iostream>
#include <math.h>

using namespace std;
int main() {
  int gd = DETECT, gm;

  int xc = 300, yc = 250; // center coordinates
  int rad;
  int x = 0;
  cout << "\nEnter the radius of circle : ";
  cin >> rad;
  // initwindow(1000,800);      // can also do this
  initgraph(&gd, &gm, "C:\\TurboC3\\BGI");

  int y = rad;
  int d = floor(1.25 * rad);
  putpixel(xc, yc, WHITE);
  while (x <= y) {
    if (d < 0) {
      d += ((2 * x) + 3);
      x++;
    } else {
      d += (2 * (x - y)) + 5;
      x++;
      y--;
    }
    putpixel(xc + x, yc + y, 15); // 8 way symmetry
    putpixel(xc + x, yc - y, 15);

    putpixel(xc - x, yc + y, 15);
    putpixel(xc - x, yc - y, 15);

    putpixel(xc + y, yc + x, 15);
    putpixel(xc + y, yc - x, 15);

    putpixel(xc - y, yc + x, 15);
    putpixel(xc - y, yc - x, 15);
    delay(5);
  }
  getch();
  closegraph();
  return 0;
}

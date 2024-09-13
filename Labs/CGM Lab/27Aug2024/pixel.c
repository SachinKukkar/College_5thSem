#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main() {
    int gd = DETECT , gm;
    initgraph(&gd,&gm,(char*)"");
    putpixel(40,50);
    getch();
    closegraph();
    
}
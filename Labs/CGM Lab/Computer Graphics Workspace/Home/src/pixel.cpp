#include <graphics.h>

int main() {
    int gd = DETECT , gm , color;
    initgraph(&gd,&gm,(char*)"");
    putpixel(40,50,RED);
    putpixel(150,180,BLUE);
    putpixel(90,100,GREEN);
    putpixel(200,300,YELLOW);
    
    getch();
    closegraph();
    return 0;
}
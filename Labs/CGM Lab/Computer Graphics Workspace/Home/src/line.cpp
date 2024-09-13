#include<iostream>
#include<graphics.h>
using namespace std;

int main() {
     int gd = DETECT,gm,color;
    initgraph(&gd,&gm,(char*)"");

    int x1,x2,y1,y2;
    cout<<"Enter the value of x1 and y1 : ";
    cin>>x1>>y1;

    cout<<"Enter the value of x2 and y2 : ";
    cin>>x2>>y2;

    int dx = x2-x1;
    int dy = y2-y1;

    float m = (float)dy/dx;
    float c = y1-(m*x1);

    if(m<=1) {
        for(int x = x1;x<x2;x++) {
            int y= m*x + c ;
            putpixel(x,y,BLUE);
        }
    }
    else {
        for(int y = y1;y<y2;y++) {
            int x = (y-c)/m;
            putpixel(x,y,GREEN);
        }
    }
getch();
closegraph();
    
    return 0;
}
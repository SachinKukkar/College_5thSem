#include <graphics.h>
#include<iostream>


void Bresenham(int x1, int y1, int x2, int y2)
{
	int dx = abs(x1 - x2), dy = abs(y1 - y2);
	int p = 2*dy - dx;
	int twoDy = 2*dy, twoDyDx = 2*(dy - dx);
	int x, y, xEnd;
	/*Determine which points to start and End */
	if(x1>x2){
	   x = x2;
	   y = y2;
	   xEnd = x1;
	}
	else{
	  x = x1; y = y1 ; xEnd =  x2;
	}
	putpixel(x, y, WHITE);
	while(x < xEnd){
	   x++;
	   if(p<0){
	     p = p + twoDy;
	   }
	   else{
	     y++;
	     p = p + twoDyDx;
	   }
	   putpixel(x,y,GREEN);
	}

}

int main()
{
    int gd=DETECT, gm, err;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    err = graphresult();
    if(err!=grOk){
	       printf(" error: %s\n", grapherrormsg(err));
    }
    Bresenham(100, 5, 200, 110);
    getch();
    return 0;
}
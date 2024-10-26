#include <iostream>
#include <graphics.h>
using namespace std;

void bresenhamLine(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    
    int x = x1, y = y1;
    int p = 2 * dy - dx;  // Initial decision parameter

    putpixel(x, y, WHITE);  // Draw the starting pixel

    while (x < x2) {
        x++;
        
        if (p < 0) {
            p = p + 2 * dy;
        } else {
            y++;
            p = p + 2 * dy - 2 * dx;
        }
        
        putpixel(x, y, WHITE);  // Draw the pixel at the current coordinates
    }
}

int main() {
    int gd = DETECT, gm;
    
    // Initialize the graphics mode
    initgraph(&gd, &gm, "");

    // Input the coordinates of the line
    int x1 = 100, y1 = 100, x2 = 200, y2 = 150;

    // Call Bresenham's line drawing function
    bresenhamLine(x1, y1, x2, y2);

    // Wait for user input to close the graphics window
    getchar();

    // Close the graphics mode
    closegraph();

    return 0;
}

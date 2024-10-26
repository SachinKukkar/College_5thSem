#include <graphics.h>
#include <iostream>
#include <cmath>

void plotEllipsePoints(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}

void drawEllipse(int xc, int yc, int a, int b) {
    int x = 0, y = b;
    float p1 = b * b - a * a * b + 0.25 * a * a;

    // Region 1
    while (2.0 * b * b * x <= 2.0 * a * a * y) {
        plotEllipsePoints(xc, yc, x, y);
        if (p1 < 0) {
            p1 += 2.0 * b * b * (++x) + b * b;
        } else {
            p1 += 2.0 * b * b * (++x) - 2.0 * a * a * (--y) + b * b;
        }
    }

    // Region 2
    float p2 = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b;
    while (y > 0) {
        plotEllipsePoints(xc, yc, x, y);
        if (p2 > 0) {
            p2 += -2.0 * a * a * (--y) + a * a;
        } else {
            p2 += 2.0 * b * b * (++x) - 2.0 * a * a * (--y) + a * a;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc = 200; // Center X
    int yc = 200; // Center Y
    int a = 100;  // Semi-major axis
    int b = 50;   // Semi-minor axis

    drawEllipse(xc, yc, a, b);
    
    getch();
    closegraph();
    return 0;
}

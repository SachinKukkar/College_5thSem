#include <graphics.h>
#include <conio.h>
#include <stdio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1, y1, x2, y2;
    printf("Enter the value of x1 and y1: ");
    scanf("%d%d", &x1, &y1);
    printf("Enter the value of x2 and y2: ");
    scanf("%d%d", &x2, &y2);

    int dx = x2 - x1;
    int dy = y2 - y1;

    // Preventing integer division by converting to float
    float m = (float)dy / dx;
    float c = y1 - (m * x1);

    if (abs(dx) >= abs(dy)) {
        for (int x = x1; x <= x2; x++) {
            int y = m * x + c;
            putpixel(x, y, WHITE);
        }
    } else {
        for (int y = y1; y <= y2; y++) {
            int x = (y - c) / m;
            putpixel(x, y, WHITE);
        }
    }

    getch();
    closegraph();
    return 0;
}

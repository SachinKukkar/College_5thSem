#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    // Set the color for the circle
    setcolor(RED);  // You can use any predefined color or an RGB value

    // Draw the circle
    circle(200, 200, 150);

    getch();
    closegraph();
    return 0;
}

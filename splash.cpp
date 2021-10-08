#include <iostream>
#include <conio.h>
#include <Xgeii.h>

using namespace std;

void splash()
{
    window w = create_splash(680, 384, 425, 100, "splash", blue);

    // Lettres en  jaune :
    change_color(w, yellow);
    //P
    draw_line(w, 25, 25, 25, 75);
    draw_line(w, 25, 25, 45, 37);
    draw_line(w, 25,49, 45, 37);

    //I
    draw_line(w, 105, 25, 105, 75);

    //S
    draw_line(w, 165, 25, 185, 25);
    draw_line(w, 165, 25, 165, 50);
    draw_line(w, 185, 50, 185, 75);
    draw_line(w, 165, 50, 185, 50);
    draw_line(w, 165, 75, 185, 75);
    //N
    draw_line(w, 245, 75, 245, 25);
    draw_line(w, 245, 25, 265, 75);
    draw_line(w, 265, 75, 265, 25);
    //C
    draw_line(w, 325, 25, 325, 75);
    draw_line(w, 325, 25, 345, 25);
    draw_line(w, 325, 75, 345, 75);
    draw_line(w, 325, 50, 345, 50);


    //lettres en rouge :
    change_color(w, red);
    //U
    draw_line(w, 65, 25, 65, 75);
    draw_line(w, 65, 75, 85, 75);
    draw_line(w, 85, 25, 85, 75);
    //S
    draw_line(w, 125, 25, 145, 25);
    draw_line(w, 125, 25, 125, 50);
    draw_line(w, 145, 50, 145, 75);
    draw_line(w, 125, 50, 145, 50);
    draw_line(w, 125, 75, 145, 75);
    //A
    draw_line(w, 205, 75, 215, 25);
    draw_line(w, 215, 25, 225, 75);
    draw_line(w, 210, 50, 220, 50);
    //C
    draw_line(w, 285, 25, 285, 75);
    draw_line(w, 285, 25, 305, 25);
    draw_line(w, 285, 75, 305, 75);
    //4
    draw_line(w, 365, 25, 365, 50);
    draw_line(w, 365, 50, 385, 50);
    draw_line(w, 375, 25, 375, 75);

    getch();
    close_window(w);
}

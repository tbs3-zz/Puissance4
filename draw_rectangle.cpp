#include <iostream>
#include <conio.h>
#include <Xgeii.h>

using namespace std;

void draw_rectangle(window window, unsigned int pos_x, unsigned int pos_y, unsigned int width, unsigned int height){
    draw_line(window, pos_x, pos_y, pos_x, pos_y+height);
    draw_line(window, pos_x, pos_y, pos_x+width, pos_y);
    draw_line(window, pos_x+width, pos_y, pos_x+width, pos_y+height);
    draw_line(window, pos_x, pos_y+height, pos_x+width, pos_y+height);

}

void draw_rectangle_full(window window, unsigned int pos_x, unsigned int pos_y, unsigned int width, unsigned int height){
    unsigned int i;
    for(i=0 ; i<=height ; i++){
        draw_line(window, pos_x, pos_y+i, pos_x+width, pos_y+i);
    }
}


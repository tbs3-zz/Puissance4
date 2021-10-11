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

void draw_board(window window){
    int a = 0, b = 0;
    change_color(window, blue);
    draw_rectangle_full(window, 50, 50, 700, 600);

    change_color(window, white);
    for(int l=0 ; l<=5 ; l++){
    for(int i=0; i<=6 ;i++){
        draw_disk(window, 100+a, 100+b, 40);
        a+=100;
    }
    b += 100;
    a=0;
    }
}
void put_jeton(window window, unsigned short num_ligne, unsigned short num_colonne, unsigned short num_joueur){
    if(num_joueur == 1){
        change_color(window, yellow);
    }
    else {
        change_color(window, red);
    }
    draw_disk(window, num_colonne*100, 700-num_ligne*100, 40);
}

short is_valid(unsigned short tableau[][7], unsigned short num_colonne){
    short num_ligne=1;
    if(num_colonne <1 || num_colonne >7){
        return -1;
    }
    while(num_ligne <= 6 && tableau[6-num_ligne][num_colonne-1] != 0){
        num_ligne++;
    }

    return num_ligne<=6?num_ligne:-1;
}

void affiche_tableau(unsigned short tab[][7]){
    for(int i=0;i<6;i++){
            for(int j=0;j<7;j++){
                cout << tab[i][j] << " ";
            }
            cout << endl;
        };
}

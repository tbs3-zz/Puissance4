#include <iostream>
#include <conio.h>
#include <Xgeii.h>
#include <puissance4.h>
using namespace std;

unsigned short end_of_game(unsigned short t[][7], unsigned short c, unsigned short j, unsigned short l);

int main(){
    //Déclarations du tableau représentant le plateau et des différentes variables
    unsigned short plateau[6][7] = {{0}};
    unsigned short num_colonne, num_joueur=1, end;
    short num_ligne;

    //Appel de la fonction affichant le splash & fermeture lors d'un appui sur une touche
    splash();

    //Déclaration de la fenêtre plateau de jeu
    window w = create_window(100, 100, 800, 700, "Puissance 4", black);

    //Appel de la fonction qui dessine le plateau de jeu
    draw_board(w);


    while(true){
        //saisie de la colonne jouée
        do{
            cout << "Entrez un numéro de colonne valide" << endl;
              cin >> num_colonne;
            num_ligne = is_valid(plateau, num_colonne);
            cout << "num_ligne : " << num_ligne << endl;
          } while(num_ligne <0);

          if(num_ligne != -1){
          //vérif' et placement dans la colonne jouée à la ligne la plus basse disponible
              put_jeton(w, num_ligne, num_colonne, num_joueur);
              plateau[6-num_ligne][num_colonne-1] = num_joueur;
            } else
                cout << "Colonne pleine, rejouez votre coup." << endl;

          end = end_of_game(plateau,num_colonne, num_joueur, num_ligne);
          cout << "end_of_game() = " << end << endl;

          if(end != 0){
            if(end == 1){
                cout << "le joueur " << num_joueur << " a gagné" << endl;
                break;
            }
          }
          //changement de joueur & retour aux conditions initiales du test de ligne dispo
          num_joueur = !(num_joueur-1)+1;
          cout << "Au tour du joueur " << num_joueur << endl;
          num_ligne=1;
      }
          getch();
          close_window(w);
          return 0;
      }

unsigned short end_of_game(unsigned short t[][7], unsigned short c, unsigned short j,unsigned short l){
    int l0 = l, alig=0, c0;
    //col
    if(l0>=4){
        alig = 0;
        while(l0 >= 1 && t[6-l0][c-1] == j){
            cout << "l0 : " <<l0 << " tab : " << t[6-l0][c-1] << endl ;
            alig++;
            l0--;
    }}
    if(alig >=4){
        return 1;
    }
    //lig
    c0 = c;
    alig = 0;
    while(c0>=0 && t[6-l][c0-1] == j){
                  c0--;
                  alig++;
              }
    if(alig >=4){
        return 1;
    }
    c0 = c+1;
              while(c0 <= 6 && t[6-l][c0] == j){
                  c0++;
                  alig++;
              }
              if(alig >=4){
                  return 1;
              }

    //diaggd
    c0 = c;
    l0 = l;
    alig = 0;
    while(c0>=1 && l0 >=1 && t[6-l0][c0] == j){
                  c0--;
                  l0--;
                  alig++;
              }
    c0 = c+1;
    l0=l+1;
    while(c0 <= 7 && l0 <= 6 && t[6-l0][c0] == j){
                  l0++;
                  c0++;
                  alig++;
              }
    if(alig >=4){
                  return 1;
              }
    //diagdg
    c0 = c;
    l0 = l;
    alig = 0;
    while(c0<=7 && l0 >=1 && t[6-l0][c0] == j){
                  c0++;
                  l0--;
                  alig++;
              }
    c0 = c-1;
    l0=l+1;
    while(c0 >=1 && l0 <= 6 && t[6-l0][c0] == j){
                  l0++;
                  c0--;
                  alig++;
              }
    if(alig >=4){
                  return 1;
              }
    return 0;
}

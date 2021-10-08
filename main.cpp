#include <iostream>
#include <conio.h>
#include <Xgeii.h>
#include <puissance4.h>
using namespace std;

unsigned short end_of_game(unsigned short t[][7], unsigned short c, unsigned short j, unsigned short num_ligne);

int main()
{
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
        }while(num_ligne <0);

        if(num_ligne != -1){
        //vérif' et placement dans la colonne jouée à la ligne la plus basse disponible
            put_jeton(w, num_ligne, num_colonne, num_joueur);
            if(num_joueur == 1){
                plateau[num_ligne-1][num_colonne-1] = num_joueur;
            }
            if(num_joueur == 2){
                plateau[num_ligne-1][num_colonne-1] = num_joueur;
            }

        //affichage du tableau (debug)
        affiche_tableau(plateau);

        end=end_of_game(plateau, num_colonne, num_joueur, num_ligne);
        if(end != 0){
            if(end == 1){
            cout << "le joueur " << num_joueur << " a gagné" << endl;
            break;
            }

            break;
        }

        //changement de joueur & retour aux conditions initiales du test de ligne dispo
        num_joueur = !(num_joueur-1)+1;
        cout << "Au tour du joueur " << num_joueur << endl;
        num_ligne=1;
        }
        else
            cout << "Colonne pleine, rejouez votre coup." << endl;
    }

    getch();
    close_window(w);
    return 0;
}

unsigned short end_of_game(unsigned short t[][7], unsigned short c, unsigned short j,unsigned short num_ligne){
    int l = num_ligne-1; //align=0;

    //ligne gauche
    if(t[l][c] == j && t[l-1][c] == j && t[l-2][c] == j && t[l-3][c] == j){
        return 1;
    }
    //ligne droite
    if(t[l][c] == j && t[l+1][c] == j && t[l+2][c] == j && t[l+3][c] == j){
        return 1;
    }
    //colonne haut
    if(t[l][c] == j && t[l][c+1] == j && t[l][c+2] == j && t[l][c+3] == j){
        return 1;
    }
    //colonne bas
    if(t[l][c] == j && t[l][c-1] == j && t[l][c-2] == j && t[l][c-3] == j){
        return 1;
    }
    //diag bas gauche
    if(t[l][c] == j && t[l-1][c-1] == j && t[l-2][c-2] == j && t[l-3][c-3] == j){
        return 1;
    }
    //diag haut droit
    if(t[l][c] == j && t[l+1][c+1] == j && t[l+2][c+2] == j && t[l+3][c+3] == j){
        return 1;
    }
    //diag bas droit
    if(t[l][c] == j && t[l+1][c-1] == j && t[l+2][c-2] == j && t[l+3][c-3] == j){
        return 1;
    }
    //diag haut gauche
    if(t[l][c] == j && t[l-1][c+1] == j && t[l-2][c+2] == j && t[l-3][c+3] == j){
        return 1;
    }
    if(is_valid(t, 1) == -1 && is_valid(t, 2) == -1 && is_valid(t, 3) == -1 && is_valid(t, 4) == -1 && is_valid(t, 5) == -1 && is_valid(t, 6) == -1 && is_valid(t, 7) == -1){
        return 2;
    }
   /* do {
        if(t[l][c] == j){
            align++;
            l--;
        }
        else{
            align=0;
        }
    } while(l<=5 && align!=0);
    if(align==4){
        return 1;
    } */

    return 0;
}

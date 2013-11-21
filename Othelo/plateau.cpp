#include <iostream>
#include "Othelo.h"

using namespace std;

Plateau::Plateau()
{
	for( int i=0; i<64; i++)
	{
		liste_cases[i] = NULL;
	}
	int nb_pions_blancs = 0;
	int nb_pions_noirs = 0;

}

void Plateau::afficher()
{
	for( int i =0; i<8; i++)
	{ 
		cout<<"|";
		for( int j=0; j<8; j++)
		{
			cout<<liste_cases[i*8+j]<<"|";
		}
		cout<<endl;
	}
			
}

bool Plateau::action_possible ( Humain joueur, int x, int y )
{
    // Pour chaque direction possible (Gauche, Bas, Droite, Haut, Droite/Haut, Droite/bas, Gauche/haut, etc)
    for(int dx = -1; dx < 2; dx++) {
        for(int dy = -1; dy < 2; dy++) {
            // Si on est au bord du plateau
            if(x + dx > 8 || y + dy > 8) {
                continue;
            }
            // Si le pion juste à côté est de la couleur adverse
            if(liste_cases[x+dx+8*(y+dy)] == abs(joueur.couleur-1)) {
                // On continue dans cette direction tant qu'on ne rencontre pas un bord ou un pion de la couleur du joueur
                while(x + dx < 9 && y + dy < 9) {
                    if(liste_cases[x+dx+8*(y+dy)] == joueur.couleur) {
                        return true;
                    }
                    else {
                        dy += dy;
                        dx += dx;
                    }
                }
            }
        }
    }
    return false;
}
	
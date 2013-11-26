#include "Othelo.h"



Plateau::Plateau()
{
	for( int i=0; i<64; i++)
	{
		liste_cases[i] = -1;
	}

	liste_cases[27] = 0;
	liste_cases[28] = 1;
	liste_cases[35] = 1;
	liste_cases[36] = 0;

	int nb_pions_blancs = 2;
	int nb_pions_noirs = 2;

}

void Plateau::afficher()
{
	cout<<endl;

	for( int i =0; i<8; i++)
	{ 
		cout<<"|";
		for( int j=0; j<8; j++)
		{
			if ( liste_cases[i*8+j]== 0)
				cout<<"0"<<"|";
			else if ( liste_cases[i*8+j]== 1)
				cout<<"1"<<"|";
			else if ( liste_cases[i*8+j]== -1)
				cout<<"-"<<"|";
			
		}
		cout<<endl;
	}
			
}

bool Plateau::action_possible ( Joueur* joueur, int x, int y )
{
    
    int test2 = x+8*y;
    int test = liste_cases[x+8*y];

	int v = 0;
    
	if( joueur == NULL || x == -1 || y == -1)
		return false;
	else if ( liste_cases[x+8*y] != -1)
		return false;
	else
	{
		// Pour chaque direction possible (Gauche, Bas, Droite, Haut, Droite/Haut, Droite/bas, Gauche/haut, etc)
		for(int dx = -1; dx < 2; dx++) {
			for(int dy = -1; dy < 2; dy++) {
				// Si on est au bord du plateau
				if(x + dx >= 8 || y + dy >= 8 || (dx==0 && dy==0) ) {
					continue;
				}
				// Si le pion juste à côté est de la couleur adverse
				if(liste_cases[x+dx+8*(y+dy)] == abs(joueur->color-1)) 
				{
					
					// On continue dans cette direction tant qu'on ne rencontre pas un bord ou un pion de la couleur du joueur
					v = 1;

					while(x + v*dx < 8 && y + v*dy < 8) 
					{
						if(liste_cases[x+v*dx+8*(y+v*dy)] == joueur->color) 
						{
							return true;
						}
						else 
						{
							v++;
						}
					}

				}
			}
		}
		return false;
	}
}

bool Plateau::fin_de_jeu ( Joueur* joueur )
{
    return false;
    
	bool fin = true;

	for( int i=0; i<8; i++)
	{
		for( int j=0; j<8; j++)
		{
			if( liste_cases[i*8+j] == -1 )
			{
				if (action_possible ( joueur, i, j ))
					fin = false;
			}
		}
	}

	return fin;

}

void Plateau::ajouter_pion ( Joueur* joueur, int x, int y)
{
    liste_cases[x+8*y]= joueur->color;
    
    for(int dx = -1; dx < 2; dx++) {
        
        for(int dy = -1; dy < 2; dy++) {
            // Si on est au bord du plateau
            if(x + dx >= 8 || y + dy >= 8 || (dx==0 && dy==0) ) {
                continue;
            }
            // Si le pion juste à côté est de la couleur adverse
            if(liste_cases[x+dx+8*(y+dy)] == abs(joueur->color-1))
            {
                
                // On continue dans cette direction tant qu'on ne rencontre pas un bord ou un pion de la couleur du joueur
                int v = 1;
                
                while(x + v*dx < 8 && y + v*dy < 8)
                {
                    // Quand on rencontre une case du joueur, on fait marche arrière en convertissant tous les pions sur notre passage
                    if(liste_cases[x+v*dx+8*(y+v*dy)] == joueur->color)
                    {
                        while(v != 0) {
                            liste_cases[x+v*dx+8*(y+v*dy)] = joueur->color;
                            v--;
                        }
                        break;
                    } else {
                        v++;
                    }
                }
                
            }
        }
    }
}
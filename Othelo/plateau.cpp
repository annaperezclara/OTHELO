#include "Othelo.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

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

void Plateau::afficher(sf::RenderWindow *fenetre)
{
	cout<<" ";

	for( int i =0; i<8; i++)
		cout<<" "<<i+1;

	cout<<endl;

	for( int i =0; i<8; i++)
	{ 
		cout<<i+1<<"|";
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
    cout<<endl;


	fenetre->clear();
	sf::CircleShape shape(10.f);

	for( int i =0; i<8; i++)
	{ 
		cout<<i+1<<"|";
		for( int j=0; j<8; j++)
		{
			if ( liste_cases[i*8+j]== 0)
			{
				shape.setFillColor(sf::Color::Red);
				shape.setPosition((float)j*100+50,(float)i*100+50);
				fenetre->draw(shape);
			}
			else if ( liste_cases[i*8+j]== 1)
			{
				shape.setFillColor(sf::Color::Green);
				shape.setPosition((float)j*100+50,(float)i*100+50);
				fenetre->draw(shape);
			}
			else if ( liste_cases[i*8+j]== -1)
			{
				shape.setFillColor(sf::Color::White);
				shape.setPosition((float)j*100+50,(float)i*100+50);
				fenetre->draw(shape);
			}
		}
		cout<<endl;
	}


    fenetre->display();


}

bool Plateau::action_possible ( Joueur* joueur, int x, int y )
{

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
				if(liste_cases[x+dx+8*(y+dy)] == abs(joueur->couleur-1))
				{
					
					// On continue dans cette direction tant qu'on ne rencontre pas un bord ou un pion de la couleur du joueur
					v = 1;

                    while(x+v*dx >= 0 && x + v*dx < 8 && y + v*dy < 8 && y+v*dy >= 0)
					{
						if(liste_cases[x+v*dx+8*(y+v*dy)] == joueur->couleur)
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

    //on parcourt toutes les cases pour verifier qu'une action est possible
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
    liste_cases[x+8*y]= joueur->couleur;
    
    for(int dx = -1; dx < 2; dx++) {
        
        for(int dy = -1; dy < 2; dy++) {
            // Si on est au bord du plateau
            if(x + dx >= 8 || y + dy >= 8 || (dx==0 && dy==0) ) {
                continue;
            }
            // Si le pion juste à côté est de la couleur adverse
            if(liste_cases[x+dx+8*(y+dy)] == abs(joueur->couleur-1))
            {
                
                // On continue dans cette direction tant qu'on ne rencontre pas un bord ou un pion de la couleur du joueur
                int v = 1;
                
                while(x+v*dx >= 0 && x + v*dx < 8 && y + v*dy < 8 && y+v*dy >= 0)
                {
                    // Quand on rencontre une case du joueur, on fait marche arrière en convertissant tous les pions sur notre passage
                    if(liste_cases[x+v*dx+8*(y+v*dy)] == joueur->couleur)
                    {
                        while(v != 0) {
                            liste_cases[x+v*dx+8*(y+v*dy)] = joueur->couleur;
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
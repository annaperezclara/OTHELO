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
	//for( int i=0; i<64; i++)
	//{
	//	liste_cases[i] = 1;
	//}

	//liste_cases[27] = -1;
	//liste_cases[28] = 0;
	//liste_cases[35] = -1;
	//liste_cases[36] = -1;

	int nb_pions_blancs = 2;
	int nb_pions_noirs = 2;

}

void Plateau::calcul_score()
{
    nb_pions_blancs=0;
    nb_pions_noirs=0;

	for(int i=0; i<64; i++)
	{
		if( liste_cases[i] == 1)
			nb_pions_blancs++;
		if( liste_cases[i] == 0)
			nb_pions_noirs++;
	}
}


bool Plateau::calcul_vainqueur()
{
	if( nb_pions_blancs>nb_pions_noirs)
		return true;
	else
		return false;
}


void Plateau::afficher(sf::RenderWindow *fenetre, std::string joueur1, std::string joueur2)
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
    
    float radius = 20.0f;
    float padding = 5.0f;
    float width = 8*2*(radius+padding);
	float score = 30.;

    fenetre->setSize(sf::Vector2u(width, width+score));
    fenetre->clear(sf::Color(12, 138, 89));
    
    sf::RectangleShape line(sf::Vector2f(width, 2));
    line.setFillColor(sf::Color::Black);
    
    for (int i = 1; i <= 8; i++) {
        line.setPosition(0, 2*(radius+padding)*i);
        fenetre->draw(line);
    }

    line.setSize(sf::Vector2f(2, width));
    
    for (int i = 1; i < 8; i++) {
        line.setPosition(2*(radius+padding)*i, 0);
        fenetre->draw(line);
    }
    
	sf::CircleShape circle(radius);

	for( int i =0; i<8; i++)
	{ 
		//cout<<i+1<<"|";
		for( int j=0; j<8; j++)
		{
			if ( liste_cases[i*8+j]== 0)
				circle.setFillColor(sf::Color::Black);
			else if ( liste_cases[i*8+j]== 1)
				circle.setFillColor(sf::Color::White);
            else if ( liste_cases[i*8+j]== -1)
                continue;
            
            circle.setPosition((float)padding+j*2*(radius+padding),(float)padding+i*2*(radius+padding));
            fenetre->draw(circle);
		}
		cout<<endl;
	}

	// Affichage de scores
	sf::Font font;
	//font.loadFromFile("arial.ttf");
    font.loadFromFile("Avenir.ttc");

	//creation objet texte 1
	joueur1 += " "+std::to_string((long long)nb_pions_blancs);
	sf::Text text(joueur1.c_str(), font);
	text.setCharacterSize(20);
	text.setColor(sf::Color::White);
	text.setPosition(padding,width+padding);

	// Affichage 1
	fenetre->draw(text);

	//creation objet texte 2
	joueur2 += " "+std::to_string((long long)nb_pions_noirs);
	sf::Text text2(joueur2.c_str(), font);
	text2.setCharacterSize(20);
	text2.setColor(sf::Color::Black);
	text2.setPosition(width/2.,width+padding);

	// Affichage 2
	fenetre->draw(text2);

    fenetre->display();


}

bool Plateau::action_possible ( Joueur* joueur, int x, int y )
{

	int v = 0;
    
	if( joueur == NULL || x < 0 || x > 7 || y < 0 || y > 7)
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
	for( int i=0; i<8; i++)
	{
		for( int j=0; j<8; j++)
		{
            if (action_possible (joueur, i, j))
                return false;
		}
	}

	return true;

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
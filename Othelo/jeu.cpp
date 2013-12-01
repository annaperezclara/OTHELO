#include "Othelo.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "StrategieStupide.h"
#include "IA.h"

Jeu::Jeu(sf::RenderWindow* fenetre)
{
    bool termine = false;
    this->fenetre = fenetre;
    
	int jeu = NULL;
	string nom;

	
	while ( !(jeu==1 || jeu==2 || jeu == 3))
	{
		cout<<"bonjour, bienvenue dans le jeu d'othelo"<<endl;
		cout<<"tapez 1 pour jouer contre l'ordi"<<endl;
		cout<<"tapez 2 pour joeur avec un ami"<<endl;

		cin>>jeu;
		cin.clear();
		cin.ignore();
	}

	
    tour = 0;
    
	plateau = new Plateau();

	if( jeu == 2 )
	{
		cout<<"Nom du joueur 1"<<endl;
		cin>>nom;
		joueur1 = new Humain(this, nom, 1);

		cout<<"Nom du joueur 2"<<endl;
		cin>>nom;
		joueur2 = new Humain(this, nom, 0);

	}
	else if(jeu == 1)
	{
        cout<<"Nom du joueur 1"<<endl;
        cin>>nom;
        joueur1 = new Humain(this, nom, 1);
        joueur2 = new IA(this, new StrategieStupide(), plateau, 0);
	}
    
    else if(jeu == 3) {
        cout<<"IA contre IA"<<endl;
        joueur1 = new IA(this, new StrategieStupide(), plateau, 0);
        joueur2 = new IA(this, new StrategieStupide(), plateau, 1);
    }


}

Jeu::~Jeu( )
{
	delete joueur1;
	delete joueur2;
	delete plateau;

}

Joueur* Jeu::joueur_actuel()
{
	if ( tour%2 == 0)
		return joueur1;
	else
		return joueur2;
}

Joueur* Jeu::vainqueur()
{
	if ( plateau->calcul_vainqueur())
		return joueur1;
	else
		return joueur2;
}

void Jeu::phase_jeu (sf::RenderWindow *fenetre2)
{
	Joueur* joueur = joueur_actuel();
    
    if(plateau->fin_de_jeu(joueur)) {
        termine = true;
        return;
    }
    
	plateau->calcul_score();
	plateau->afficher(fenetre, joueur1->nom, joueur2->nom);

	//on initialise avec une position impossible
    int coords[2] = {-1,-1};

	//on demande au joueur des coordonnees jusqu'a ce qu'il fournisse une position possible
	while( !plateau->action_possible(joueur, coords[0], coords[1]))
        joueur->jouer(coords);

	//on effectue l'action et on passe au tour suivant
	plateau->ajouter_pion(joueur, coords[0], coords[1]);
	tour++;
}




void Jeu::quitter ()
{
	cout<<"fin du jeu"<<endl;
}
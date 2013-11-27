#include "Othelo.h"

Jeu::Jeu( )
{
	int jeu = NULL;
	string nom;

	while ( !(jeu==1 || jeu==2))
	{
		cout<<"Bonjour, bienvenue dans le jeu d'othelo"<<endl;
		cout<<"Tapez 1 pour jouer contre l'ordi"<<endl;
		cout<<"Tapez 2 pour joeur avec un ami"<<endl;

		cin>>jeu;
	}

	if( jeu == 2 )
	{
		cout<<"Nom du joueur 1"<<endl;
		cin>>nom;
		joueur1 = new Humain(nom, 1);

		cout<<"Nom du joueur 2"<<endl;
		cin>>nom;
		joueur2 = new Humain(nom, 0);

	}
	else if(jeu == 1)
	{
		cout<<"Pardon le jeu contre ordinateur n'est pas encore implemente"<<endl;
	}

	tour = 0;

	plateau = new Plateau();


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


void Jeu::phase_jeu ()
{
	Joueur* joueur = joueur_actuel();
    
	plateau->afficher();

    int coords[2] = {-1,-1};
	while( !plateau->action_possible(joueur, coords[0], coords[1]))
        joueur->jouer(coords);

	plateau->ajouter_pion(joueur, coords[0], coords[1]);
	tour++;
}

void Jeu::quitter ()
{
	cout<<"fin du jeu"<<endl;
}
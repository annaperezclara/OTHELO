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


}

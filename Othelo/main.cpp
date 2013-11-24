#include "Othelo.h"



int main()
{

	Jeu monJeu;

	//boucle de jeu
	while( !monJeu.plateau->fin_de_jeu( monJeu.joueur_actuel() ) )
	{
		monJeu.phase_jeu ();
	}

	monJeu.quitter ();

	delete &monJeu;
	
	//pour empecher la sortie	
	int tortue;
	cin>>tortue;

    return 0;
}
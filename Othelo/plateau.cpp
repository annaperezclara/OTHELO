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

}
	
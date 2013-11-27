#include "Othelo.h"

Humain::Humain( string nom, int couleur)
{
	name = nom;
	color = couleur;
}

void Humain::jouer(int *coords)
{
    int nLigne, nColonne;
    
    cout<<"Veuillez indiquer un numero de ligne"<<endl;
    cin>>nLigne;
    cout<<"Veuillez indiquer un numero de colonne"<<endl;
    cin>>nColonne;
    
    coords[0] = nColonne-1;
    coords[1] = nLigne-1;
}
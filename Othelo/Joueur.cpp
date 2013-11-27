#include "Othelo.h"

Humain::Humain( string nom, int couleur)
{
	this->nom = nom;
	this->couleur = couleur;
}

void Humain::jouer(int *coords)
{
    int nLigne, nColonne;
    
    cout<<"("<< couleur << ") Veuillez indiquer un numero de ligne : ";
    cin>>nLigne;
    cout<<"(" << couleur << ") Veuillez indiquer un numero de colonne : ";
    cin>>nColonne;
    
    coords[0] = nColonne-1;
    coords[1] = nLigne-1;
}
#include "Othelo.h"

Humain::Humain( string nom, int couleur)
{
	this->nom = nom;
	this->couleur = couleur;
}

void Humain::jouer(int *coords)
{
    int ligne, colonne;
    
    cout<<"("<< couleur << ") Veuillez indiquer un numero de ligne : ";
    cin>>ligne;
    cout<<"(" << couleur << ") Veuillez indiquer un numero de colonne : ";
    cin>>colonne;
    
    coords[0] = colonne-1;
    coords[1] = ligne-1;
}
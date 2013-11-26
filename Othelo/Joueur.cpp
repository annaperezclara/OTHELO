#include "Othelo.h"

Humain::Humain( string nom, int couleur)
{
	name = nom;
	color = couleur;
}

void Humain::jouer()
{
    int case_index;
    cout<<"Dans quelle case jouer ?"<<endl;
    cin>>case_index;
    
}
#include "Othelo.h"

Humain::Humain(Jeu* jeu, string nom, int couleur)
{
    this->jeu = jeu;
	this->nom = nom;
	this->couleur = couleur;
}

void Humain::jouer(int *coords)
{
    sf::Event event;
    coords[0] = -1;
    while(coords[0] == -1) {
        while(jeu->fenetre->pollEvent(event)) {
            if(event.type == sf::Event::MouseButtonPressed) {
                coords[0] = event.mouseButton.x/50;
                coords[1] = event.mouseButton.y/50;
            }
        }
    }
}

/*
void Humain::jouer(int *coords)
{
    int ligne, colonne;
    
    cout<<"("<< couleur << ") Veuillez indiquer un numero de ligne : ";
    cin>>ligne;
    cout<<"(" << couleur << ") Veuillez indiquer un numero de colonne : ";
    cin>>colonne;
    
    coords[0] = colonne-1;
    coords[1] = ligne-1;
}*/
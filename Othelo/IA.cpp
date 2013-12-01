//
//  IA.cpp
//  Othelo
//

#include "IA.h"
IA::IA(Jeu* jeu, Strategie* strategie, Plateau* plateau, int couleur) {
    this->couleur = couleur;
    this->jeu = jeu;
    this->strategie = strategie;
    this->plateau = plateau;
    this->nom = "Ordinateur";
}

void IA::jouer(int* coords) {
    strategie->coords(coords, plateau, this);
    cout<<"L'IA joue sur la "<< coords[1]<<"e ligne et la "<<coords[0]<<"e colonne"<<endl;
}
//
//  IA.cpp
//  Othelo
//

#include "IA.h"
IA::IA(Jeu* jeu, Strategie* strategie, Plateau* plateau) {
    this->jeu = jeu;
    this->strategie = strategie;
    this->plateau = plateau;
}

void IA::jouer(int* coords) {
    strategie->coords(coords, plateau, this);
    cout<<"L'IA joue sur la "<< coords[1]<<"e ligne et la "<<coords[0]<<"e colonne"<<endl;
}
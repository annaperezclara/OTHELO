//
//  IA.h
//  Othelo
//

#ifndef __Othelo__IA__
#define __Othelo__IA__

#include <iostream>
#include "Othelo.h"

class IA: public Joueur
{
public:
    IA(Jeu* jeu, Strategie* strategie, Plateau* plateau, int couleur);
    void jouer(int *coords);
private:
    Strategie* strategie;
    Plateau* plateau;
};

#endif /* defined(__Othelo__IA__) */

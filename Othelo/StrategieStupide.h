//
//  StrategieStupide.h
//  Othelo
//

#ifndef __Othelo__StrategieStupide__
#define __Othelo__StrategieStupide__

#include <iostream>
#include "Othelo.h"

class StrategieStupide: public Strategie
{
public:
    void coords(int* coords, Plateau* plateau, Joueur* joueur);
};

#endif /* defined(__Othelo__StrategieStupide__) */

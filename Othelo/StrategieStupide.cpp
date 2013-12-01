//
//  StrategieStupide.cpp
//  Othelo
//
extern "C"{
#include <unistd.h>
}

#include "StrategieStupide.h"
void StrategieStupide::coords(int* coords, Plateau* plateau, Joueur* joueur) {
    int x = 0;
    int y = 0;
    while(!plateau->action_possible(joueur, x, y) && y < 8) {
        if (x == 7) {
            y++;
            x = 0;
        } else {
            x++;
        }
    }

    //sleep(1);
    
    coords[0] = x;
    coords[1] = y;
}
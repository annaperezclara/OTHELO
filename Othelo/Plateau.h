//
//  Header.h
//  Othelo
//

#ifndef plateau_h
#define plateau_h

#include "Othelo.h"


class Joueur;

class Plateau
{
public:
    Plateau ();
    void afficher(sf::RenderWindow *fenetre, std::string joueur1, std::string joueur2);
    bool action_possible ( Joueur* joueur, int x, int y );
    void ajouter_pion ( Joueur* joueur, int x, int y);
    bool fin_de_jeu ( Joueur* joueur );
	void calcul_score();
    
private:
    int liste_cases [64];
    int nb_pions_blancs;
    int nb_pions_noirs;
};


#endif
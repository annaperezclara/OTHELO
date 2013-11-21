#ifndef othelo
#define othelo

class Plateau
{
    public:

	void afficher ();
	bool action_possible ( Joueur joueur, int x, int y );
	void ajouter_pion ( Joueur joueur, int x, int y);
    
    private:
 
    int liste_cases [64];
	int nb_pions_blancs;
	int nb_pions_noirs;

};


#endif
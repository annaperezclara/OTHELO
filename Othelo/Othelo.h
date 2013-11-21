#ifndef othelo
#define othelo

class Joueur
{
	public:
		virtual void jouer () = 0;
    int couleur;

};

class Humain: public Joueur
{
	public:
		void jouer ();

};


class Plateau
{
    public:
	
	Plateau ();
	void afficher ();
	bool action_possible ( Humain joueur, int x, int y );
	void ajouter_pion ( Humain joueur, int x, int y);
    
    private:
 
    int liste_cases [64];
	int nb_pions_blancs;
	int nb_pions_noirs;

};

class Jeu
{
	public:

		void initialiser ();
		void quitter ();

	private:
		Joueur* joueur1;
		Joueur* joueur2;

};


#endif
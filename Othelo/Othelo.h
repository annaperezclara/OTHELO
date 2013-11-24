#ifndef othelo
#define othelo

#include <iostream>
#include <string>

using namespace std;

class Joueur
{
	public:
		virtual void jouer () = 0;
		int couleur;

};

class Humain: public Joueur
{
	public:
		Humain(string nom, int couleur);
		void jouer ();
	private:
		string name;

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

		Jeu ();
		void phase_jeu ();
		void quitter ();

	private:
		Joueur* joueur1;
		Joueur* joueur2;
		bool tour;
};


#endif
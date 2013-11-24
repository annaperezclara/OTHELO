#ifndef othelo
#define othelo

#include <iostream>
#include <string>

using namespace std;

class Joueur
{
	public:
		virtual void jouer () = 0;
		int color;

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
	bool action_possible ( Joueur* joueur, int x, int y );
	void ajouter_pion ( Joueur* joueur, int x, int y);
	bool fin_de_jeu ( Joueur* joueur );
    
    private:
 
    int liste_cases [64];
	int nb_pions_blancs;
	int nb_pions_noirs;

};

class Jeu
{
	public:

		Jeu ();
		~Jeu ();
		void phase_jeu ();
		void quitter ();
		Joueur* joueur_actuel();
		Plateau* plateau;

	private:
		Joueur* joueur1;
		Joueur* joueur2;
		int tour;
		
		
};


#endif
#ifndef othelo
#define othelo

#include <iostream>
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Plateau.h"

using namespace std;

class Joueur
{
	public:
		virtual void jouer (int *coords) = 0;
		int couleur;

};

class Humain: public Joueur
{
	public:
		Humain(string nom, int couleur);
		void jouer (int *coords);
	private:
		string nom;

};

class Strategie
{
    public:
        virtual void coords(int* coords, Plateau* plateau, Joueur* joueur) = 0;
};

class Jeu
{
	public:
		Jeu ();
		~Jeu ();
		void phase_jeu (sf::RenderWindow *fenetre);
		void quitter ();
		Joueur* joueur_actuel();
		Plateau* plateau;

	private:
		Joueur* joueur1;
		Joueur* joueur2;
		int tour;
};


#endif
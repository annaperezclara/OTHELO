#ifndef othelo
#define othelo

#include <iostream>
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Plateau.h"

using namespace std;

class Jeu;

class Joueur
{
	public:
		virtual void jouer (int *coords) = 0;
		int couleur;
        Jeu* jeu;
};

class Humain: public Joueur
{
	public:
		Humain(Jeu* jeu, string nom, int couleur);
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
        Jeu (sf::RenderWindow* fenetre);
		~Jeu ();
		void phase_jeu (sf::RenderWindow *fenetre);
		void quitter ();
		Joueur* joueur_actuel();
		Plateau* plateau;
        sf::RenderWindow* fenetre;

	private:
		Joueur* joueur1;
		Joueur* joueur2;
		int tour;
};


#endif
#include "gtest/gtest.h"
#include "Othelo.h"


TEST(testStack, othelo) 
{
	//test fenetre se lance bien
	sf::RenderWindow window(sf::VideoMode(400, 430), "Jeu d'othelo", sf::Style::Titlebar);
	EXPECT_EQ(window.isOpen(), true);

	//test variable fin de jeu fausse apres lancement objet jeu
	Jeu monJeu(&window);
	EXPECT_EQ(monJeu.termine, false);

	//test phase jeu 1 passe bien
	monJeu.phase_jeu(&window);
	EXPECT_EQ(1, monJeu.tour);
}


TEST(testStack, pause) 
{
	bool wait;
	cin>>wait;
}


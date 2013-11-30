#include "Othelo.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main()
{
	//fenetre non resizable sinon bug d'affichage
	sf::RenderWindow window(sf::VideoMode(400, 430), "Jeu d'othelo", sf::Style::Titlebar);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    Jeu monJeu(&window);
    
	//boucle de jeu tant que la fenêtre reste ouverte
    while (window.isOpen())
    {
        monJeu.phase_jeu(&window);

        sf::Event event;
        while (window.pollEvent(event))
        {
			if(monJeu.plateau->fin_de_jeu( monJeu.joueur_actuel()))
			{
				//si plus de position possible on quitte et on affiche le vainqueyr
				// /!\/!\ fonction a rajouter pour dire qui a gagne
				
				//monJeu.quitter();

				delete &monJeu;
				window.close();
			}

            if (event.type == sf::Event::Closed)
                window.close();
        }

	}
    

	
    return 0;
}


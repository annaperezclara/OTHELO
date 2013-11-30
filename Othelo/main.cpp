#include "Othelo.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main()
{
	
	sf::RenderWindow window(sf::VideoMode(400, 400), "Jeu d'othelo");
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

				window.close();
			}

            if (event.type == sf::Event::Closed)
                window.close();
        }

		//cout<<"gros bouffon"<<endl;

		/*
        window.clear();
        window.draw(shape);
        window.display();*/
	}
    

	
	/*
	//boucle de jeu
	while(!monJeu.plateau->fin_de_jeu( monJeu.joueur_actuel()))
		monJeu.phase_jeu();

	monJeu.quitter();

	delete &monJeu;
	*/
	

	
    return 0;
}


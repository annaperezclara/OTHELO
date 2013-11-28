#include "Othelo.h"

int main()
{
	Jeu monJeu;

	
	sf::RenderWindow window(sf::VideoMode(800, 800), "Jeu d'othelo");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

	//boucle de jeu tant que la fenêtre reste ouverte
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
			monJeu.phase_jeu(&window);

			if(monJeu.plateau->fin_de_jeu( monJeu.joueur_actuel()))
			{
				//si plus de position possible on quitte et on affiche le vainqueyr
				// /!\/!\ fonction a rajouter pour dire qui a gagne

				window.close();
			}

            if (event.type == sf::Event::Closed)
                window.close();
        }

		cout<<"gros bouffon"<<endl;

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


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
    
    bool stop = false;
    
	//boucle de jeu tant que la fenêtre reste ouverte
    while (window.isOpen())
    {
        monJeu.phase_jeu(&window);

        sf::Event event;
        while (window.pollEvent(event))
        {
        if(monJeu.termine && !stop)
        {
            stop = true;
            //si plus de position possible on quitte et on affiche le vainqueyr
            // /!\/!\ fonction a rajouter pour dire qui a gagne
            sf::RectangleShape rect(sf::Vector2f(400,400));
            rect.setFillColor(sf::Color(0,0,0,125));
            window.draw(rect);
            
            rect.setSize(sf::Vector2f(300,300));
            rect.setFillColor(sf::Color(255,255,255,230));
            rect.setPosition(50,50);
            
            sf::Font font;
            //font.loadFromFile("/Users/julien/workspace/projetc++/OTHELO/Othelo/Avenir.ttc");
            sf::Text text("Victoire", font);
           
            text.setCharacterSize(20);
            text.setColor(sf::Color::Black);
            
            window.draw(rect);
            window.draw(text);
            
            
            window.display();
            
        }
        }
        
		//cout<<"gros bouffon"<<endl;

		/*
        window.clear();
        window.draw(shape);
        window.display();*/
	}
    

	
    return 0;
}


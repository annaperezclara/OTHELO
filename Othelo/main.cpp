#include "Othelo.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main()
{
	//fenetre non resizable sinon bug d'affichage
	sf::RenderWindow window(sf::VideoMode(400, 430), "Jeu d'othelo", sf::Style::Titlebar);

    Jeu monJeu(&window);
	cout<<monJeu.termine<<endl;
    
	//boucle de jeu tant que la fenêtre reste ouverte
    while (window.isOpen())
    {
        monJeu.phase_jeu(&window);

        sf::Event event;
        while (window.pollEvent(event))
        {
        if(monJeu.termine)
        {

			cout<<"APPUYEZ SUR LA TOUCHE ENTREE POUR QUITTEZ"<<endl;

            //si plus de position possible on quitte et on affiche le vainqueur
			//fond
            sf::RectangleShape rect(sf::Vector2f(400,400));
            rect.setFillColor(sf::Color(0,0,0,125));
            window.draw(rect);
            
            rect.setSize(sf::Vector2f(300,300));
            rect.setFillColor(sf::Color(255,255,255,230));
            rect.setPosition(50,50);
            
			//message
            sf::Font font;
			string texte= "VICTOIRE\n"+monJeu.vainqueur()->nom;
			font.loadFromFile("Avenir.ttc");
            sf::Text text(texte.c_str(), font);
           
            text.setCharacterSize(40);
            text.setColor(sf::Color::Black);
			text.setPosition(120,150);


            window.draw(rect);
            window.draw(text);
            
            
            window.display();

			while(!sf::Keyboard::isKeyPressed((sf::Keyboard::Return)))
			{
				if(sf::Keyboard::isKeyPressed((sf::Keyboard::Return)))
				{
					window.close();
					return 1;
				}
			}

            
        }
        }
        
	}
    

	
    return 0;
}


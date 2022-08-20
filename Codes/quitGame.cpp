#include <iostream>
#include<SFML/Graphics.hpp>
#include "quitGame.h"
using namespace sf;

int quitGame::close_window(sf::RenderWindow& play){
    Font font;
    font.loadFromFile("Fonts/Contra.ttf");
    Text text[3];
    for(int i=0;i<3;i++)
    {
        text[i].setFont(font);//sets font for text
        text[i].setCharacterSize(16);
        text[i].setFillColor(sf::Color::Black);
    }
    //text[0].setCharacterSize(16);
    //Sets co ordinates for text text
    text[0].setPosition(10,10);
    text[1].setPosition(100,70);
    text[2].setPosition(350,70);

    //Sting values for text text
    text[0].setString("Are you sure you want to quit?\n**Your data will be lost!");
    text[1].setString("Yes");
    text[2].setString("No");

    RenderWindow Quit(VideoMode(500, 100), "QUIT",Style::Close);
    while(Quit.isOpen())
    {
        Event event;
        while (Quit.pollEvent(event))
        {
            if(event.type == Event::Closed)
                Quit.close();
            Vector2i mouse;
            mouse=Mouse::getPosition(Quit);

            if(text[1].getGlobalBounds().contains(mouse.x,mouse.y))
            {
                text[1].setFillColor(sf::Color::Red);
                if (Mouse::isButtonPressed(Mouse::Left)) {
                    Quit.close();
                    play.close();
                }
            }
            else if(text[2].getGlobalBounds().contains(mouse.x,mouse.y))
            {
                text[2].setFillColor(sf::Color::Red);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    Quit.close();
                }
            }
            else
            {
                text[1].setFillColor(sf::Color::Black);
                text[2].setFillColor(sf::Color::Black);
            }
        }
        Quit.clear(Color(119,221,119));
        for(int i=0;i<3;i++){
            Quit.draw(text[i]);
        }
        Quit.display();
    }
    return 0;
}

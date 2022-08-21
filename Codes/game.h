#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

#include "Loadboard.h"
#include "MainMenu.h"
#include "quitGame.h"
#include <unistd.h>
#include <unordered_map>

using namespace sf;

class Game{
public:
    Texture goatWinTexture,tigerWinTexture,homeButtonTexture;
    RectangleShape goatWinImage,tigerWinImage,homeButtonImage;
    Event event{};
    Goat goat[20];
    Board board;
    int goatChosen,goatEaten;
    bool gameOver,tigerTurn=true;
    bool tigerWin,goatWin;
    Vector2i pos;
    bool quit;

    void getBestMove();
    Game();
    int run();
    void processEvents();
    void handlePlayerInput(sf::Keyboard::Key & );
    void checkGameOver(RenderWindow&);
    void goatWins();
    void tigerWins();
protected:
    sf::RenderWindow mWindow;
};
#endif

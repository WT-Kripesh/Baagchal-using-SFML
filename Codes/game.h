#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "MainMenu.h"

using namespace sf;

class Game{
public:
    RectangleShape Pbackground;
    Texture back_texture;
    Game();
    int run(Sprite);
};
#endif // GAME_H_INCLUDED

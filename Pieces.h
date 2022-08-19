#ifndef PIECES_H_INCLUDED
#define PIECES_H_INCLUDED

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
using namespace sf;

class Tiger{
    Texture tiger_texture;
public:
    Tiger();
    void tiger_sprite();
};

class Goat{
    Texture goat_texture;
public:
    Goat();
    void goat_sprite();
};

void setup(){
    //code
}

void initial_board(){
    //code

}
void start_game(){
    //code
}
#endif // PIECES_H_INCLUDED

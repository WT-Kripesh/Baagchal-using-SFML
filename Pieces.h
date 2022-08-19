#ifndef PIECES_H_INCLUDED
#define PIECES_H_INCLUDED

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
using namespace sf;

class Tiger{
    Texture tiger_texture;
public:
    Tiger(){
        if (!tiger_texture.loadFromFile("Images/tiger.png"))
        {
            cout << "Error loading from file!"<<endl;
        }
    }
    int position;
    Sprite tiger_sprite;
    void set_texture(){
        this->tiger_sprite.setTexture(tiger_texture);
        this->tiger_sprite.setScale(sf::Vector2f(0.12f, 0.12f));
        this->tiger_sprite.setPosition(125*(position/10)+280,125*(position%10)+150);
        this->tiger_sprite.setOrigin(400,346);
    }
};

class Goat{
    Texture goat_texture;
    Sprite goat_sprite;

public:
    Goat(){
        if (!goat_texture.loadFromFile("Images/goat.png"))
        {
            cout << "Error loading from file!"<<endl;
        }
    }
    void set_texture(){
        this->goat_sprite.setTexture(goat_texture);
        this->goat_sprite.setScale(sf::Vector2f(0.15f, 0.15f));
        this->goat_sprite.setOrigin(682/2,584/2);
    }
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

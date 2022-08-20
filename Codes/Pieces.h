#ifndef PIECES_H_INCLUDED
#define PIECES_H_INCLUDED

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
using namespace sf;

class Tiger{
    Texture tiger_texture;
public:
        int row,column;
        int index;
        static int indexSetter;
    Sprite tiger_sprite;
    Tiger(){
        index=indexSetter;
        indexSetter++;
        if (!tiger_texture.loadFromFile("Images/tiger.png"))
        {
            cout << "Error loading from file!"<<endl;
        }
        this->tiger_sprite.setTexture(tiger_texture);
        this->tiger_sprite.setScale(sf::Vector2f(0.12f, 0.12f));
        this->tiger_sprite.setOrigin(400,346);

    }
    void set_Position(){
        this->tiger_sprite.setPosition(125*(this->row-1)+280,125*(this->column-1)+150);
    }
};
int Tiger::indexSetter;

class Goat{
    Texture goat_texture;
public:
        int row,column;
        int index;
        static int indexSetter;
    Sprite goat_sprite;
Goat(){
        index=indexSetter;
        indexSetter++;
        if (!goat_texture.loadFromFile("Images/goat.png"))
        {
            cout << "Error loading from file!"<<endl;
        }
        this->goat_sprite.setTexture(goat_texture);
        this->goat_sprite.setScale(sf::Vector2f(0.15f, 0.15f));
        this->goat_sprite.setOrigin(682/2,584/2);
    }
    void set_Position(){
    this->goat_sprite.setPosition(125*(this->row-1)+280,125*(this->column-1)+150);
    }
};
int Goat::indexSetter;
#endif // PIECES_H_INCLUDED

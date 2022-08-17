#include "game.h"

Game::Game(){}
int Game::run(){
	//Photo to the game
    RectangleShape Pbackground;
	Pbackground.setSize(Vector2f(WIDTH, HEIGHT));
	Texture back_texture;
	back_texture.loadFromFile("Images/board.jpg");
	Pbackground.setTexture(&back_texture);

    RenderWindow Play(VideoMode(WIDTH, HEIGHT), "PLAY");
    while (Play.isOpen()) {
            Event aevent;
    while (Play.pollEvent(aevent)) {
            if (aevent.type == Event::Closed)
                Play.close();
    if (aevent.type == Event::KeyPressed) {
            if (aevent.key.code == Keyboard::Escape)
                Play.close();
    }}
    Play.clear();
    Play.draw(Pbackground);
    Play.display();
    }
    return 0;
}

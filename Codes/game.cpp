#include "game.h"
#include "Pieces.h"
#include "board.h"
#include "gameFunctions.h"

Game::Game(){
    //Photo to the game
	Pbackground.setSize(Vector2f(WIDTH, HEIGHT));
	back_texture.loadFromFile("Images/board.jpg");
	Pbackground.setTexture(&back_texture);
}


int Game::run(Sprite button){

    Tiger tiger[4];
    Goat goat[20];
    Matrix matrix[6][6];        //Neglecting [0][0] and so on
    initial_positions(tiger,matrix);

    RenderWindow Play(VideoMode(WIDTH, HEIGHT), "PLAY",Style::None);
    while (Play.isOpen()) {
        Event aevent;
        while (Play.pollEvent(aevent)){
            if (aevent.type == Event::KeyPressed) {
                    if (aevent.key.code == Keyboard::Escape)
                        close_window(Play);
            }
            if (button.getGlobalBounds().contains(Mouse::getPosition(Play).x, Mouse::getPosition(Play).y)){
                if (Mouse::isButtonPressed(Mouse::Left)){
                    close_window(Play);
            }
            }
        }

    Play.clear();
    Play.draw(Pbackground);
    Play.draw(button);
    draw(Play,matrix,tiger,goat);
    input(Play,matrix,sr,sc);
    process(Play,matrix,tiger,goat,sr,sc);
	Play.display();
    }
    return 0;
}



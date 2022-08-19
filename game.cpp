#include "game.h"
#include "Pieces.h"

void initial_positions(Tiger t[4]){
        t[0].position=11;
        t[1].position=15;
        t[2].position=51;
        t[3].position=55;
}


Game::Game(){}
int Game::run(){
	//Photo to the game
    RectangleShape Pbackground;
	Pbackground.setSize(Vector2f(WIDTH, HEIGHT));
	Texture back_texture;
	back_texture.loadFromFile("Images/board.jpg");
	Pbackground.setTexture(&back_texture);

    Tiger tiger[4];
    Goat goat[20];
    initial_positions(tiger);
    for(int i=0;i<4;i++){
        tiger[i].set_texture();
    }
    for(int i=0;i<20;i++){
        goat[i].set_texture();
    }

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
    for (int i = 0; i <4; i++) {
		 Play.draw(tiger[i].tiger_sprite);
	}
	Play.display();
    }
    //setup();        //setup() is in pieces.h. It sets up the name and tiger/goat of players
    //initial_board();    //4 tigers in 4 corners and goats alive=20 in side of board
    //start_game();   //game starting
    return 0;
}



#include "game.h"
#include "Pieces.h"
#include "board.h"
#include "gameFunctions.h"

Game::Game(){}
int Game::run(Sprite button){
	//Photo to the game
    RectangleShape Pbackground;
	Pbackground.setSize(Vector2f(WIDTH, HEIGHT));
	Texture back_texture;
	back_texture.loadFromFile("Images/board.jpg");
	Pbackground.setTexture(&back_texture);

    Tiger tiger[4];
    Goat goat[20];
    Matrix matrix[6][6];        //Neglecting [0][0] and so on
    //matrix_initialization(matrix);
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            cout<<matrix[i][j].row<<" , ";
            cout<<matrix[i][j].column;
    }
    cout<<endl;
    }
    setIndices(tiger,goat);
    set_all_tigerTexture(tiger);
    set_all_goatTexture(goat);
    initial_positions(tiger,matrix);

    RenderWindow Play(VideoMode(WIDTH, HEIGHT), "PLAY",Style::None);
    while (Play.isOpen()) {
        Event aevent;
        while (Play.pollEvent(aevent)){
            if (aevent.type == Event::KeyPressed) {
                    if (aevent.key.code == Keyboard::Escape)
                        close_window(Play);
            }
            if (button.getGlobalBounds().contains(mouse.x, mouse.y)){
                if (Mouse::isButtonPressed(Mouse::Left)){
                    close_window(Play);
            }
        }}

    Play.clear();
    Play.draw(Pbackground);
    Play.draw(button);
    draw(Play,matrix,tiger,goat);
    input(Play,matrix);
    process(Play,matrix,tiger,goat);

	Play.display();
    }
    return 0;
}



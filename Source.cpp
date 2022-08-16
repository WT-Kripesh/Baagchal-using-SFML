#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "MainMenu.h"
using namespace sf;
int main() {
const int WIDTH= 1200;
const int HEIGHT= 750;
	//make a main window
	RenderWindow MENU(VideoMode(WIDTH, HEIGHT), "Main Menu", Style::Default);
	MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);
	//For Audio
	SoundBuffer buffer1;
	SoundBuffer buffer2;
	if (!buffer1.loadFromFile("Audio/menu.wav"))
	{
		cout << "ERROR" <<endl;
	}
	if (!buffer2.loadFromFile("Audio/selected.wav"))
	{
		cout << "ERROR" <<endl;
	}
	Sound sound1;
	Sound sound2;
	sound1.setBuffer(buffer1);
	sound2.setBuffer(buffer2);


	//set background
	RectangleShape background;
	background.setSize(Vector2f(WIDTH, HEIGHT));
	Texture Maintexture;
	Maintexture.loadFromFile("Images/background.jpg");
	background.setTexture(&Maintexture);

	//Photo to the game
	RectangleShape Pbackground;
	Pbackground.setSize(Vector2f(WIDTH, HEIGHT));
	Texture back_texture;
	back_texture.loadFromFile("Images/board.jpg");
	Pbackground.setTexture(&back_texture);

	//photo to the option (will be added in future)
	//photo to the about (will be added in future)

	while (MENU.isOpen())
	{
		Event event;
		while (MENU.pollEvent(event)) {
			if (event.type == Event::Closed) {
				MENU.close();
			}
			if (event.type == Event::KeyReleased) {
				if (event.key.code == Keyboard::Up) {
					mainMenu.MoveUp();
					sound1.play();
					break;
				}
				if (event.key.code == Keyboard::Down) {
					mainMenu.MoveDown();
					sound1.play();
					break;
				}
				if (event.key.code == Keyboard::Return) {
					RenderWindow Play(VideoMode(WIDTH, HEIGHT), "PLAY");
					RenderWindow OPTIONS(VideoMode(WIDTH, HEIGHT), "OPTIONS");
					RenderWindow ABOUT(VideoMode(WIDTH, HEIGHT), "ABOUT");
					int x = mainMenu.MainMenuPressed();
					if (x == 0) {
						sound2.play();
						while (Play.isOpen()) {
							Event aevent;

							while (Play.pollEvent(aevent)) {

								if (aevent.type == Event::Closed) {
									Play.close();
								}
								if (aevent.type == Event::KeyPressed) {
									if (aevent.key.code == Keyboard::Escape) {
										Play.close();
									}
								}
							}
							OPTIONS.close();
							ABOUT.close();
							Play.clear();
							Play.draw(Pbackground);
							Play.display();
						}
					}
					if (x == 1) {
						sound2.play();
						while (OPTIONS.isOpen()) {
							Event aevent;
							while (OPTIONS.pollEvent(aevent)) {
								if (aevent.type == Event::Closed) {
									OPTIONS.close();
								}
								if (aevent.type == Event::KeyPressed) {
									if (aevent.type == Keyboard::Escape) {
										OPTIONS.close();
									}
								}
							}
							Play.close();
							OPTIONS.clear();
							ABOUT.close();
							OPTIONS.display();
						}
					}
					if (x == 2) {
						sound2.play();
						while (ABOUT.isOpen()) {
							Event aevent;
							while (ABOUT.pollEvent(aevent)) {
								if (aevent.type == Event::Closed) {
									ABOUT.close();
								}
								if (aevent.type == Event::KeyPressed) {
									if (aevent.key.code == Keyboard::Escape) {
										ABOUT.close();
									}
								}
							}
							Play.close();
							OPTIONS.clear();
							ABOUT.clear();
							ABOUT.display();
						}
					}
					if (x == 3)
						sound2.play();
						MENU.close();
					break;
				}
			}
		}
		MENU.clear();
		MENU.draw(background);
		mainMenu.draw(MENU);
		MENU.display();
	}
	return 0;
}

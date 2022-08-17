#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "MainMenu.h"
using namespace sf;
int main() {
	const int WIDTH = 1050;
	const int HEIGHT = 800;
	//make a main window
	RenderWindow MENU(VideoMode(WIDTH, HEIGHT), "Main Menu", Style::Default);
	MainMenu mainMenu(WIDTH, HEIGHT);
	//For Audio
	SoundBuffer buffer1;
	SoundBuffer buffer2;
	if (!buffer1.loadFromFile("Audio/menu.wav"))
	{
		cout << "ERROR" << endl;
	}
	if (!buffer2.loadFromFile("Audio/selected.wav"))
	{
		cout << "ERROR" << endl;
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

	//Sprite of tiger
	sf::Texture tiger;
	if (!tiger.loadFromFile("Sprites/tiger.png"))
	{
		cout << "error...";
	}
	sf::Sprite tiger_sprite[4];
	for (int i = 0; i < 4; i++) {
		tiger_sprite[i].setTexture(tiger);
	}


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
					int x = mainMenu.MainMenuPressed();
					if (x == 0) {
						RenderWindow Play(VideoMode(WIDTH, HEIGHT), "PLAY");
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
							Play.clear();
							Play.draw(Pbackground);

							tiger_sprite.setScale(sf::Vector2f(0.15f, 0.15f));
							tiger_sprite.setPosition(450,360);
							tiger_sprite.setOrigin(sf::Vector2f(50.f, 50.f));
							Play.draw(tiger_sprite);
							




							Play.display();
						}
					}
					if (x == 1) {
						RenderWindow OPTIONS(VideoMode(WIDTH, HEIGHT), "OPTIONS");
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
							OPTIONS.clear();
							OPTIONS.display();
						}
					}
					if (x == 2) {
						RenderWindow ABOUT(VideoMode(WIDTH, HEIGHT), "ABOUT");
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
#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;

#define Max_main_menu 4
const int WIDTH = 1050,HEIGHT = 800;

class MainMenu {
private:
    int MainMenuSelected;
	Font font;
	std::string aboutTextString;
	Text mainMenu[Max_main_menu],aboutText;
	RectangleShape menu_background,background1,background2;
   	Texture Maintexture,tex1,tex2,homeButton_tex;
public:
    Sprite homeButton;
	MainMenu();
	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int show();
    int Howtoplay();
    int About();
    int Selected(){
        return MainMenuSelected;
    }
	~MainMenu(){}
};

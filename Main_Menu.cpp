#include "MainMenu.h"
MainMenu::MainMenu(float width, float height) {
	if (!font.loadFromFile("Fonts/outline.ttf")) {
		cout << "No font is here";
	}
	for(int i=0;i<4;i++)
    {
        mainMenu[i].setFont(font);
        mainMenu[i].setFillColor(Color(0,0,0,225)); //black color
        mainMenu[i].setPosition(400, 150+100*i);
        mainMenu[i].setCharacterSize(70);
    }
	//Play
	mainMenu[0].setString("Play");
	//Options
	mainMenu[1].setString("Options");
	//About
	mainMenu[2].setString("About");
	//Exit
	mainMenu[3].setString("Exit");
	MainMenuSelected = -1;
}
MainMenu::~MainMenu() {

}
//Draw MainMenu
void MainMenu::draw(RenderWindow& window) {
	for (int i = 0; i < Max_main_menu; i++) {
		window.draw(mainMenu[i]);
	}
}
//MoveUp
void MainMenu::MoveUp() {
	if (MainMenuSelected - 1 >= 0) {
		mainMenu[MainMenuSelected].setFillColor(Color::White);
		MainMenuSelected--;
		if (MainMenuSelected == -1) {
			MainMenuSelected = 2;				//Cursor last maa xa, tala dabayam vane first maa janxa
		}
		mainMenu[MainMenuSelected].setFillColor(Color::Blue);
	}
}
//MoveDown
void MainMenu::MoveDown() {
	if (MainMenuSelected + 1 <= Max_main_menu) {
		mainMenu[MainMenuSelected].setFillColor(Color::White);
		MainMenuSelected++;
		if (MainMenuSelected == 4) {
			MainMenuSelected == 0;
		}
		mainMenu[MainMenuSelected].setFillColor(Color::Blue);
	}
}

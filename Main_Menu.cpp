#include "MainMenu.h"
MainMenu::MainMenu(float width, float height) {
	if (!font.loadFromFile("Fonts/outline.ttf")) {
		cout << "No font is here";
	}
	for(int i=0;i<Max_main_menu;i++)
    {
        mainMenu[i].setFont(font);
        mainMenu[i].setFillColor(Color::Black); //black color
        mainMenu[i].setCharacterSize(70);
        mainMenu[i].setPosition(400, 150+100*i);
    }
	//Play
	mainMenu[0].setString("Play");
    //Options
	mainMenu[1].setString("Options");
	//About
	mainMenu[2].setString("About");
	//Exit
	mainMenu[3].setString("Exit");
	MainMenuSelected = 0;
    mainMenu[MainMenuSelected].setFillColor(Color::Blue);
}
MainMenu::~MainMenu() {}

//Draw MainMenu
void MainMenu::draw(RenderWindow& window) {
	for (int i = 0; i < Max_main_menu; i++) {
		window.draw(mainMenu[i]);
	}
}
//MoveUp
void MainMenu::MoveUp() {
    mainMenu[MainMenuSelected].setFillColor(Color::Black);
    MainMenuSelected--;
    if (MainMenuSelected == -1) {
        MainMenuSelected = 3;				//Cursor last maa xa, tala dabayam vane first maa janxa
    }
    mainMenu[MainMenuSelected].setFillColor(Color::Blue);
}

//MoveDown
void MainMenu::MoveDown() {
    mainMenu[MainMenuSelected].setFillColor(Color::Black);
    MainMenuSelected++;
    if (MainMenuSelected == 4){
        MainMenuSelected = 0;
    }
    mainMenu[MainMenuSelected].setFillColor(Color::Blue);
}



#include "MainMenu.h"
#include<SFML/Audio.hpp>

MainMenu::MainMenu()
{
	font.loadFromFile("Fonts/outline.ttf");
	for(int i=0;i<Max_main_menu;i++)
    {
        mainMenu[i].setFont(font);
        mainMenu[i].setFillColor(Color::Black); //black color
        mainMenu[i].setCharacterSize(70);
        mainMenu[i].setPosition(400, 150+100*i);
    }
	mainMenu[0].setString("Play");
	mainMenu[1].setPosition(250, 250);
	mainMenu[1].setString("How to play");
	mainMenu[2].setString("About");
	mainMenu[3].setString("Exit");
	MainMenuSelected = 0;
    mainMenu[MainMenuSelected].setFillColor(Color::Blue);

	//set background for Main menu
	background.setSize(Vector2f(WIDTH, HEIGHT));
	Maintexture.loadFromFile("Images/background1.jpg");
	background.setTexture(&Maintexture);
	//Set background for Options
	background1.setSize(Vector2f(WIDTH, HEIGHT));
	tex1.loadFromFile("Images/background.jpg");
	background1.setTexture(&tex1);
	//Set background for About
	background2.setSize(Vector2f(WIDTH, HEIGHT));
	tex2.loadFromFile("Images/neww.jpg");
	background2.setTexture(&tex2);
}

int MainMenu::show(){
	//For Audio
	SoundBuffer buffer1,buffer2;
	buffer1.loadFromFile("Audio/menu.wav");
	buffer2.loadFromFile("Audio/selected.wav");
	Sound sound1,sound2;
	sound1.setBuffer(buffer1);
	sound2.setBuffer(buffer2);

	//make menu window
	RenderWindow MENU(VideoMode(WIDTH, HEIGHT), "Main Menu", Style::Default);
    while (MENU.isOpen())
	{
		draw(MENU);
		MENU.display();
		Event event;
		while (MENU.pollEvent(event)) {
			if (event.type == Event::Closed) {
				MENU.close();
			}
			if (event.type == Event::KeyReleased) {
				if (event.key.code == Keyboard::Up) {
					MoveUp();
                    cout<<MainMenuSelected<<" up\t";
					sound1.play();
				}
				else if (event.key.code == Keyboard::Down) {
					MoveDown();
                    cout<<MainMenuSelected<<" down\t";
					sound1.play();
				}
				else if (event.key.code == Keyboard::Return){
                    sound2.play();
                    cout<<MainMenuSelected<<"\tEnter\n";
                    MENU.close();
				}
				else if(event.key.code == Keyboard::Escape){
                    MainMenuSelected = 3;
                    MENU.close();
				}
    }}
    }
    return 0;
}
//Draw MainMenu
void MainMenu::draw(RenderWindow& window) {
    window.clear();
    window.draw(background);
	for (int i = 0; i < Max_main_menu; i++) {
		window.draw(mainMenu[i]);
	}
}
//MoveUp
void MainMenu::MoveUp() {
    mainMenu[MainMenuSelected].setFillColor(Color::Black);
    mainMenu[MainMenuSelected].setCharacterSize(70);
    --MainMenuSelected;
    if (MainMenuSelected == -1) {
        MainMenuSelected = 3;				//Cursor last maa xa, tala dabayam vane first maa janxa
    }
    mainMenu[MainMenuSelected].setFillColor(Color::Blue);
    mainMenu[MainMenuSelected].setCharacterSize(80);
}

//MoveDown
void MainMenu::MoveDown() {
    mainMenu[MainMenuSelected].setFillColor(Color::Black);
    mainMenu[MainMenuSelected].setCharacterSize(70);
    ++MainMenuSelected;
    if (MainMenuSelected == 4){
        MainMenuSelected = 0;
    }
    mainMenu[MainMenuSelected].setFillColor(Color::Blue);
    mainMenu[MainMenuSelected].setCharacterSize(80);
}

int MainMenu::Howtoplay(){
   RenderWindow OPTIONS(VideoMode(WIDTH, HEIGHT), "HOW TO PLAY");
   while (OPTIONS.isOpen()) {
        Event aevent;
        while (OPTIONS.pollEvent(aevent)) {
            if (aevent.type == Event::Closed) {
                OPTIONS.close();
            }
            if (aevent.type == Event::KeyPressed) {
                if (aevent.key.code == Keyboard::Escape)
                    OPTIONS.close();
        }}
        OPTIONS.clear();
        OPTIONS.draw(background1);
        OPTIONS.display();
	}
	show();
	return 0;
}

int MainMenu::About(){
    RenderWindow ABOUT(VideoMode(WIDTH, HEIGHT), "ABOUT");
    while (ABOUT.isOpen()) {
        Event aevent;
        while (ABOUT.pollEvent(aevent)) {
            if (aevent.type == Event::Closed) {
                ABOUT.close();
        }
        if (aevent.type == Event::KeyPressed) {
            if (aevent.key.code == Keyboard::Escape) {
                ABOUT.close();
        }}
        }
        ABOUT.clear();
        ABOUT.draw(background2);
        ABOUT.display();
    }
    show();
    return 0;
}

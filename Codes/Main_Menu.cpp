#include "MainMenu.h"
#include<SFML/Audio.hpp>
#include<fstream>

MainMenu::MainMenu()
{
    font.loadFromFile("Fonts/outline.ttf");
    for(int i=0;i<Max_main_menu;i++)
    {
        mainMenu[i].setFont(font);
        mainMenu[i].setFillColor(Color::Black); //black color
        mainMenu[i].setCharacterSize(70);
        mainMenu[i].setPosition(400, 180+100*i);
    }
	mainMenu[0].setString("Play");
	mainMenu[1].setPosition(250, 280);
	mainMenu[1].setString("How to play");
	mainMenu[2].setString("About");
	mainMenu[3].setString("Exit");
	MainMenuSelected = 0;
    mainMenu[MainMenuSelected].setFillColor(Color::Blue);

	//set background for Main menu
	menu_background.setSize(Vector2f(WIDTH, HEIGHT));
	Maintexture.loadFromFile("Images/menu.jpg");
	menu_background.setTexture(&Maintexture);
	//Set background for HowtoPlay
	background1.setSize(Vector2f(WIDTH, HEIGHT));
	tex1.loadFromFile("Images/howtoplay.jpg");
	background1.setTexture(&tex1);
	//Set background for About
	background2.setSize(Vector2f(WIDTH, HEIGHT));
	tex2.loadFromFile("Images/about.jpg");
	background2.setTexture(&tex2);
	//set homeButtontexture
    homeButton_tex.loadFromFile("Images/homeButton.png");
    homeButton.setTexture(homeButton_tex);
	homeButton.setPosition(25,25);
  	homeButton.setScale(0.15,0.15);
	//Set about text
	std::string detail;
    std::fstream aboutFile;
    aboutFile.open(("Images/about.txt"));
    if(aboutFile)
    {
        while(getline(aboutFile, detail))
        {
            aboutTextString.append(detail + "\n");
        }
    }
    aboutText.setString(aboutTextString);
    aboutText.setFont(font);
    aboutText.setCharacterSize(30);
    aboutText.setPosition(150, 100);
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
	RenderWindow MENU(VideoMode(WIDTH, HEIGHT), "Main Menu", Style::None);
    while (MENU.isOpen())
	{
		draw(MENU);
		MENU.display();
		Event event;
		while (MENU.pollEvent(event)) {
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
    window.draw(menu_background);
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
   RenderWindow HowtoPlay(VideoMode(WIDTH, HEIGHT), "HOW TO PLAY",Style::None);
   while (HowtoPlay.isOpen()) {
        Event aevent;
        while (HowtoPlay.pollEvent(aevent)) {
            if (aevent.type == Event::KeyPressed) {
                if (aevent.key.code == Keyboard::Escape)
                    HowtoPlay.close();
            }
            if (homeButton.getGlobalBounds().contains(Mouse::getPosition(HowtoPlay).x, Mouse::getPosition(HowtoPlay).y)){
                if (Mouse::isButtonPressed(Mouse::Left)){
                    HowtoPlay.close();
            }
        }}
        HowtoPlay.clear();
        HowtoPlay.draw(background1);
        HowtoPlay.draw(homeButton);
        HowtoPlay.display();
	}
	show();
	return 0;
}

int MainMenu::About(){
    int x=0;
    RenderWindow ABOUT(VideoMode(WIDTH, HEIGHT), "ABOUT",Style::None);
    while (ABOUT.isOpen()) {
        Event aevent;
        while (ABOUT.pollEvent(aevent)) {
            if (aevent.type == Event::KeyPressed) {
                if (aevent.key.code == Keyboard::Escape) {
                    ABOUT.close();
            }}
            if (homeButton.getGlobalBounds().contains(Mouse::getPosition(ABOUT).x, Mouse::getPosition(ABOUT).y)){
                if (Mouse::isButtonPressed(Mouse::Left)){
                    ABOUT.close();
            }
            }
        }
        x++;
        ABOUT.clear(Color(255,253,208));
        //ABOUT.draw(background2);
        aboutText.setFillColor(Color(x-40,x+50,0));
        ABOUT.draw(aboutText);
        ABOUT.draw(homeButton);
        ABOUT.display();
    }
    show();
    return 0;
}

#include "game.h"

Game::Game(){
    mWindow.create(sf::VideoMode(1380, 850), "Baagchaal", sf::Style::Default);
    goatChosen=0;
    tigerTurn=false;
    tigerWin=false;
    goatWin=false;
    gameOver=false;
    goatChosen=0;
    goatEaten=0;
    quit = false;
    pos=Mouse::getPosition(mWindow);
    homeButtonTexture.loadFromFile("Images/homeButton.png");
    homeButtonImage.setTexture(&homeButtonTexture);
    homeButtonImage.setPosition(25,25);
    homeButtonImage.setSize(Vector2f(0.15,0.17));
    tigerWinTexture.loadFromFile("Images/tigerWins.jpg");
    tigerWinImage.setTexture(&tigerWinTexture);
    tigerWinImage.setPosition(0,0);
    tigerWinImage.setSize(Vector2f(800,600));
    goatWinTexture.loadFromFile("Images/goatWins.jpg");
    goatWinImage.setTexture(&goatWinTexture);
    goatWinImage.setPosition(0,0);
    goatWinImage.setSize(Vector2f(800,600));
}


void Game::getBestMove() {
    if (tigerTurn) {
        std::map<int, std::vector<Cell>> moves = board.getTigerMoves();

        int random_tiger = rand() % 4;
        int random_move = rand() % moves[random_tiger].size();

        board.moveTiger(random_tiger, moves[random_tiger][random_move]);
        tigerTurn = false;
    }
}

void Game::processEvents()
{
    while (mWindow.pollEvent(event)) {
        pos=sf::Mouse::getPosition(mWindow);
        if (event.type == sf::Event::Closed) {
            quit= true;
        }
        if (event.type == sf::Event::KeyPressed) {
            handlePlayerInput(event.key.code);
        }
        if(tigerTurn) {
            // board.tigerMove(event, mWindow);//for the movement of goat
            getBestMove();

            tigerTurn = false;
            if(board.eatGoat(&goat[0]))//checks if the the move if goat eating move
            {
                goatEaten++;
                board.goatEatenMoveSound.play();
            }
        }
        else if(goatChosen<20)//placing the goat
        {
            board.placements(event,mWindow,&goat[goatChosen]);
            if(board.getState())
            {
                tigerTurn = true;
                goatChosen++;
                board.setState(false);
            }
        }
        else if(goatChosen>=20)
        {
            board.goatMove(event,pos,&goat[0]);//moving the goat after all the goats are pressed
            if(board.getState())
            {
                tigerTurn=true;
                board.setState(false);
            }
        }
    }
    if(gameOver and homeButtonImage.getGlobalBounds().contains(pos.x,pos.y))
    {
        if(event.type==sf::Event::MouseButtonPressed) {
            mWindow.close();
            MainMenu menu;
            menu.show();
        }
    }
}

void Game::handlePlayerInput(sf::Keyboard::Key & key)
{
    switch(key)
    {
        case sf::Keyboard::Escape:
            MainMenu myMenu();
            quit= true;
            break;

    }
}

int Game::run()//main game loop
{
    while(mWindow.isOpen())
    {
        mWindow.clear();
        if(quit)
        {
            quitGame q;
            q.close_window(mWindow);
            quit=false;
        }
        processEvents();
        if(!gameOver)
            board.render(mWindow,&goat[0],&tigerTurn,tigerWin,goatWin,20-goatChosen,goatEaten);
        checkGameOver(mWindow);
        mWindow.display();
    }
    return 0;
}

void Game::checkGameOver(sf::RenderWindow& Window)//checks if the game is over
{
    if(goatEaten>=4 )
    {
        gameOver=true;
        Window.close();
        tigerWins();
    }
    if(board.goatWin())
    {
        gameOver=true;
        Window.close();
        goatWins();
    }
}



void Game::goatWins()
{
    sf::RenderWindow mWindow1;
    mWindow1.create(sf::VideoMode(800, 600), "Congrats");
    while(mWindow1.isOpen()){
    mWindow1.clear();
    mWindow1.draw(goatWinImage);
    homeButtonImage.setPosition(50,50);
    mWindow1.draw(homeButtonImage);
    mWindow1.display();
    Event aevent;
        while (mWindow1.pollEvent(aevent)) {
            if(aevent.type == Event::Closed){
                mWindow1.close();
            }
            if (aevent.type == Event::KeyPressed) {
                if (aevent.key.code == Keyboard::Escape)
                    mWindow1.close();
            }
            if (homeButtonImage.getGlobalBounds().contains(Mouse::getPosition(mWindow1).x, Mouse::getPosition(mWindow1).y)){
                if (Mouse::isButtonPressed(Mouse::Left)){
                    mWindow1.close();
            }
    }
}
    }
}

void Game::tigerWins()
{
    sf::RenderWindow mWindow1;
    mWindow1.create(sf::VideoMode(800, 600), "Congrats");
    while(mWindow1.isOpen()){
    mWindow1.clear();
    mWindow1.draw(tigerWinImage);
    homeButtonImage.setPosition(50,50);
    mWindow1.draw(homeButtonImage);
    mWindow1.display();
     Event aevent;
        while (mWindow1.pollEvent(aevent)) {
            if(aevent.type == Event::Closed){
                mWindow1.close();
            }
            if (aevent.type == Event::KeyPressed) {
                if (aevent.key.code == Keyboard::Escape)
                    mWindow1.close();
            }
            if (homeButtonImage.getGlobalBounds().contains(Mouse::getPosition(mWindow1).x, Mouse::getPosition(mWindow1).y)){
                if (Mouse::isButtonPressed(Mouse::Left)){
                    mWindow1.close();
            }
    }
}
    }
}

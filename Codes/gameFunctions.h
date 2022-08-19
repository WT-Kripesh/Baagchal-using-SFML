#ifndef GAMEFUNCTIONS_H_INCLUDED
#define GAMEFUNCTIONS_H_INCLUDED

 int selectedRow;
 int selectedColumn;

 void setIndices(Tiger t[4], Goat g[20])
 {
 for(int i=0;i<4;i++){t[i].index=i;}
 for(int i=0;i<20;i++){g[i].index=i;}
 }


 void set_all_tigerTexture(Tiger t[4])
 {
     for(int i=0;i<4;i++)
        {
        t[i].set_texture();
        }
 }

 void set_all_goatTexture(Goat g[20])
    {
        for(int i=0;i<20;i++)
            {
        g[i].set_texture();
            }
    }

 void initial_positions(Tiger t[4], Matrix matrix[6][6])
    {
        int tigerCount=0;
        for(int i=1;i<=5;i++)
        {
        for(int j=1;j<=5;j++)
        {
            if((i==1 || i==5) && (j==1 || j==5))
                {
                    t[tigerCount].row=i;
                    t[tigerCount].column=j;
                    matrix[i][j].row=i;
                    matrix[i][j].column=j;
                    matrix[i][j].content='T';
                    matrix[i][j].content_index=tigerCount;
                    tigerCount++;
                }
        }
        }
    }

    int getPixelX(int row){return  280+ (row - 1) * 125;}
    int getPixelY(int column){return  150+ (column - 1) * 125;}

    void input(RenderWindow& Play, Matrix matrix[6][6]){
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
							{
								int mouseX = Mouse::getPosition(Play).x;
								int mouseY = Mouse::getPosition(Play).y;
								for (int i = 1; i <= 5; i++)
								{
									for (int j = 0; j <= 5; j++)
									{
										if ( (mouseX >= (getPixelX(matrix[i][j].row)-50)) && (mouseX <= (getPixelX(matrix[i][j].row)+ 50)) ) {selectedRow=i;}
                                        if (((mouseY >= (getPixelY(matrix[i][j].column)-50))) && (mouseY <= (getPixelY(matrix[i][j].column)+50))) {selectedColumn=j;}
									}
								}
							}
    }

void close_window(RenderWindow& play){
    Font font;
    font.loadFromFile("Fonts/Contra.ttf");
    Text text[3];
    for(int i=0;i<3;i++)
    {
        text[i].setFont(font);//sets font for text
        text[i].setCharacterSize(16);
        text[i].setFillColor(sf::Color::Black);
    }
    //text[0].setCharacterSize(16);
    //Sets co ordinates for text text
    text[0].setPosition(10,10);
    text[1].setPosition(100,70);
    text[2].setPosition(350,70);

    //Sting values for text text
    text[0].setString("Are you sure you want to quit?\n**Your data will be lost!");
    text[1].setString("Yes");
    text[2].setString("No");

    RenderWindow Quit(VideoMode(500, 100), "QUIT",Style::Close);
    while(Quit.isOpen())
    {
        Event event;
        while (Quit.pollEvent(event))
        {
            if(event.type == Event::Closed)
                Quit.close();
            Vector2i mouse;
            mouse=Mouse::getPosition(Quit);

            if(text[1].getGlobalBounds().contains(mouse.x,mouse.y))
            {
                text[1].setFillColor(sf::Color::Red);
                if (Mouse::isButtonPressed(Mouse::Left)) {
                    Quit.close();
                    play.close();
                }
            }
            else if(text[2].getGlobalBounds().contains(mouse.x,mouse.y))
            {
                text[2].setFillColor(sf::Color::Red);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    Quit.close();
                }
            }
            else
            {
                text[1].setFillColor(sf::Color::Black);
                text[2].setFillColor(sf::Color::Black);
            }
        }
        Quit.clear(Color(119,221,119));
        for(int i=0;i<3;i++){
            Quit.draw(text[i]);
        }
        Quit.display();
    }
}
#endif

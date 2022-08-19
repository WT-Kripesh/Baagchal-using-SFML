#ifndef GAMEFUNCTIONS_H_INCLUDED
#define GAMEFUNCTIONS_H_INCLUDED

 int selectedRow;
 int selectedColumn;

 void setIndices(Tiger& t, Goat& g)
 {
 for(int i=0;i<4;i++){t[i].index=i;}
 for(int i=0;i<20;i++){g[i].index=i;}
 }


 void set_all_tigerTexture(Tiger& t)
 {
     for(int i=0;i<4;i++)
        {
        t[i].set_texture();
        }
 }

 void set_all_goatTexture(Goat& g)
    {
        for(int i=0;i<20;i++)
            {
        g[i].set_texture();
            }
    }

 void initial_positions(Tiger& t)
    {
        int tigerCount=0;
        for(int i=1;i<=5;i++)
        {
        for(int j=1;j<=5;j++)
        {
            if((i==1 || i==5) && (j==1 || j==5)
                {
                    t[tigerCount].row=i;
                    t[tigerCount].column=j;
                    tigerCount++;
                    cell[i][j].row=i;
                    cell[i][j].column=j;
                    cell[i][j].content="Tiger";
                    cell[i][j].index=tigerCount;
                }
        }
        }
    }

    int getPixelX(int row){return  280+ (row - 1) * 125;}
    int getPixelY(int column){return  150+ (column - 1) * 125;}

    void input(){
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
							{
								int mouseX = Mouse::getPosition(Play).x;
								int mouseY = Mouse::getPosition(Play).y;
								for (int i = 1; i <= 5; i++)
								{
									for (int j = 0; j <= 5; j++)
									{
										if (((mouseX >= (getPixelX(cell[i][j].row)-50) && (mouseX <= (getPixelX(cell[i][j].row)+ 50)))  && ((mouseY >= (getPixelY(cell[i][j].column)-50)) && (mouseY <= (getPixelY(cell[i][j].column)+50))))
										{
											selectedRow = i;
											selectedColumn = j;
										}
									}
								}
							}
    }
#endif

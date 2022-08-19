#ifndef GAMEFUNCTIONS_H_INCLUDED
#define GAMEFUNCTIONS_H_INCLUDED

 int selectedRow=0;
 int selectedColumn=0;

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
                    matrix[i][j].content='T';
                    matrix[i][j].content_index=tigerCount;
                    tigerCount++;
                }
        }
        }
    }

    void matrix_initialization(Matrix matrix[6][6]){
    for(int i=1;i<=5;i++){
            for(int j=1;j<=5;j++){
            matrix[i][j].row=i;
            matrix[i][j].column=j;
    }}
    }

    int getPixelX(int row){return  280+ ((row - 1) * 125);}
    int getPixelY(int column){return  150+ ((column - 1) * 125);}

    void draw(RenderWindow& Play, Matrix matrix[6][6],Tiger tiger[4],Goat goat[20])
    {
        for (int i = 1; i <= 5; i++)
								{
									for (int j = 0; j <= 5; j++)
									{
										if(matrix[i][j].content=='T')
                                            {
                                                //Tiger tdraw=tiger[matrix[i][j].indexGetter()];
                                                tiger[matrix[i][j].content_index].set_texture();
                                                tiger[matrix[i][j].content_index].set_Position();
                                                Play.draw(tiger[matrix[i][j].content_index].tiger_sprite);
                                            }
                                            else if(matrix[i][j].content=='G')
                                            {

                                                goat[matrix[i][j].content_index].set_texture();
                                                goat[matrix[i][j].content_index].set_Position();
                                                Play.draw(goat[matrix[i][j].content_index].goat_sprite);
                                            }
                                            else{//Draws nothing}
									}
								}
    }
    }

    void input(RenderWindow& Play, Matrix matrix[6][6]){
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
							{
								int mouseX = Mouse::getPosition(Play).x;
								int mouseY = Mouse::getPosition(Play).y;
								for (int i = 1; i <= 5; i++)
								{
									for (int j = 1; j <= 5; j++)
									{
										if (((mouseX >= (getPixelX(matrix[i][j].row)-50)) && (mouseX <= (getPixelX(matrix[i][j].row)+50)))  && ((mouseY >= (getPixelY(matrix[i][j].column)-50)) && (mouseY <= (getPixelX(matrix[i][j].column)+50))))
										{
											selectedRow = i;
											selectedColumn = j;
										}
									}
								}
cout<<selectedRow<<"\t"<<selectedColumn<<endl;

							}
    }
int goat_count=0;
     void process(RenderWindow& Play, Matrix matrix[6][6],Tiger tiger[4],Goat goat[20])
     {
         //Input Goat
        matrix[0][0].content='X';
          if(matrix[selectedRow][selectedColumn].content=='N' && goat_count<=20)
          {
            goat[goat_count].row=selectedRow;
            goat[goat_count].column=selectedColumn;
            matrix[selectedRow][selectedColumn].content='G';
            matrix[selectedRow][selectedColumn].content_index=goat_count;
            matrix[selectedRow][selectedColumn].row=selectedRow;
            matrix[selectedRow][selectedColumn].column=selectedColumn;
            goat_count++;
            cout<<goat_count<<endl;
            //selectedRow=0;selectedColumn=0;     //Selection reset
          }
        }
#endif

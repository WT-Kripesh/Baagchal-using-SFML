#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

class Matrix{
public:
    char content='N';//COULD BE T, G , D & N
    int tiger_index,goat_index;
    int row,column;
    static int i,j;
    Matrix(){
        row=i;column=j;
        j++;
        if(j==6){
            i++;j=0;
        }
    }
};

int Matrix::i=0;
int Matrix::j=0;

#endif

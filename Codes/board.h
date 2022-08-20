#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
static int i=0,j=0;
class Matrix{
public:
    char content='N';//COULD BE T, G OR N
    int content_index;
    int row,column;
public:
    Matrix(){
        row=i;column=j;
        j++;
        if(j==5){
            i++;j=0;
        }
    }
};



#endif

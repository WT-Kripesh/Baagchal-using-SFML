#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
class Matrix{
public:
    char content='N';//COULD BE T, G OR N
    int content_index;
    int row,column;

    char content_getter()
    {
        return this->content;
    }

     int indexGetter()
    {
        return this->content_index;
    }
};


#endif

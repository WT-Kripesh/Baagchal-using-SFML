#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
class Cell{
public:
    string content="NULL"; //COULD BE TIGER, GOAT OR NULL
    int content_index;
    int row,column;

    string content_getter()
    {
        return this->content;
    }

     int index()
    {
        return this->content_index;
    }
};

Cell cell[6][6];

#endif

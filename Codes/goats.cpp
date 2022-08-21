
#include "goats.h"

Goat::Goat()
{
    state=Dead;
    texture.loadFromFile("Images/goat.png");
    image.setTexture(&texture);
    image.setRadius(35);
}



goatState Goat::getState() {
    return state;
}

void Goat::setState(goatState _state)
{
    state=_state;
}





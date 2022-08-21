
#include "tigers.h"
Tiger::Tiger()
{
    texture.loadFromFile("Images/tiger.png");
    image.setTexture(&texture);
    image.setRadius(40);
}

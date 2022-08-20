
#include "tigers.h"
Tiger::Tiger()
{
    texture.loadFromFile("Media/Images/tiger.jpg");
    image.setTexture(&texture);
    image.setRadius(40);
}

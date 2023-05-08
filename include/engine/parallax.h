#ifndef PARALLAX_H
#define PARALLAX_H

#include "element.h"

class Parallax
{
private:
    bool firstTime = true;
    Element firstElement;
    Element secondElement;
    int firstElementPosition = 0;
    int secondElementPosition = 0;

public:
    Parallax();
    Parallax(std::string textureImagePath, unsigned int heigth, unsigned int width);
    void render(float deltaTime, float velocity);
    void setPositionY(float position);

};

#endif
#include "parallax.h"

Parallax::Parallax()
{
}

Parallax::Parallax(std::string textureImagePath, unsigned int heigth, unsigned int width)
{
    this->firstElement = Element(textureImagePath, heigth, width);
    this->secondElement = Element(textureImagePath, heigth, width);
    secondElement.setPositionX(1280);
}

void Parallax::setPositionY(float position)
{
    this->firstElement.setPositionY(position);
    this->secondElement.setPositionY(position);
}

void Parallax::render(float deltaTime, float velocity)
{
    // Renderiza chão
    firstElement.translateXAxis(-velocity);
    secondElement.translateXAxis(-velocity);
    firstElementPosition += velocity;
    secondElementPosition += velocity;
    
    float multiplier = 2;
    if (!this->firstTime) {
        multiplier = 4;
    }

    if (firstElementPosition >= 1280 * multiplier)
    {
        firstElementPosition = 0;
        firstElement.setPositionX(1280);
        this->firstTime = false;
    }
    if (secondElementPosition >= 1280 * 4)
    {
        secondElementPosition = 0;
        secondElement.setPositionX(1280);
    }
    firstElement.render(deltaTime);
    secondElement.render(deltaTime);
}

#include "sprite.h"

Sprite::Sprite()
{
}
void Sprite::defineAnimation(unsigned int spriteInitialPosition, unsigned int spriteFinalPosition, unsigned int spriteLengthPosition, float durationAnimation)
{
    this->spriteInitialPosition = spriteInitialPosition;
    this->actualPosition = spriteInitialPosition - 1;
    this->spriteFinalPosition = spriteFinalPosition;
    this->spriteLengthPosition = spriteLengthPosition;
    this->durationAnimation = durationAnimation;
}
void Sprite::defineTextureCoordinates(float deltaTime, float *vertexes)
{
    // Se tem que mudar a sprite da animação
    this->spriteTime += deltaTime;
    if (this->spriteTime >= this->durationAnimation / (float)spriteFinalPosition)
    {
        // Inicia valores da nova sprite da animação
        this->spriteTime = 0;
        this->actualPosition++;
        if (this->actualPosition > this->spriteLengthPosition)
            this->actualPosition = this->spriteInitialPosition;

        // Calcula nova posição do mapeando de textura
        float spriteSize = 1.0 / (this->spriteLengthPosition);
        vertexes[6] = this->actualPosition * spriteSize - spriteSize;
        vertexes[14] = this->actualPosition * spriteSize - spriteSize;
        vertexes[22] = this->actualPosition * spriteSize;
        vertexes[30] = this->actualPosition * spriteSize;
    }
}

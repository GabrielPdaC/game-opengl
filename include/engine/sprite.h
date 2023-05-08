#ifndef SPRITE_H
#define SPRITE_H

class Sprite
{
private:
    unsigned int actualPosition = 0;
    unsigned int spriteInitialPosition = 0;
    unsigned int spriteFinalPosition = 0;
    unsigned int spriteLengthPosition = 0;
    float spriteTime = 0;
    float durationAnimation = 0;
public:
    Sprite();
    void defineAnimation(unsigned int spriteInitialPosition, unsigned int spriteFinalPosition, unsigned int spriteLengthPosition, float durationAnimation);
    void defineTextureCoordinates(float deltaTime, float *vertexes);
};

#endif
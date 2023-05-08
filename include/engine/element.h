#ifndef ELEMENT_H
#define ELEMENT_H

#include "shader.h"
#include "sprite.h"
#include "texture.h"

class Element
{
private:
    unsigned int id;
    float vertexes[32] = {
        // positions      // colors         // texture coords
        0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, // bottom left
        0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, // top left
        1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.33f, 1.0f, // top right
        1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.33f, 0.0f  // bottom right
    };
    unsigned int indexes[6] = {
        0, 1, 3, // first Triangle
        1, 2, 3  // second Triangle
    };
    Texture texture;
    Shader shader;
    Sprite sprite;

    void setStartPositionVertexes(float heigth, float width);
    void draw(float *vertexes, int vertexesSizes, unsigned int *indexes, int indexesSize);

public:
    Element();
    Element(std::string textureImagePath, unsigned int heigth, unsigned int width);
    void render(float deltaTime);
    void setSprite(unsigned int spriteInitialPosition, unsigned int spriteFinalPosition, unsigned int spriteLenghtPosition, float duration);
    float* getPosition();

    void translateXAxis(float velocity);
    void translateYAxis(float velocity);
    void setPositionX(unsigned int position);    
    void setPositionY(unsigned int position);
    void turnRight();
    void turnLeft();
    // void sprite(unsigned int pos, float deltaTime);
    void flipHorizontal();
};

#endif
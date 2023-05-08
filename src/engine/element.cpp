#include "element.h"

#include <glad/glad.h>

Element::Element()
{
}

Element::Element(std::string textureImagePath, unsigned int heigth, unsigned int width)
{
        this->shader = Shader();
        this->shader.compile();

        this->texture = Texture(textureImagePath);
        this->texture.generate();

        this->sprite = Sprite();
        this->sprite.defineAnimation(1, 1, 1, 0.0);

        setStartPositionVertexes(heigth, width);
}

void Element::render(float deltaTime)
{
        this->shader.use();
        this->texture.active();
        this->sprite.defineTextureCoordinates(deltaTime, this->vertexes);

        unsigned int VAO, VBO, EBO;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertexes), this->vertexes, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->indexes), this->indexes, GL_STATIC_DRAW);
        // position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);
        // color attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
        // texture coord attribute
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));
        glEnableVertexAttribArray(2);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        glBindVertexArray(VAO); // seeing as we only have a single this->VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Element::setSprite(unsigned int spriteInitialPosition, unsigned int spriteFinalPosition, unsigned int spriteLenghtPosition, float duration)
{
        this->sprite.defineAnimation(spriteInitialPosition, spriteFinalPosition, spriteLenghtPosition, duration);
}

float* Element::getPosition()
{
        return this->vertexes;
}

void Element::translateXAxis(float velocity)
{
        float velocityFactor = (float)(velocity / 1280.0);

        this->vertexes[0] += velocityFactor;
        this->vertexes[8] += velocityFactor;
        this->vertexes[16] += velocityFactor;
        this->vertexes[24] += velocityFactor;
}

void Element::translateYAxis(float velocity)
{
        float velocityFactor = (float)(velocity / 720.0);

        this->vertexes[1] += velocityFactor;
        this->vertexes[9] += velocityFactor;
        this->vertexes[17] += velocityFactor;
        this->vertexes[25] += velocityFactor;
}
void Element::setPositionX(unsigned int position)
{
        float positionX = (float)((position / 1280.0 * 2) - 1);
        float diff = this->vertexes[16] - this->vertexes[0];

        this->vertexes[0] = positionX;
        this->vertexes[8] = positionX;
        this->vertexes[16] = positionX + diff;
        this->vertexes[24] = positionX + diff;
}

void Element::setPositionY(unsigned int position)
{
        float positionY = (float)((position / 720.0 * 2) -1);
        float diff = this->vertexes[9] - this->vertexes[1];

        this->vertexes[1] = positionY;
        this->vertexes[9] = positionY + diff;
        this->vertexes[17] = positionY + diff;
        this->vertexes[25] = positionY;
}

void Element::turnRight()
{
        if (this->vertexes[22] < 0)
                flipHorizontal();
}
void Element::turnLeft()
{
        if (this->vertexes[22] > 0)
                flipHorizontal();
}

void Element::flipHorizontal()
{
        this->vertexes[6] *= -1.0;
        this->vertexes[14] *= -1.0;
        this->vertexes[22] *= -1.0;
        this->vertexes[30] *= -1.0;
}

void Element::setStartPositionVertexes(float heigth, float width)
{
        float widthFactor = (float)(width / 1280.0) * 2.0 - 1.0;
        float heigthFactor = (float)(heigth / 720.0) * 2.0 - 1.0;
        this->vertexes[0] = -1.0;
        this->vertexes[1] = -1.0;
        this->vertexes[8] = -1.0;
        this->vertexes[9] = heigthFactor;
        this->vertexes[16] = widthFactor;
        this->vertexes[17] = heigthFactor;
        this->vertexes[24] = widthFactor;
        this->vertexes[25] = -1.0;
}

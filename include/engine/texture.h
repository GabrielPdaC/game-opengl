#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>

class Texture
{
private:
    unsigned int textureId;
    std::string imagePath;
    int width;
    int height;
public:
    Texture();
    Texture(std::string imagePath);
    void generate();
    void active();
    int getWidth();
    int getHeight();
};

#endif
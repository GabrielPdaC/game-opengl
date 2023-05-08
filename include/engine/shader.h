#ifndef SHADER_H
#define SHADER_H

#include <iostream>

class Shader
{
private:
    unsigned int shaderProgramId;
    std::string vertexShaderSource;
    std::string fragmentShaderSource;
    std::string readShader(std::string shaderPath);
public:
    Shader();
    Shader(std::string vertexShaderPath, std::string fragmentShaderPath);
    void compile();
    void use();
    unsigned int getShaderProgramId();
};

#endif
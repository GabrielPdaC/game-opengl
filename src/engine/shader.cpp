#define DEFAULT_VERTEX_SHADER_PATH "/home/gabrielpdc/workspace/game-opengl/src/shaders/default-vert.glsl"
#define DEFAULT_FRAGMENT_SHADER_PATH "/home/gabrielpdc/workspace/game-opengl/src/shaders/default-frag.glsl"

#include "shader.h"

#include <fstream>
#include <glad/glad.h>
#include <sstream>
#include <iostream>

Shader::Shader()
{
    this->vertexShaderSource = readShader(DEFAULT_VERTEX_SHADER_PATH);
    this->fragmentShaderSource = readShader(DEFAULT_FRAGMENT_SHADER_PATH);
}

Shader::Shader(std::string vertexShaderPath, std::string fragmentShaderPath)
{
    this->vertexShaderSource = readShader(vertexShaderPath);
    this->fragmentShaderSource = readShader(fragmentShaderPath);
}

std::string Shader::readShader(std::string shaderPath)
{
    // open shader files
    std::ifstream shaderFile(shaderPath);
    std::stringstream shaderStream;
    // read file's buffer contents into streams
    shaderStream << shaderFile.rdbuf();
    // close file handlers
    shaderFile.close();
    // convert stream into string
    return shaderStream.str();
}

void Shader::compile()
{
    // compile vertex shader source
    const char *vertexShaderSource = this->vertexShaderSource.c_str();
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // compile fragment shader source
    const char *fragmentShaderSource = this->fragmentShaderSource.c_str();
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // attach shader into program
    this->shaderProgramId = glCreateProgram();
    glAttachShader(this->shaderProgramId, vertexShader);
    glAttachShader(this->shaderProgramId, fragmentShader);
    glLinkProgram(this->shaderProgramId);
}

void Shader::use()
{
    glUseProgram(this->shaderProgramId);
}

unsigned int Shader::getShaderProgramId()
{
    return this->shaderProgramId;
}
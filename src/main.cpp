#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include "element.h"
#include "parallax.h"

void processInput(GLFWwindow *window);

bool jump = false;
int velocity = 0;

int enemyPosition = 0;
int enemy2Position = 0;

int points = 0;
int gameState = 0;

int main()
{

    // Inicializa GLFW
    glfwInit();

    // Cria uma janela e define ela como contexto atual
    GLFWwindow *window = glfwCreateWindow(1280, 720, "main", NULL, NULL);
    glfwMakeContextCurrent(window);

    // Inicializa glad para gerenciar ponteiros de funções
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glViewport(0, 0, 1280, 720);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    Element background = Element("../resources/images/background/trees-background.png", 720, 1280);

    Parallax backTrees = Parallax("../resources/images/background/back-trees.png", 720, 1280);
    backTrees.setPositionY(40);
    Parallax middleTrees = Parallax("../resources/images/background/middle-trees.png", 720, 1280);
    middleTrees.setPositionY(40);
    Parallax frontTrees = Parallax("../resources/images/background/front-trees.png", 720, 1280);
    frontTrees.setPositionY(40);

    Parallax floor = Parallax("../resources/images/background/floor.png", 80, 1280);

    Element capybara = Element("../resources/images/capybara-sprite.png", 150, 100);
    capybara.setSprite(1, 3, 3, 0.2);
    capybara.setPositionY(40);
    capybara.setPositionX(20);

    Element enemy = Element("../resources/images/crocodille.png", 60, 200);
    enemy.setPositionY(50);
    enemy.setPositionX(1280);

    // Loop principal
    while (!glfwWindowShouldClose(window))
    {
        // Calcula tempo por frame
        static float lastFrameTime = 0.0f;
        float currentFrameTime = glfwGetTime();
        float deltaTime = currentFrameTime - lastFrameTime;
        lastFrameTime = currentFrameTime;

        // Processa entradas
        processInput(window);
        // Define uma coloração para a janela
        glClearColor(0.08f, 0.18f, 0.18f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Renderiza fundo fixo
        background.render(deltaTime);
        // Renderiza parallax
        backTrees.render(deltaTime, 1);
        middleTrees.render(deltaTime, 3);
        frontTrees.render(deltaTime, 5);
        floor.render(deltaTime, 12);

        // Renderiza capivara
        if (jump)
        {
            if (velocity >= -33)
            {
                capybara.setSprite(1, 1, 3, 0.01);
                velocity--;
                capybara.translateYAxis(velocity);
            }
            else
            {
                capybara.setSprite(1, 3, 3, 0.3);
                jump = false;
            }
        }
        capybara.render(deltaTime);

        // Renderiza inimigo
        enemy.translateXAxis(-12);
        enemyPosition += 12;
        if (enemyPosition >= (1280+200)*2){
            enemyPosition = 0;
            enemy.setPositionX(1280);
            points++;
        }
        enemy.render(deltaTime);

        // Detecta a colisão
        float *capybaraPosition = capybara.getPosition();
        float *enemyPostion = enemy.getPosition();

        if (capybaraPosition[0] > enemyPostion[8] && capybaraPosition[0] < enemyPostion[16] && capybaraPosition[1] < enemyPostion[9] ||
            capybaraPosition[24] > enemyPostion[8] && capybaraPosition[24] < enemyPostion[16] && capybaraPosition[1] < enemyPostion[9])
            glfwSetWindowShouldClose(window, true);

        std::cout << points << std::endl;
        // Troca o buffer de exibição
        glfwSwapBuffers(window);
        // Verifica eventos do GLFW
        glfwPollEvents();
    }
    // Encerra GLFW
    glfwTerminate();

    return 0;
}

void processInput(GLFWwindow *window)
{
    float v = 10;

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }

    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS && !jump)
    {
        jump = true;
        velocity = 35;
    }
}

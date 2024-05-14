#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <vector>

const int mapWidth = 20;
const int mapHeight = 20;
const int map[mapWidth][mapHeight] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

float playerX = 5.0f, playerY = 5.0f, playerZ = 1.0f;
float playerAngle = 0.0f;

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        float newX = playerX + cos(playerAngle) * 0.005f;
        float newY = playerY + sin(playerAngle) * 0.005f;
        if (map[(int)newX][(int)newY] == 0) {
            playerX = newX;
            playerY = newY;
        }
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        float newX = playerX - cos(playerAngle) * 0.005f;
        float newY = playerY - sin(playerAngle) * 0.005f;
        if (map[(int)newX][(int)newY] == 0) {
            playerX = newX;
            playerY = newY;
        }
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        float newX = playerX - cos(playerAngle + glm::radians(90.0f)) * 0.005f;
        float newY = playerY - sin(playerAngle + glm::radians(90.0f)) * 0.005f;
        if (map[(int)newX][(int)newY] == 0) {
            playerX = newX;
            playerY = newY;
        }
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        float newX = playerX + cos(playerAngle + glm::radians(90.0f)) * 0.005f;
        float newY = playerY + sin(playerAngle + glm::radians(90.0f)) * 0.005f;
        if (map[(int)newX][(int)newY] == 0) {
            playerX = newX;
            playerY = newY;
        }
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        playerAngle -= 0.005f;
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        playerAngle += 0.005f;
    }
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void drawMap() {
    glBegin(GL_QUADS);
    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            if (map[x][y] == 1) {
                glColor3f(0.0f, 1.0f, 1.0f);
            } else {
                glColor3f(0.0f, 0.0f, 0.0f);
            }
            glVertex3f(x, y, 0.0f);
            glVertex3f(x + 1.0f, y, 0.0f);
            glVertex3f(x + 1.0f, y + 1.0f, 0.0f);
            glVertex3f(x, y + 1.0f, 0.0f);
        }
    }
    glEnd();
}

void drawPlayer() {
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(playerX - 0.1f, playerY - 0.1f, playerZ);
    glVertex3f(playerX + 0.1f, playerY - 0.1f, playerZ);
    glVertex3f(playerX + 0.1f, playerY + 0.1f, playerZ);
    glVertex3f(playerX - 0.1f, playerY + 0.1f, playerZ);
    glEnd();
}

void castRays() {
    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_LINES);
    for (int i = -45; i <= 45; i += 2) {
        float rayAngle = playerAngle + glm::radians(static_cast<float>(i));
        float rayX = playerX;
        float rayY = playerY;
        float stepSize = 0.1f;
        float stepX = cos(rayAngle) * stepSize;
        float stepY = sin(rayAngle) * stepSize;

        while (map[(int)rayX][(int)rayY] == 0) {
            rayX += stepX;
            rayY += stepY;
        }

        glVertex3f(playerX, playerY, playerZ);
        glVertex3f(rayX, rayY, playerZ);
    }
    glEnd();
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(1920, 1080, "Raycasting", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);
    glfwSetWindowMonitor(window, primaryMonitor, 0, 0, mode->width, mode->height, mode->refreshRate);

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0f, mapWidth, mapHeight, 0.0f, -1.0f, 1.0f);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        drawMap();
        castRays();
        drawPlayer();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <vector>

const int mapWidth = 20;
const int mapHeight = 20;
const int map[mapWidth][mapHeight] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

float playerX = 5.0f, playerY = 1.0f, playerZ = 5.0f;
float playerAngle = 0.0f;
float rotateAngleX = 0.0f, rotateAngleZ = 0.0f;

float lastX = 400, lastY = 300;
bool firstMouse = true;

void mouseCallback(GLFWwindow* window, double xpos, double ypos) {
    if (firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;

    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    rotateAngleZ += xoffset;
    rotateAngleX += yoffset;

    if (rotateAngleX > 90.0f)
        rotateAngleX = 90.0f;
    if (rotateAngleX < -90.0f)
        rotateAngleX = -90.0f;
}

void processInput(GLFWwindow *window) {
    float cameraSpeed = 0.005f;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        float newX = playerX + cos(glm::radians(rotateAngleZ)) * cameraSpeed;
        float newZ = playerZ + sin(glm::radians(rotateAngleZ)) * cameraSpeed;
        if (map[(int)newX][(int)newZ] == 0) {
            playerX = newX;
            playerZ = newZ;
        }
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        float newX = playerX - cos(glm::radians(rotateAngleZ)) * cameraSpeed;
        float newZ = playerZ - sin(glm::radians(rotateAngleZ)) * cameraSpeed;
        if (map[(int)newX][(int)newZ] == 0) {
            playerX = newX;
            playerZ = newZ;
        }
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        float newX = playerX - cos(glm::radians(rotateAngleZ + 90.0f)) * cameraSpeed;
        float newZ = playerZ - sin(glm::radians(rotateAngleZ + 90.0f)) * cameraSpeed;
        if (map[(int)newX][(int)newZ] == 0) {
            playerX = newX;
            playerZ = newZ;
        }
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        float newX = playerX + cos(glm::radians(rotateAngleZ + 90.0f)) * cameraSpeed;
        float newZ = playerZ + sin(glm::radians(rotateAngleZ + 90.0f)) * cameraSpeed;
        if (map[(int)newX][(int)newZ] == 0) {
            playerX = newX;
            playerZ = newZ;
        }
    }
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void drawCube(float x, float y, float z) {
    glBegin(GL_QUADS);

    glVertex3f(x - 0.5f, y - 0.5f, z + 0.5f);
    glVertex3f(x + 0.5f, y - 0.5f, z + 0.5f);
    glVertex3f(x + 0.5f, y + 0.5f, z + 0.5f);
    glVertex3f(x - 0.5f, y + 0.5f, z + 0.5f);

    glVertex3f(x - 0.5f, y - 0.5f, z - 0.5f);
    glVertex3f(x + 0.5f, y - 0.5f, z - 0.5f);
    glVertex3f(x + 0.5f, y + 0.5f, z - 0.5f);
    glVertex3f(x - 0.5f, y + 0.5f, z - 0.5f);

    glVertex3f(x - 0.5f, y + 0.5f, z - 0.5f);
    glVertex3f(x + 0.5f, y + 0.5f, z - 0.5f);
    glVertex3f(x + 0.5f, y + 0.5f, z + 0.5f);
    glVertex3f(x - 0.5f, y + 0.5f, z + 0.5f);

    glVertex3f(x - 0.5f, y - 0.5f, z - 0.5f);
    glVertex3f(x + 0.5f, y - 0.5f, z - 0.5f);
    glVertex3f(x + 0.5f, y - 0.5f, z + 0.5f);
    glVertex3f(x - 0.5f, y - 0.5f, z + 0.5f);

    glVertex3f(x - 0.5f, y - 0.5f, z - 0.5f);
    glVertex3f(x - 0.5f, y - 0.5f, z + 0.5f);
    glVertex3f(x - 0.5f, y + 0.5f, z + 0.5f);
    glVertex3f(x - 0.5f, y + 0.5f, z - 0.5f);

    glVertex3f(x + 0.5f, y - 0.5f, z - 0.5f);
    glVertex3f(x + 0.5f, y - 0.5f, z + 0.5f);
    glVertex3f(x + 0.5f, y + 0.5f, z + 0.5f);
    glVertex3f(x + 0.5f, y + 0.5f, z - 0.5f);
    glEnd();
}

void drawMap() {
    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            if (map[x][y] == 1) {
                glColor3f(0.0f, 1.0f, 1.0f);
                drawCube(x, 0.5f, y);
            }
        }
    }
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(1920, 1080, "3D Raycasting", NULL, NULL);
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

    glfwSetCursorPosCallback(window, mouseCallback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)mode->width / (float)mode->height, 0.1f, 100.0f);
        glLoadMatrixf(glm::value_ptr(projection));

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glm::mat4 view = glm::lookAt(glm::vec3(playerX, playerY, playerZ), glm::vec3(playerX + cos(glm::radians(rotateAngleZ)), playerY + sin(glm::radians(rotateAngleX)), playerZ + sin(glm::radians(rotateAngleZ))), glm::vec3(0.0f, 1.0f, 0.0f));
        glLoadMatrixf(glm::value_ptr(view));

        drawMap();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

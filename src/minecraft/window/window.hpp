#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdexcept>

class Window
{
public:
    Window(int width, int height);
    ~Window();

    void Show();
    void Update();
    bool IsCloseRequested() { return glfwWindowShouldClose(window); }

    int GetWidth() { return width; }
    int GetHeight() { return height; }
private:
    GLFWwindow *window;
    int width, height;

    static void sizeCallback(GLFWwindow *window, int w, int h);
};
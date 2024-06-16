#include "window.hpp"

Window::Window(int w, int h) : width {w}, height {h}
{
    if(!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW!");
    }

    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, "MinecraftClone", nullptr, nullptr);
    if(window == nullptr) {
        throw std::runtime_error("Failed to create the window!");
    }
    glfwSetWindowUserPointer(window, this);
    glfwMakeContextCurrent(window);

    glfwSetFramebufferSizeCallback(window, sizeCallback);

    gladLoadGL();
    glViewport(0, 0, width, height);
}

Window::~Window()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::Show()
{
    glfwShowWindow(window);
}

void Window::Update()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glfwPollEvents();
    glfwSwapBuffers(window);
}

void Window::sizeCallback(GLFWwindow *window, int w, int h)
{
    Window* win = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glfwGetCurrentContext()));
    win->width = w;
    win->height = h;

    glViewport(0, 0, w, h);
}
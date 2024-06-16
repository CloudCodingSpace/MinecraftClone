#pragma once

#include <stdexcept>
#include <iostream>

#include "window/window.hpp"
#include "renderer/renderer.hpp"

class MC 
{
public:
    MC();
    ~MC(); 

    void Run();
private:
    Window *window;
    Renderer *renderer;

    void Render();
    void Update();
};
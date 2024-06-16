#pragma once

#include <stdexcept>
#include <iostream>

#include "window/window.hpp"

class MC 
{
public:
    MC();
    ~MC(); 

    void Run();
private:
    Window *window;

    void Render();
    void Update();
};
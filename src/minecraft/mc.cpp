#include "mc.hpp"

MC::MC()
{
    window = new Window(800, 600);
}

MC::~MC()
{
    delete window;
}

void MC::Run()
{
    window->Show();

    bool running = true;
    while (running) {
        Update();
        Render();

        if(window->IsCloseRequested()) {
            running = false;
        }
    }
}

void MC::Render()
{

}

void MC::Update()
{
    window->Update();
}
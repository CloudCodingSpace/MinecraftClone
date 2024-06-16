#include "mc.hpp"

MC::MC()
{
    window = new Window(800, 600);
    renderer = new Renderer();
}

MC::~MC()
{
    delete renderer;
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
    renderer->Render(window->GetWidth(), window->GetHeight());
}

void MC::Update()
{
    renderer->Update();
    window->Update();
}
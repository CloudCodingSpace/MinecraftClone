#include "renderer.hpp"

Renderer::Renderer()
{
    shader = new Shader("shaders/default.vert", "shaders/default.frag");
}

Renderer::~Renderer()
{
    delete shader;
}

void Renderer::Render(int width, int height)
{
    
}

void Renderer::Update()
{

}
#include "renderer.hpp"

Renderer::Renderer()
{
    shader = new Shader("shaders/default.vert", "shaders/default.frag");

    std::vector<Vertex> vertices = {
        {{ -0.5f, -0.5f, 0.0f }, { 0.0f, 0.0f }}, 
        {{  0.5f, -0.5f, 0.0f }, { 1.0f, 0.0f }},
        {{  0.0f,  0.0f, 0.0f }, { 0.5f, 1.0f }}
    };

    std::vector<unsigned int> indices = {
        0, 1, 2
    };

    Mesh mesh(vertices, indices);
    Texture texture("assets/textures/test.jpg");
    texturedmesh = new TexturedMesh(mesh, texture);
}

Renderer::~Renderer()
{
    delete texturedmesh;
    delete shader;
}

void Renderer::Render(int width, int height)
{
    shader->Bind();
    texturedmesh->Render(shader);
    shader->Unbind();
}

void Renderer::Update()
{

}
#pragma once

#include <glad/glad.h>

#include "shader/shader.hpp"
#include "mesh/texturedmesh.hpp"

class Renderer
{
public:
    Renderer();
    ~Renderer();

    void Render(int width, int height);
    void Update();
private:
    Shader* shader;
    TexturedMesh* texturedmesh;
};
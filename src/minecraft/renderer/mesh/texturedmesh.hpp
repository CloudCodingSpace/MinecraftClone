#pragma once

#include "mesh.hpp"
#include "../textures/texture.hpp"
#include "../shader/shader.hpp"

class TexturedMesh
{
public:
    TexturedMesh(Mesh& mesh, Texture& texture);
    ~TexturedMesh();

    void Render(Shader* shader);
private:
    Mesh* mesh;
    Texture* texture;
};
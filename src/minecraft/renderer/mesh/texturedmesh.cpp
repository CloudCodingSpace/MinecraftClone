#include "texturedmesh.hpp"

TexturedMesh::TexturedMesh(Mesh& mesh, Texture& texture)
{
    this->mesh = &mesh;
    this->texture = &texture;
}

TexturedMesh::~TexturedMesh()
{
    delete texture;
    delete mesh;
}

void TexturedMesh::Render(Shader* shader)
{
    shader->PutTex("tex", 0);
    texture->Bind();
    texture->Activate(0);
    mesh->Render();
    texture->Unbind();
}
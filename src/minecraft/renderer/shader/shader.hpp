#pragma once

#include <stdexcept>
#include <fstream>
#include <iostream>
#include <string>

#include <glad/glad.h>

class Shader
{
public:
    Shader(const std::string& vertPath, const std::string& fragPath);
    ~Shader();

    void Bind();
    void PutTex(const std::string& name, int slot);
    void Unbind();
private:
    unsigned int ID;

    std::string ReadShaderFile(const std::string& path);
};
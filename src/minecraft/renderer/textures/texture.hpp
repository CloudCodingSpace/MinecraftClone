#pragma once

#include <glad/glad.h>
#include <stb/stb_image.h>

#include <stdexcept>

class Texture
{
public:
    Texture(const std::string& path);
    ~Texture();

    void Activate(int texNum);
    void Bind();
    void Unbind();

    int GetWidth() { return width; };
    int GetHeight() { return height; };
    int GetChannels() { return channels; };
private:
    unsigned int ID;
    int width, height, channels;
};
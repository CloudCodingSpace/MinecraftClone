#version 330 core

out vec4 FragColor; 
in vec2 coord;

uniform sampler2D tex;

void main()
{
    FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
}
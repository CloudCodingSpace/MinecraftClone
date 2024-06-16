#include "shader.hpp"

Shader::Shader(const std::string &vertPath, const std::string &fragPath)
{
    std::string vertSrc = ReadShaderFile(vertPath);
    std::string fragSrc = ReadShaderFile(fragPath);
    const char* vertSrcp = vertSrc.c_str();
    const char* fragSrcp = fragSrc.c_str();

    int success;
    char log[512];

    unsigned int vertShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertShader, 1, &vertSrcp, NULL);
    glCompileShader(vertShader);
    glGetShaderiv(vertShader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(vertShader, 512, NULL, log);
        std::cerr << "ERROR in VERTEX shader :- " << log << std::endl;
    }

    unsigned int fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShader, 1, &fragSrcp, NULL);
    glCompileShader(fragShader);
    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(fragShader, 512, NULL, log);
        std::cerr << "ERROR in FRAGMENT shader :- " << log << std::endl;
    }

    ID = glCreateProgram();
    glAttachShader(ID, vertShader);
    glAttachShader(ID, fragShader);
    glLinkProgram(ID);

    glDeleteShader(vertShader);
    glDeleteShader(fragShader);
}

Shader::~Shader()
{
    glDeleteProgram(ID);
}

void Shader::Bind()
{
    glUseProgram(ID);
}

void Shader::Unbind()
{
    glUseProgram(0);
}

std::string Shader::ReadShaderFile(const std::string &path)
{
    std::ifstream file(path);

    if(file.is_open()) {
        std::string content, line;
        while(getline(file, line)) {
            content += line + "\n";
            line = "";
        }

        file.close();
        return content;
    } else {
        throw std::runtime_error("Failed to open file for reading!");
    }
}
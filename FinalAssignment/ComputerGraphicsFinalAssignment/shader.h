#pragma once
#include <glm/glm.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

class Shader
{
public:
    unsigned int ID;
    Shader() = default;
    Shader(const char* vertexPath, const char* fragmentPath);
    void use();
    unsigned int getAttribLocation(const std::string&);
    void setMat4(const std::string&, const glm::mat4&);
    void setVec3(const std::string&, const glm::vec3&);
    void setFloat(const std::string&, float);
    void setTexture(const std::string&, const std::string&);
    void setNoTexture(const std::string&);



private:

    void checkCompileErrors(GLuint shader, std::string type);
};


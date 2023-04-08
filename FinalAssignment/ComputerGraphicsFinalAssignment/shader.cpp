#include "Shader.h"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
    /* Defining the strings and stream variables */
    std::string vSource;
    std::string fSource;
    std::ifstream VSS; // Vertex Shader Stream
    std::ifstream FSS; // Fragment Shader Stream

    VSS.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    FSS.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        /* Reading the shaderfiles and stream to string variables*/

        VSS.open(vertexPath);
        FSS.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;

        vShaderStream << VSS.rdbuf();
        fShaderStream << FSS.rdbuf();

        VSS.close();
        FSS.close();

        vSource = vShaderStream.str();
        fSource = fShaderStream.str();
    }
    catch (std::ifstream::failure& e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ: " << e.what() << std::endl;
    }
    const char* vCode = vSource.c_str();
    const char* fCode = fSource.c_str();

    unsigned int vertex, fragment;
    
    /* Create Vertex Shader*/
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vCode, NULL);
    glCompileShader(vertex);
    checkCompileErrors(vertex, "VERTEX");

    /* Create Fragment Shader*/
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fCode, NULL);
    glCompileShader(fragment);
    checkCompileErrors(fragment, "FRAGMENT");

    /* Create Program to link the shaders*/
    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    checkCompileErrors(ID, "PROGRAM");

    /* Delete the shaders */
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::use()
{
    glUseProgram(ID);
}
unsigned int Shader::getAttribLocation(const std::string& name)
{
    return glGetAttribLocation(ID, name.c_str());
}
void Shader::setMat4(const std::string& name, const glm::mat4& value)
{
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}
void Shader::setVec3(const std::string& name, const glm::vec3& value)
{
    glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, glm::value_ptr(value));
}
void Shader::setFloat(const std::string& name, float value)
{
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}
void Shader::setInt(const std::string& name, int value)
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}
void Shader::setTexture(const std::string& name)
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), 0);
}
void Shader::setBool(const std::string& bool_name, bool value)
{
    glUniform1i(glGetUniformLocation(ID, bool_name.c_str()), value);
}
void Shader::checkCompileErrors(GLuint programID, std::string type)
{
    GLint success;
    GLchar infoLog[1024];
    if (type != "PROGRAM")
    {
        glGetShaderiv(programID, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(programID, 1024, NULL, infoLog);
            std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
    else
    {
        glGetProgramiv(programID, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(programID, 1024, NULL, infoLog);
            std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
}


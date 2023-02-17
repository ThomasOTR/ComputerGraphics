#pragma once
#include <glm/glm.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

/// <summary>
/// Class to store and set everything related to Shaders
/// </summary>
class Shader
{
public:
    Shader() = default;
    Shader(const char*, const char*);

   /* ID created by glCreateProgram() to get the right Program for your shaders. */
    unsigned int ID;

    /// <summary>
    /// A method to trigger glUseProgram() with the stored ID 
    /// </summary>
    void use();

    /// <summary>
    /// A method to get the location of input of shader files.
    /// </summary>
    /// <param name="">name of the input</param>
    /// <returns></returns>
    unsigned int getAttribLocation(const std::string&);

    /// <summary>
    /// Method to set a glm::mat4
    /// </summary>
    /// <param name="">name of the input </param>
    /// <param name="">mat4 that needs to be stored</param>
    void setMat4(const std::string&, const glm::mat4&);

    /// <summary>
    /// Method to set a glm::mat4
    /// </summary>
    /// <param name="">name of the input </param>
    /// <param name="">vec3 that needs to be stored</param>
    void setVec3(const std::string&, const glm::vec3&);

    /// <summary>
    /// Method to set a glm::mat4
    /// </summary>
    /// <param name="">name of the input </param>
    /// <param name="">float that needs to be stored</param>
    void setFloat(const std::string&, float);

    void setInt(const std::string&, int);

    /// <summary>
    /// Method to set a Texture
    /// </summary>
    /// <param name="">name of the input </param>
    /// <param name="">name of boolean</param>
    void setTexture(const std::string&, const std::string&);

    /// <summary>
    /// Method to set boolean related to textures
    /// </summary>
    /// <param name="">name of boolean</param>
    void setNoTexture(const std::string&);



private:

    /// <summary>
    /// Method to check the shader on any compile errors
    /// </summary>
    /// <param name="shader"></param>
    /// <param name="type"></param>
    void checkCompileErrors(GLuint shader, std::string type);
};


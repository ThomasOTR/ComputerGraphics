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

    /// <summary>
    /// Constructor to set shader with paths for the fragment and vertex shaders
    /// </summary>
    /// <param name="vertexPath">: Path of the vertex shader</param>
    /// <param name="fragmentPath">: Path of the fragment shader</param>
    Shader(const char* vertexPath, const char* fragmentPath);

   /* ID created by glCreateProgram() to get the right Program for your shaders. */
    unsigned int ID;

    /// <summary>
    /// A method to trigger glUseProgram() with the stored ID.
    /// </summary>
    void use();

    /// <summary>
    /// A method to get the location of input of shader files.
    /// </summary>
    /// <param name="name">: Name of the input where you need the location of.</param>
    /// <returns></returns>
    unsigned int getAttribLocation(const std::string& name );

    /// <summary>
    /// Method to set a glm::mat4.
    /// </summary>
    /// <param name="name">: name of the input </param>
    /// <param name="value">: value to be set</param>
    void setMat4(const std::string& name, const glm::mat4& value);

    /// <summary>
    /// Method to set a glm::vec3.
    /// </summary>
    /// <param name="name">: name of the input </param>
    /// <param name="value">: value to be set</param>
    void setVec3(const std::string& name, const glm::vec3& value);

    /// <summary>
    /// Method to set a float.
    /// </summary>
    /// <param name="name">: name of the input </param>
    /// <param name="value">: value to be set</param>
    void setFloat(const std::string& name, float value);

    /// <summary>
    /// Method to set a int.
    /// </summary>
    /// <param name="name">: name of the input </param>
    /// <param name="value">: value to be set</param>
    void setInt(const std::string& name, int value);

    /// <summary>
    /// Method to set a Texture
    /// </summary>
    /// <param name="name">: name of the input </param>
    void setTexture(const std::string& name);

    /// <summary>
    /// Method to set boolean.
    /// </summary>
    /// <param name="">name of boolean</param>
    void setBool(const std::string& bool_name, bool value);



private:

    /// <summary>
    /// Method to check the shader on any compile errors
    /// </summary>
    /// <param name="programID">: ID of the program that is checked on compile errors</param>
    /// <param name="type">: Type of error that is checked</param>
    void checkCompileErrors(GLuint programID, std::string type);
};


#pragma once
#include "Entity.h"

/// <summary>
/// Class to create a Skybox
/// </summary>
class Skybox :
    public Entity
{
private:
    /// <summary>
    /// A vector with all the vertices needed for the skybox
    /// </summary>
    std::vector<GLfloat> skyboxVertices =
    {
        //   Coordinates
        -1.0f, -1.0f,  1.0f,//        7--------6
         1.0f, -1.0f,  1.0f,//       /|       /|
         1.0f, -1.0f, -1.0f,//      4--------5 |
        -1.0f, -1.0f, -1.0f,//      | |      | |
        -1.0f,  1.0f,  1.0f,//      | 3------|-2
         1.0f,  1.0f,  1.0f,//      |/       |/
         1.0f,  1.0f, -1.0f,//      0--------1
        -1.0f,  1.0f, -1.0f
    };

    std::vector<GLushort> skyboxIndices =
    {
        // Right
        1, 2, 6,
        6, 5, 1,
        // Left
        0, 4, 7,
        7, 3, 0,
        // Top
        4, 5, 6,
        6, 7, 4,
        // Bottom
        0, 3, 2,
        2, 1, 0,
        // Back
        0, 1, 5,
        5, 4, 0,
        // Front
        3, 7, 6,
        6, 2, 3
    };
    
    /// <summary>
    /// A vector with image_paths of each side of the skybox
    /// </summary>
    std::vector<std::string> sides
    {
        "Textures/skybox/right.jpg",
        "Textures/skybox/left.jpg",
        "Textures/skybox/top.jpg",
        "Textures/skybox/bottom.jpg",
        "Textures/skybox/front.jpg",
        "Textures/skybox/back.jpg"
    };
public:
    Skybox();

    /// <summary>
    /// Method to buffer the object
    /// </summary>
    /// <param name="">view</param>
    /// <param name="">projection</param>
    virtual void Buffer(glm::mat4, glm::mat4);

    /// <summary>
    /// Method to render the object
    /// </summary>
    /// <param name="">view</param>
    /// <param name="">projection</param>
    virtual void Render(glm::mat4, glm::mat4);

    GLfloat vertices[120] = {};
    unsigned int indices[72] = {};
};


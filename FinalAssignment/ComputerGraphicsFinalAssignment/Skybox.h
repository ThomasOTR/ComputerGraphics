#pragma once
#include "Entity.h"

/// <summary>
/// Class to create a Skybox
/// </summary>
class Skybox :
    public Entity
{
private:
    /* A vector with all the vertices needed for the skybox */
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

    /* A vector with all the indices needed for the skybox */
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
    
    /* A vector with image_paths of each side of the skybox */
    std::vector<std::string> sides
    {
        "Textures/skybox2/right.jpg",
        "Textures/skybox2/left.jpg",
        "Textures/skybox2/up.jpg",
        "Textures/skybox2/down.jpg",
        "Textures/skybox2/front.jpg",
        "Textures/skybox2/back.jpg",
    };
public:
    Skybox();

    /// <summary>
    /// Method to buffer the object
    /// </summary>
    /// <param name="view">: Calculated View Matrix</param>
    /// <param name="projection">: Calculated Projection Matrix</param>
    virtual void Buffer(glm::mat4, glm::mat4);

    /// <summary>
    /// Method to render the object
    /// </summary>
    /// <param name="view">: Calculated View Matrix</param>
    /// <param name="projection">: Calculated Projection Matrix</param>
    virtual void Render(glm::mat4, glm::mat4);

    GLfloat vertices[120] = {};
    unsigned int indices[72] = {};
};


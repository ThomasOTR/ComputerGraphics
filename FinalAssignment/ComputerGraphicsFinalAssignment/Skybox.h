#pragma once
#include "Entity.h"

/// <summary>
/// Class to create a Skybox
/// To create this Skybox, i have used information and some code from https://learnopengl.com/Advanced-OpenGL/Cubemaps.
/// </summary>
class Skybox :
    public Entity
{
private:
    /* A vector with all the vertices needed for the skybox */
    std::vector<GLfloat> SkyboxVertices =
    {
        -1.0f, -1.0f,  1.0f,
         1.0f, -1.0f,  1.0f,
         1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f
    };

    /* A vector with all the indices needed for the skybox */
    std::vector<GLushort> SkyboxIndices =
    {
        1, 2, 6,
        6, 5, 1,
        0, 4, 7,
        7, 3, 0,
        4, 5, 6,
        6, 7, 4,
        0, 3, 2,
        2, 1, 0,
        0, 1, 5,
        5, 4, 0,
        3, 7, 6,
        6, 2, 3
    };
    
    /* A vector with image_paths of each side of the skybox */
    std::vector<std::string> ImagesOfEachSide
    {
        "Textures/skybox/right.jpg",
        "Textures/skybox/left.jpg",
        "Textures/skybox/up.jpg",
        "Textures/skybox/down.jpg",
        "Textures/skybox/front.jpg",
        "Textures/skybox/back.jpg",
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


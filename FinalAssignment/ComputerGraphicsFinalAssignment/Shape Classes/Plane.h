#pragma once
#include "../Shape.h"

/// <summary>
/// A class to create a plane shape and render it
/// </summary>
class Plane :
    public Shape
{
public:
    std::vector<GLfloat> PlaneVertices = {
        -1.0,  0.0, -1.0, // 0
         1.0,  0.0, -1.0, // 1
         1.0,  0.0,  1.0, // 2

         1.0,  0.0,  1.0, // 2
        -1.0,  0.0,  1.0, // 3
        -1.0,  0.0, -1.0, // 0
    };

    std::vector<GLfloat> PlaneColors = {

    };

    std::vector<GLushort> Plane_Elements = {
        0,1,2,
        0,2,3
    };

    std::vector<GLfloat> Plane_Uvs = {
        0.0f, 0.0f, // bottom left
        1.0f, 0.0f, // bottom right
        1.0f, 1.0f, // top right

        1.0f, 1.0f,
        0.0f, 1.0f,
        0.0f, 0.0f,
    };
    Plane() = default;
    Plane(glm::vec3, float, float, float);


    // Inherited via Shape
    virtual void setData() override;

    virtual void setAnimations() override;

};


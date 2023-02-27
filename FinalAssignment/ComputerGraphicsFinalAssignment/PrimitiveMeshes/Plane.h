#pragma once
#include "../PrimitiveMesh.h"

/// <summary>
/// A class to create a plane shape and render it
/// </summary>
class Plane :
    public PrimitiveMesh
{
public:

    /* Vertices needed to create a Plane*/
    std::vector<GLfloat> PlaneVertices = {
    -1.0, 0.0, -1.0, // 0
     1.0, 0.0, -1.0, // 1
    -1.0, 0.0,  1.0, // 2
     1.0, 0.0,  1.0  // 3
    };

    /* Elements needed to create a Plane*/
    std::vector<GLushort> Plane_Elements = {
        0,1,2,
        2,3,1
    };
    Plane() = default;
    Plane(glm::vec3 color);


    // Inherited via Shape
    virtual void setData() override;

};


#pragma once
#include "../PrimitiveMesh.h"

/// <summary>
/// A class to create a plane shape and render it
/// </summary>
class Plane :
    public PrimitiveMesh
{
public:
    std::vector<GLfloat> PlaneVertices = {
    -1.0, 0.0, -1.0, // 0
     1.0, 0.0, -1.0, // 1
    -1.0, 0.0,  1.0, // 2
     1.0, 0.0,  1.0  // 3
    };
    std::vector<GLushort> Plane_Elements = {
        0,1,2,
        2,3,1
    };
    Plane() = default;
    Plane(glm::vec3, glm::vec3);


    // Inherited via Shape
    virtual void setData() override;

};


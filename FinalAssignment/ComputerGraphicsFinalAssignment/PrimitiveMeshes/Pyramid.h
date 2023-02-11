#pragma once
#include "../PrimitiveMesh.h"
#include <vector>

/// <summary>
/// A class to create a Pyramid shape and render it.
/// </summary>
class Pyramid : public PrimitiveMesh
{
private:
    std::vector<GLfloat> Pyramid_Vertices = { // X, Y, Z.
           // front
           -1.0, -1.0,  1.0, // bottom left
            1.0, -1.0,  1.0, // bottom right
            0.0,  1.0,  0.0, // top middle
           // back
           -1.0, -1.0, -1.0, // bottom left
            1.0, -1.0, -1.0, // bottom right
    };
    std::vector<GLushort> Pyramid_Elements = {
       0,1,2, // front
       1,4,2, // right side
       4,3,2, // back
       3,0,2, // left side
       3,4,1, 3,1,0 // bottom
    };
public:
    Pyramid();
    Pyramid(glm::vec3, float, float, float, ShadingType);

	// Inherited via Shape
	virtual void setData() override;
    virtual void setAnimations() override;

};


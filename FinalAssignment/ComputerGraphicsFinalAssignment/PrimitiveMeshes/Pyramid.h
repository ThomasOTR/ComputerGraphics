#pragma once
#include "../PrimitiveMesh.h"
#include <vector>

/// <summary>
/// A class to create a Pyramid shape and render it.
/// </summary>
class Pyramid : public PrimitiveMesh
{
private:
    
    /* Vertices needed for the Pyramid */
    std::vector<GLfloat> Pyramid_Vertices = {
           -1.0, -1.0,  1.0, 
            1.0, -1.0,  1.0, 
            0.0,  1.0,  0.0,
           -1.0, -1.0, -1.0, 
            1.0, -1.0, -1.0,
    };

    /* Elements needed for the Pyramid */
    std::vector<GLushort> Pyramid_Elements = {
       0,1,2,
       1,4,2, 
       4,3,2, 
       3,0,2, 
       3,4,1,
       3,1,0 
    };
public:
    Pyramid() = default;
    Pyramid(glm::vec3 color);

	// Inherited via Shape
	virtual void setData() override;
};


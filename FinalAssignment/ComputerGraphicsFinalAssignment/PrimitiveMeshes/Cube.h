#pragma once
#include "../PrimitiveMesh.h"

/// <summary>
/// A class to create a Cube Shape and render it on the screen.
/// </summary>
class Cube :
	public PrimitiveMesh
{
private:
    /* The vertices that are needed to create a cube*/
	std::vector<GLfloat> CubeVertices = {
        // front
        -1.0, -1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, 1.0, 1.0,
            -1.0, 1.0, 1.0,
            // top
            -1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, -1.0,
            -1.0, 1.0, -1.0,
            // back
            1.0, -1.0, -1.0,
            -1.0, -1.0, -1.0,
            -1.0, 1.0, -1.0,
            1.0, 1.0, -1.0,
            // bottom
            -1.0, -1.0, -1.0,
            1.0, -1.0, -1.0,
            1.0, -1.0, 1.0,
            -1.0, -1.0, 1.0,
            // left
            -1.0, -1.0, -1.0,
            -1.0, -1.0, 1.0,
            -1.0, 1.0, 1.0,
            -1.0, 1.0, -1.0,
            // right
            1.0, -1.0, 1.0,
            1.0, -1.0, -1.0,
            1.0, 1.0, -1.0,
            1.0, 1.0, 1.0,
    };
    
    /* The elements that are needed to create a cube*/
    std::vector<GLushort> CubeElements = {
        // front
         0,  1,  2,
         2,  3,  0,
         // top
          4,  5,  6,
          6,  7,  4,
          // back
           8,  9, 10,
          10, 11,  8,
          // bottom
          12, 13, 14,
          14, 15, 12,
          // left
          16, 17, 18,
          18, 19, 16,
          // right
          20, 21, 22,
          22, 23, 20,
    };
public:
    Cube() = default;
	Cube(glm::vec3);
	// Inherited via Shape
	virtual void setData();
};
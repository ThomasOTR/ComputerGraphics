#pragma once
#include "../PrimitiveMesh.h"
#include <vector>

class TriangularPrism :
    public PrimitiveMesh
{
    private:

        /* Vertices needed to create the Triangular Prism */
        std::vector<GLfloat> Prism_Vertices = {
            0.0f, 0.0f, 0.0f,
            1.0f, 1.0f, 1.0f,
            0.0f, 1.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 1.0f, 1.0f,
            1.0f, 1.0f, 0.0f,
            1.0f, 0.0f, 1.0f,

        };

        /* Elements needed to create the Triangular Prism */
        std::vector<GLushort> Prism_Elements = {
            0,4,2,
            2,3,0,
            0,4,3,
            3,2,6,
            6,3,7,
            7,3,4,
            4,6,7,
            4,6,2

        };    
public:
        TriangularPrism() = default;
        TriangularPrism(glm::vec3 color);

        // Inherited via Shape
        virtual void setData() override;

};


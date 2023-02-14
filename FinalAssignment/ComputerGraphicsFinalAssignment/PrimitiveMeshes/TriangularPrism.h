#pragma once
#include "../PrimitiveMesh.h"
#include <vector>

class TriangularPrism :
    public PrimitiveMesh
{
    private:
        std::vector<GLfloat> Prism_Vertices = { // X, Y, Z.
            //back

            0.0f, 0.0f, 0.0f,
            1.0f, 1.0f, 1.0f,

            0.0f, 1.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f,

            0.0f, 1.0f, 1.0f,
            1.0f, 1.0f, 0.0f,
            1.0f, 0.0f, 1.0f,

        };
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
        TriangularPrism(glm::vec3 color, ShadingType);

        // Inherited via Shape
        virtual void setData() override;

};


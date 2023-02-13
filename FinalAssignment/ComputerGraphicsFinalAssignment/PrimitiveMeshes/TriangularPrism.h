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
            
            
           
            //6,3,4,
            
            
            //2,3
            //0,2,6,
            //4,3,6
            

            
            //7,4,5,
            //5,4,2,
            //3,7,4,
            ////back            
            //6,2,0,
            //3,0,6,
            //6,2,4
            //
            


            //6,2,4,
            ////3,0,2,
            //////3,7,1

            //0,1,
            //1,2,
            //2,3,
            //3,4,
            //4,5,
            //5,6,
            //6,6,
            

        };    
public:
        TriangularPrism() = default;
        TriangularPrism(glm::vec3, glm::vec3, ShadingType);

        // Inherited via Shape
        virtual void setData() override;
        virtual void setAnimations() override;

};


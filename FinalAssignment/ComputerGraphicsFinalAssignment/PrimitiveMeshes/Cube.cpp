#include "Cube.h"
#include "../Transformations.h"


Cube::Cube(glm::vec3 inputColor)
{
	color = inputColor;
	setData();

}
void Cube::setData()
{
	std::copy(CubeVertices.begin(), CubeVertices.end(), vertices);
	std::copy(CubeElements.begin(), CubeElements.end(), indices);
}
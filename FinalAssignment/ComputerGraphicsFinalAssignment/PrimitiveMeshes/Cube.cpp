#include "Cube.h"
#include "../Transformations.h"


Cube::Cube(glm::vec3 inputColor)
{
	color = inputColor;
	setData();

}
void Cube::setData()
{
	std::copy(Cube_Vertices.begin(), Cube_Vertices.end(), vertices);
	std::copy(Cube_Elements.begin(), Cube_Elements.end(), indices);
}
#include "Cube.h"
#include "../Transformations.h"


Cube::Cube(glm::vec3 inputColor, ShadingType st)
{
	color = inputColor;
	shading_type = st;
	material = defaultMaterial;
	setData();

}
void Cube::setData()
{
	std::copy(Cube_Vertices.begin(), Cube_Vertices.end(), vertices);
	std::copy(Cube_Texcoords.begin(), Cube_Texcoords.end(), uvs);
	std::copy(Cube_Elements.begin(), Cube_Elements.end(), indices);
}
#include "Cube.h"
#include "../Transformations.h"

Cube::Cube()
{
	setData();
	setAnimations();
	CalculateNormals(Cube_Vertices);
	material = defaultMaterial;

}


Cube::Cube(glm::vec3 inputColor, float posX, float posY, float posZ, ShadingType st) : Cube()
{
	color = inputColor;
	shading_type = st;
	SetPosition(posX, posY, posZ);

}
void Cube::setData()
{
	std::copy(Cube_Vertices.begin(), Cube_Vertices.end(), vertices);
	std::copy(Cube_Texcoords.begin(), Cube_Texcoords.end(), uvs);
	std::copy(Cube_Elements.begin(), Cube_Elements.end(), indices);
}

void Cube::setAnimations()
{
}
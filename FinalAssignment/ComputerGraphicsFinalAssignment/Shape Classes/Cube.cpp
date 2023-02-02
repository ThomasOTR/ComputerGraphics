#include "Cube.h"
#include "../Transformations.h"

Cube::Cube()
{
	setData();
	setAnimations();
	CalculateNormals(Cube_Vertices);
	material = defaultMaterial;

}

Cube::Cube(std::string texture_uri, float posX, float posY, float posZ) : Cube()
{
	shading_type = ShadingType::BasicTexture;
	texture_path = texture_uri;
	SetPosition(posX, posY, posZ);
	material = defaultMaterial;

}

Cube::Cube(glm::vec3 inputColor, float posX, float posY, float posZ) : Cube()
{
	color = inputColor;
	shading_type = ShadingType::Basic;
	SetPosition(posX, posY, posZ);
	material = defaultMaterial;

}
void Cube::setData()
{
	std::copy(Cube_Vertices.begin(), Cube_Vertices.end(), vertices);
	std::copy(Cube_uvs.begin(), Cube_uvs.end(), uvs);
	std::copy(Cube_Elements.begin(), Cube_Elements.end(), indices);
}

void Cube::setAnimations()
{
}
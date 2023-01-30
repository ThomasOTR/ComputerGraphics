#include "Plane.h"

Plane::Plane(glm::vec3 color, float posX, float posY, float posZ)
{
	this->color = color;
	SetPosition(posX, posY, posZ);
	shading_type = ShadingType::Basic;

}

void Plane::setData()
{
	std::copy(PlaneVertices.begin(), PlaneVertices.end(), vertices);
	std::copy(Plane_Uvs.begin(), Plane_Uvs.end(), uvs);
	std::copy(Plane_Elements.begin(), Plane_Elements.end(), indices);
}

void Plane::setAnimations()
{

}

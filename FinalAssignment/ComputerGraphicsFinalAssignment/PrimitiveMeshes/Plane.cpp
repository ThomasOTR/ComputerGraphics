#include "Plane.h"

Plane::Plane(glm::vec3 color, glm::vec3 position)
{
	this->color = color;
	SetPosition(position);
	shading_type = ShadingType::Basic;
	material = defaultMaterial;
	setData();
}

void Plane::setData()
{
	std::copy(PlaneVertices.begin(), PlaneVertices.end(), vertices);
	std::copy(Plane_Elements.begin(), Plane_Elements.end(), indices);
}

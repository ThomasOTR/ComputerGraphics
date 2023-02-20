#include "Plane.h"

Plane::Plane(glm::vec3 color, ShadingType st)
{
	this->color = color;
	shading_type = st;
	setData();
}

void Plane::setData()
{
	std::copy(PlaneVertices.begin(), PlaneVertices.end(), vertices);
	std::copy(Plane_Elements.begin(), Plane_Elements.end(), indices);
}

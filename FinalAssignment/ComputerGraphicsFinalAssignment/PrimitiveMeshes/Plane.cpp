#include "Plane.h"

Plane::Plane(glm::vec3 color)
{
	this->color = color;
	setData();
}

void Plane::setData()
{
	std::copy(PlaneVertices.begin(), PlaneVertices.end(), vertices);
	std::copy(PlaneElements.begin(), PlaneElements.end(), indices);
}

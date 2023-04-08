#include "TriangularPrism.h"

TriangularPrism::TriangularPrism(glm::vec3 color)
{
	this->color = color;
	setData();
}

void TriangularPrism::setData()
{
	std::copy(PrismVertices.begin(), PrismVertices.end(), vertices);
	std::copy(PrismElements.begin(), PrismElements.end(), indices);
}

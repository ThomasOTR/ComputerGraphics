#include "TriangularPrism.h"

TriangularPrism::TriangularPrism(glm::vec3 color, ShadingType st)
{
	this->color = color;
	shading_type = ShadingType::Basic;
	setData();
}

void TriangularPrism::setData()
{
	std::copy(Prism_Vertices.begin(), Prism_Vertices.end(), vertices);
	std::copy(Prism_Elements.begin(), Prism_Elements.end(), indices);
}

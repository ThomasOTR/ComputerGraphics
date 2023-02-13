#include "TriangularPrism.h"

TriangularPrism::TriangularPrism(glm::vec3 color, glm::vec3 position, ShadingType st)
{
	this->color = color;
	SetPosition(position);
	shading_type = ShadingType::Basic;
	material = defaultMaterial;
	setData();
}

void TriangularPrism::setData()
{
	std::copy(Prism_Vertices.begin(), Prism_Vertices.end(), vertices);
	std::copy(Prism_Elements.begin(), Prism_Elements.end(), indices);
}

void TriangularPrism::setAnimations()
{
}

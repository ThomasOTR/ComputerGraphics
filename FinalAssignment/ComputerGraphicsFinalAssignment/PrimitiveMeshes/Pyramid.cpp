#include "Pyramid.h"

Pyramid::Pyramid(glm::vec3 inputColor)
{
	color = inputColor;
	setData();
}
void Pyramid::setData()
{
	std::copy(PyramidVertices.begin(), PyramidVertices.end(), vertices);
	std::copy(PyramidElements.begin(), PyramidElements.end(), indices);
}

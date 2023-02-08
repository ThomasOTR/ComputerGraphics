#include "Pyramid.h"
#include "../Transformations.h"
#include "../Animations/Move/TranslateX_Animation.h"


Pyramid::Pyramid()
{
	setData();
	setAnimations();
	material = defaultMaterial;

}

Pyramid::Pyramid(glm::vec3 inputColor, float posX, float posY, float posZ, ShadingType st) : Pyramid()
{
	color = inputColor;
	shading_type = st;

	SetPosition(posX, posY, posZ);
}
void Pyramid::setData()
{
	std::copy(Pyramid_Vertices.begin(), Pyramid_Vertices.end(), vertices);
	std::copy(Pyramid_Elements.begin(), Pyramid_Elements.end(), indices);
}

void Pyramid::setAnimations()
{
	animations.push_back(new TranslateX_Animation(-0.2f));
}

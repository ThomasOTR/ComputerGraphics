#include "Pyramid.h"
#include "../Transformations.h"
#include "../Animations/Move/TranslateX_Animation.h"
#include "../Animations/Move/TranslateY_Animation.h"
#include "../Animations/Move/TranslateZ_Animation.h"
#include "../Animations/Scale/ScalingAnimation.h"
#include "../Animations/Rotate/RotationAnimation.h"

Pyramid::Pyramid(glm::vec3 inputColor, ShadingType st) : Pyramid()
{
	color = inputColor;
	shading_type = st;
	material = defaultMaterial;
	setData();
}
void Pyramid::setData()
{
	std::copy(Pyramid_Vertices.begin(), Pyramid_Vertices.end(), vertices);
	std::copy(Pyramid_Elements.begin(), Pyramid_Elements.end(), indices);
}

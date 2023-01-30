#include "Pyramid.h"
#include "../Transformations.h"
#include "../Animations/LeftRightAnimation.h"



Pyramid::Pyramid()
{
	setData();
	setAnimations();
}

Pyramid::Pyramid(std::string texture_uri, float posX, float posY, float posZ) : Pyramid()
{
	shading_type = ShadingType::BasicTexture;
	texture_path = texture_uri;

	SetPosition(posX, posY, posZ);
	
	setData();
	setAnimations();
}
Pyramid::Pyramid(std::string texture_uri, float posX, float posY, float posZ,
										  float scaleX, float scaleY, float scaleZ) : Pyramid()
{
	texture_path = texture_uri;
	SetPosition(posX, posY, posZ);
	SetScale(scaleX, scaleY, scaleZ);
	setData();
	setAnimations();
}
Pyramid::Pyramid(std::string texture_uri, float posX, float posY, float posZ,
										  float scaleX, float scaleY, float scaleZ,
										  float angle, float rotX, float rotY, float rotZ) : Pyramid()
{
	texture_path = texture_uri;

	SetPosition(posX, posY, posZ);
	SetScale(scaleX, scaleY, scaleZ);
	SetRotation(rotX, rotY, rotZ, angle);

	setData();
	setAnimations();
}

void Pyramid::setData()
{
	std::copy(Pyramid_Vertices.begin(), Pyramid_Vertices.end(), vertices);
	std::copy(Pyramid_uvs.begin(), Pyramid_uvs.end(), uvs);
	std::copy(Pyramid_Elements.begin(), Pyramid_Elements.end(), indices);
}

void Pyramid::setAnimations()
{
	//animations.push_back(new LeftRightAnimation(5.0f));
}

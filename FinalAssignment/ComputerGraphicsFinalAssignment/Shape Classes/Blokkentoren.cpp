#include "Blokkentoren.h"
#include "Cube.h"
#include "Pyramid.h"
Blokkentoren::Blokkentoren(float positionX, float positionY, float positionZ)
{
	SetPosition(positionX, positionY, positionZ);
	Transform();
	AddComponents();
	material = defaultMaterial;
}

void Blokkentoren::AddComponents()
{
	glm::vec3 position = GetPosition();

	Cube* Onder = new Cube(glm::vec3(0.275, 0.204, 0.922), position.x, position.y, position.z);

	Cube* Midden = new Cube(glm::vec3(0.275, 0.204, 0.922), position.x, position.y, position.z);
	Midden->SetPosition(position.x, position.y + 2, position.z);

	Pyramid* Top = new Pyramid("Textures/uvtemplate.bmp", position.x, position.y, position.z);
	Top->SetPosition(position.x, position.y + 4, position.z);

	Parts.insert(Parts.end(), { Onder,Midden,Top });
}

void Blokkentoren::ResetComponents()
{
	Parts.clear();
	AddComponents();
}

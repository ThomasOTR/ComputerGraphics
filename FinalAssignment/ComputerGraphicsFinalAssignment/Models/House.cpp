#include "House.h"
#include "../PrimitiveMeshes/Pyramid.h"
#include "../PrimitiveMeshes/Cube.h"
House::House(float positionX, float positionY, float positionZ)
{
	SetPosition(positionX, positionY, positionZ);
	Transform();
	AddComponents();
	material = defaultMaterial;
}

void House::AddComponents()
{
	glm::vec3 position = GetPosition();

	Cube* Base = new Cube(glm::vec3(1., 1., 1.), position.x, position.y, position.z,ShadingType::Basic);
	//Base->SetScale(1.75, 1.75, 1.75);
	Pyramid* Top = new Pyramid(glm::vec3(0.173, 0., 0.5), position.x, position.y + 2.0f, position.z, ShadingType::Basic);

	Cube* chimney = new Cube(glm::vec3(0.173, 0., 0.3), position.x - 0.5f,position.y+2.2f,position.z,ShadingType::Basic);
	chimney->SetScale(0.15f, 0.5f, 0.15f);

	Parts.insert(Parts.end(), { Base,Top,chimney });
}

#include "House.h"
#include "../PrimitiveMeshes/Pyramid.h"
#include "../PrimitiveMeshes/Cube.h"
#include "../PrimitiveMeshes/Plane.h"
House::House(glm::vec3 position)
{
	SetPosition(position);
	Transform();
	AddComponents();
	material = defaultMaterial;
}

void House::AddComponents()
{
	glm::vec3 position = GetPosition();

	Cube* base = new Cube(glm::vec3(1., 1., 1.),ShadingType::Basic);
	base->SetPosition(position);
	//Base->SetScale(1.75, 1.75, 1.75);
	Pyramid* top = new Pyramid(glm::vec3(0.173, 0., 0.5), ShadingType::Basic);
	top->SetPosition(glm::vec3(position.x, position.y + 2.0f, position.z));

	Cube* chimney = new Cube(glm::vec3(0.173, 0., 0.3),ShadingType::Basic);
	chimney->SetPosition(glm::vec3(position.x - 0.5f, position.y + 2.2f, position.z));
	chimney->SetScale(glm::vec3(0.15f, 0.5f, 0.15f));

	Plane* door = new Plane(glm::vec3(0.588, 0.294, 0.),ShadingType::Basic);
	door->SetPosition(glm::vec3(position.x + 0.3, position.y - 0.4, position.z + 1.01f));
	door->SetRotation(glm::vec3(1, 0, 0),90.0f);
	door->SetScale(glm::vec3(0.3f, 0.6, 1));

	Parts.insert(Parts.end(), { base,top,chimney,door });
}

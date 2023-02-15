#include "House.h"
#include "../PrimitiveMeshes/Pyramid.h"
#include "../PrimitiveMeshes/Cube.h"
#include "../PrimitiveMeshes/Plane.h"
#include "../PrimitiveMeshes/TriangularPrism.h"
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

	bool selectHouseRandom = rand() & 1;

	if (selectHouseRandom)
	{
		Pyramid* top = new Pyramid(glm::vec3(0.173, 0., 0.5), ShadingType::Basic);
		top->SetPosition(glm::vec3(position.x, position.y + 2.0f, position.z));

		Parts.insert(Parts.end(), { top });
	}
	else
	{
		TriangularPrism* top1 = new TriangularPrism(glm::vec3(0.173, 0., 0.1), ShadingType::Basic);
		top1->SetPosition(glm::vec3(position.x + 1.1f, position.y + 1.0f, position.z));
		top1->SetScale(glm::vec3(2.2, 1.2, 1.2));
		top1->SetRotation(glm::vec3(0, 1, 0), 180);

		TriangularPrism* top2 = new TriangularPrism(glm::vec3(0.173, 0., 0.1), ShadingType::Basic);
		top2->SetPosition(glm::vec3(position.x - 1.1f, position.y + 1.0f, position.z));
		top2->SetScale(glm::vec3(2.2, 1.2, 1.2));

		Parts.insert(Parts.end(), { top1,top2 });
	}

	Cube* base = new Cube(glm::vec3(1., 1., 1.), ShadingType::Basic);
	base->SetPosition(position);

	Plane* door = new Plane(glm::vec3(0.588, 0.294, 0.), ShadingType::Basic);
	door->SetPosition(glm::vec3(position.x + 0.3, position.y - 0.4, position.z + 1.01f));
	door->SetRotation(glm::vec3(1, 0, 0), 90.0f);
	door->SetScale(glm::vec3(0.3f, 0.5, 1));

	Cube* chimney = new Cube(glm::vec3(0.173, 0., 0.3), ShadingType::Basic);
	chimney->SetPosition(glm::vec3(position.x - 0.5f, position.y + 2.2f, position.z));
	chimney->SetScale(glm::vec3(0.15f, 0.5f, 0.15f));

	Parts.insert(Parts.end(), { base,door,chimney });

}

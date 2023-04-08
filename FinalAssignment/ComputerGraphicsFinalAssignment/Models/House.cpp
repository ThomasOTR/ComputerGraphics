#include "House.h"
#include "../PrimitiveMeshes/Pyramid.h"
#include "../PrimitiveMeshes/Cube.h"
#include "../PrimitiveMeshes/Plane.h"
#include "../PrimitiveMeshes/TriangularPrism.h"

void House::AddComponents()
{
	glm::vec3 position = GetPosition();

	/* There will be randomly chosen which roof a house will have. */
	bool SelectRoof = rand() & 1;
	if (SelectRoof)
	{
		/* A Pyramid Roof*/
		Pyramid* top = new Pyramid(glm::vec3(0.588, 0.294, 0.));
		top->Move(glm::vec3(position.x, position.y + 2.0f, position.z));
		Parts.push_back(top);
	}
	else
	{
		/* A roof of 2 TriangularPrisms */
		TriangularPrism* top1 = new TriangularPrism(glm::vec3(0.588, 0.294, 0.));
		top1->Move(glm::vec3(position.x + 1.1f, position.y + 1.0f, position.z));
		top1->Scale(glm::vec3(2.2, 1.2, 1.2));
		top1->Rotate(glm::vec3(0, 1, 0), 180);

		TriangularPrism* top2 = new TriangularPrism(glm::vec3(0.588, 0.294, 0.));
		top2->Move(glm::vec3(position.x - 1.1f, position.y + 1.0f, position.z));
		top2->Scale(glm::vec3(2.2, 1.2, 1.2));

		Parts.insert(Parts.end(), { top1,top2 });
	}

	Cube* base = new Cube(glm::vec3(0.961, 0.961, 0.863));
	base->Move(position);

	Plane* door = new Plane(glm::vec3(0.588, 0.294, 0.));
	door->Move(glm::vec3(position.x + 0.3, position.y - 0.5 , position.z + 1.01 ));
	door->Rotate(glm::vec3(1, 0, 0), 90.0f);
	door->Scale(glm::vec3(0.3f, 0.2, 0.5));

	Cube* chimney = new Cube(glm::vec3(0.29, 0.157, 0.027));
	chimney->Move(glm::vec3(position.x - 0.5f, position.y + 2.2f, position.z));
	chimney->Scale(glm::vec3(0.15f, 0.5f, 0.15f));

	Parts.insert(Parts.end(), { base,door,chimney });

}

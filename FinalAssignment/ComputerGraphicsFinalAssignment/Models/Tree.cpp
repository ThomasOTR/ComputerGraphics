#include "Tree.h"
#include "../Object.h"
void Tree::AddComponents()
{
	glm::vec3 position = GetPosition();

	Object* trunk;
	Object* leaves;
	bool selectTreeType = rand() & 1;

	if (selectTreeType)
	{
		trunk = new Object("Objects/MadeInBlender/trunk1.obj", "Textures/tree_trunk.bmp");
		leaves = new Object("Objects/MadeInBlender/leaves1.obj", "Textures/leaves.bmp");
	}
	else
	{
		trunk = new Object("Objects/MadeInBlender/trunk1.obj", glm::vec3(0.588, 0.294, 0.));
		leaves = new Object("Objects/MadeInBlender/leaves1.obj", glm::vec3(0., 0.82, 0.));
	}
	trunk->Move(position);
	trunk->Scale(glm::vec3(1.5, 1.5, 1.5));

	leaves->Move(glm::vec3(position.x, position.y - 0.7 , position.z));
	leaves->Scale(glm::vec3(2,2,2));

	Parts.insert(Parts.end(), { trunk,leaves });
}

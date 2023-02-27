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
		trunk = new Object("trunk.obj", "tree_trunk.bmp",true);
		leaves = new Object("leaves.obj", "leaves.bmp",true);
	}
	else
	{
		trunk = new Object("trunk.obj", glm::vec3(0.588, 0.294, 0.),true);
		leaves = new Object("leaves.obj", glm::vec3(0., 0.82, 0.),true);
	}
	trunk->Move(position);
	trunk->Scale(glm::vec3(1.5, 1.5, 1.5));

	leaves->Move(glm::vec3(position.x, position.y - 0.7 , position.z));
	leaves->Scale(glm::vec3(2,2,2));

	Parts.insert(Parts.end(), { trunk,leaves });
}

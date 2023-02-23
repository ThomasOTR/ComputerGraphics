#include "Tree.h"
#include "../Object.h"

Tree::Tree()
{
	AddComponents();
}

void Tree::AddComponents()
{
	glm::vec3 position = GetPosition();

	Object* trunk = new Object("Objects/MadeInBlender/trunk1.obj", "Textures/tree_trunk.bmp");

	trunk->Move(position);
	trunk->Scale(glm::vec3(1.5, 1.5, 1.5));
	Object* leaves = new Object("Objects/MadeInBlender/leaves1.obj", "Textures/leaves.bmp");
	leaves->Move(glm::vec3(position.x, position.y - 0.7 , position.z));
	leaves->Scale(glm::vec3(2,2,2));

	Parts.insert(Parts.end(), { trunk,leaves });
}

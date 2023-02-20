#include "Tree.h"
#include "../Object.h"

Tree::Tree()
{
	AddComponents();
}

void Tree::AddComponents()
{
	glm::vec3 position = GetPosition();

	Object* trunk = new Object("Objects/MadeInBlender/trunk1.obj", glm::vec3(0.588, 0.294, 0.));
	trunk->Move(position);
	trunk->Scale(glm::vec3(1.5, 1.5, 1.5));
	Object* leaves = new Object("Objects/MadeInBlender/leaves1.obj", glm::vec3(0., 0.82, 0.));
	leaves->Move(glm::vec3(position.x, position.y - 0.2 , position.z));
	leaves->Scale(glm::vec3(2,2,2));

	Parts.insert(Parts.end(), { trunk,leaves });
}

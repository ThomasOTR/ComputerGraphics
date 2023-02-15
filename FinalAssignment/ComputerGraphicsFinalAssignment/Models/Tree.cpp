#include "Tree.h"
#include "../Object.h"

Tree::Tree(glm::vec3 position)
{
	SetPosition(position);
	AddComponents();
	material = defaultMaterial;
}

void Tree::AddComponents()
{
	glm::vec3 position = GetPosition();

	Object* trunk = new Object("Objects/MadeInBlender/trunk1.obj", glm::vec3(0.588, 0.294, 0.));
	trunk->SetPosition(position);
	trunk->SetScale(glm::vec3(1.5, 1.5, 1.5));
	Object* leaves = new Object("Objects/MadeInBlender/leaves1.obj", glm::vec3(0., 0.82, 0.));
	leaves->SetPosition(glm::vec3(position.x, position.y - 0.2 , position.z));
	leaves->SetScale(glm::vec3(2,2,2));

	Parts.insert(Parts.end(), { trunk,leaves });
}

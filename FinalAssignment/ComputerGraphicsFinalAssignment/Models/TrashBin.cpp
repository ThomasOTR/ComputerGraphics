#include "TrashBin.h"
#include "../Object.h"

TrashBin::TrashBin(glm::vec3 position)
{
	SetPosition(position);
	Transform();
	AddComponents();
	material = defaultMaterial;
}

void TrashBin::AddComponents()
{
	glm::vec3 position = GetPosition();

	Object* container = new Object("Objects/MadeInBlender/trashbin_container.obj", glm::vec3(0.6, 0.286, 0.012), position);
	Object* lid = new Object("Objects/MadeInBlender/trashbin_lid.obj", glm::vec3(0.635, 0.659, 0.659), glm::vec3(position.x,position.y + 0.5, position.z));

	Parts.insert(Parts.end(), { container,lid });

}
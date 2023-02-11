#include "TrashBin.h"
#include "../Object.h"

TrashBin::TrashBin(float positionX, float positionY, float positionZ)
{
	SetPosition(positionX, positionY, positionZ);
	Transform();
	AddComponents();
	material = defaultMaterial;
}

void TrashBin::AddComponents()
{
	glm::vec3 position = GetPosition();

	Object* container = new Object("Objects/MadeInBlender/trashbin_container.obj", glm::vec3(0.6, 0.286, 0.012), position.x, position.y, position.z);
	Object* lid = new Object("Objects/MadeInBlender/trashbin_lid.obj", glm::vec3(0.635, 0.659, 0.659), position.x, position.y + 0.5, position.z);

	Parts.insert(Parts.end(), { container,lid });

}
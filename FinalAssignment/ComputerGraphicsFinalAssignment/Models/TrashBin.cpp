#include "TrashBin.h"
#include "../Object.h"
void TrashBin::AddComponents()
{
	glm::vec3 position = GetPosition();

	Object* container = new Object("trashbin_container.obj", glm::vec3(0.6, 0.286, 0.012),true);
	container->Move(position);
	Object* lid = new Object("trashbin_lid.obj", glm::vec3(0.635, 0.659, 0.659),true);
	lid->Move(glm::vec3(position.x, position.y + 0.55, position.z));

	Parts.insert(Parts.end(), { container,lid });

}
#include "Lamppost.h"
#include "../Object.h"

void Lamppost::AddComponents()
{
	glm::vec3 position = GetPosition();

	Object* pole = new Object("Objects/MadeInBlender/lamppost_pole.obj", glm::vec3(0.851, 0.851, 0.851));
	pole->Move(position);

	Object* lamp = new Object("Objects/MadeInBlender/lamppost_light.obj", glm::vec3(0.988, 0.816, 0.286));
	lamp->Move(position);

	Object* top = new Object("Objects/MadeInBlender/lamppost_top.obj", glm::vec3(0.851, 0.851, 0.851));
	top->Move(position);

	Parts.insert(Parts.end(), { pole,lamp,top });
}

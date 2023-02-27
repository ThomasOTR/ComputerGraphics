#include "Lamppost.h"
#include "../Object.h"

void Lamppost::AddComponents()
{
	glm::vec3 position = GetPosition();

	Object* pole = new Object("lamppost_pole.obj", glm::vec3(0.851, 0.851, 0.851),true);
	pole->Move(position);

	Object* lamp = new Object("lamppost_light.obj", glm::vec3(0.988, 0.816, 0.286),true);
	lamp->Move(position);

	Object* top = new Object("lamppost_top.obj", glm::vec3(0.851, 0.851, 0.851),true);
	top->Move(position);

	Parts.insert(Parts.end(), { pole,lamp,top });
}

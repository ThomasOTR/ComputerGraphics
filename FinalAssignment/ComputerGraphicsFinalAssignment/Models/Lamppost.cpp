#include "Lamppost.h"
#include "../Object.h"

Lamppost::Lamppost()
{
	AddComponents();
}

void Lamppost::AddComponents()
{
	glm::vec3 position = GetPosition();

	Object* pole = new Object("Objects/MadeInBlender/lamppost_pole.obj", glm::vec3(0.588, 0.294, 0.));
	pole->Move(position);

	Object* lamp = new Object("Objects/MadeInBlender/lamppost_light.obj", glm::vec3(0.588, 0.294, 0.));
	lamp->Move(position);

	Object* top = new Object("Objects/MadeInBlender/lamppost_top.obj", glm::vec3(0.588, 0.294, 0.));
	top->Move(position);

	Parts.insert(Parts.end(), { pole,lamp,top });
}

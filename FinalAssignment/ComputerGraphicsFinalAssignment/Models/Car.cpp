#include "Car.h"
#include "../Object.h"

void Car::AddComponents()
{
	glm::vec3 position = GetPosition();

	Object* body = new Object("car/body.obj", glm::vec3(0., 0.588, 1.), false);
	body->Move(GetPosition());
	Object* interior = new Object("car/interior.obj", glm::vec3(0., 0., 0.),false);
	interior->Move(GetPosition());
	Object* wheels = new Object("car/wheels.obj", glm::vec3(0., 0., 0.), false);
	wheels->Move(GetPosition());

	Parts.insert(Parts.end(), { interior,wheels,body });



}

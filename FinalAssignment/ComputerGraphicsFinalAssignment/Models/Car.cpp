#include "Car.h"
#include "../Object.h"

Car::Car()
{
	AddComponents();	
}

void Car::AddComponents()
{
	glm::vec3 position = GetPosition();

	Object* body = new Object("Objects/car/car_body.obj", glm::vec3(0., 0.588, 1.));
	body->Move(GetPosition());
	Object* interior = new Object("Objects/car/car_interior.obj", glm::vec3(0., 0., 0.));
	interior->Move(GetPosition());
	Object* wheels = new Object("Objects/car/car_wheels.obj", glm::vec3(0., 0., 0.));
	wheels->Move(GetPosition());

	Parts.insert(Parts.end(), { interior,wheels,body });



}

#include "Car.h"
#include "../Object.h"

Car::Car(glm::vec3 position)
{
	SetPosition(position);
	Transform();
	AddComponents();
	material = defaultMaterial;
}

void Car::AddComponents()
{
	glm::vec3 position = GetPosition();

	Object* body = new Object("Objects/car/car_body.obj", glm::vec3(0., 0.588, 1.));
	Object* interior = new Object("Objects/car/car_interior.obj", glm::vec3(0., 0., 0.));
	Object* wheels = new Object("Objects/car/car_wheels.obj", glm::vec3(0., 0., 0.));
	
	Parts.insert(Parts.end(), { body,interior,wheels });



}

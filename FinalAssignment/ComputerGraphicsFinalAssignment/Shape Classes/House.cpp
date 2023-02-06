#include "House.h"
#include "Cube.h"
#include "Pyramid.h"
#include "../Object.h"
House::House(float positionX, float positionY, float positionZ)
{
	SetPosition(positionX, positionY, positionZ);
	Transform();
	AddComponents();
	material = defaultMaterial;
}

void House::AddComponents()
{
	glm::vec3 position = GetPosition();

	Object* Base = new Object("Objects/box.obj", "Textures/brick.bmp", position.x, position.y, position.z);
	Base->SetScale(1.75, 1.75, 1.75);
	Pyramid* Top = new Pyramid("Textures/rooftiles.bmp", position.x, position.y + 2.5, position.z);

	Cube* chimney = new Cube("Textures/brick.bmp", position.x - 0.5,position.y+2.7,position.z);
	chimney->SetScale(0.15, 0.5, 0.15);

	Parts.insert(Parts.end(), { Base,Top,chimney });
}

void House::ResetComponents()
{
	Parts.clear();
	AddComponents();
}

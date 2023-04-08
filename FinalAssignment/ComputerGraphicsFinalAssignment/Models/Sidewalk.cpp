#include "Sidewalk.h"
#include "../Object.h"

Sidewalk::Sidewalk(int AmountOfParts,bool x_axis)
{
	this->AmountOfParts = AmountOfParts;
	this->x_axis = x_axis;	
}

void Sidewalk::AddComponents()
{
	glm::vec3 position = GetPosition();
	for (int i = 0; i <= AmountOfParts; i++)
	{
		/* Creating the object*/
		Object* part = new Object("box.obj", "sidewalk.bmp",false);

		/* Set position*/
		if (BuildOnXaxis) part->Move(glm::vec3(position.x + (i* 0.75) , position.y, position.z));
		else part->Move(glm::vec3(position.x, position.y, position.z + i));
		
		/* Scale and Add to the parts*/
		part->Scale(glm::vec3(0.75, 0.15, 1));
		Parts.insert(Parts.end(), part);
	}
}

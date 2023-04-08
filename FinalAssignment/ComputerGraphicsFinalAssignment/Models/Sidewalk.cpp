#include "Sidewalk.h"
#include "../Object.h"

Sidewalk::Sidewalk(int amountOfBlocks,bool x_axis)
{
	this->amountOfBlocks = amountOfBlocks;
	this->x_axis = x_axis;	
}

void Sidewalk::AddComponents()
{
	glm::vec3 position = GetPosition();
	for (int i = 0; i <= amountOfBlocks; i++)
	{
		Object* part = new Object("box.obj", "sidewalk.bmp",false);

		/* Axis depends in which direction the parts will extend */
		if (x_axis) part->Move(glm::vec3(position.x + (i* 0.75) , position.y, position.z));
		else part->Move(glm::vec3(position.x, position.y, position.z + i));
		
		part->Scale(glm::vec3(0.75, 0.15, 1));
		Parts.insert(Parts.end(), part);
	}
}

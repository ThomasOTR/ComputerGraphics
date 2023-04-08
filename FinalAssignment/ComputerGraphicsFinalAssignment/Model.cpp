#include "Model.h"
#include <glm/gtx/string_cast.hpp>

void Model::Rotate(glm::vec3 rotation, float rotAngle)
{
	/* Rotate the Entity */
	Entity::Rotate(rotation, rotAngle);
	
	/* Rotate each part of the entity */
	for (Entity* p : Parts)
	{
		p->Rotate(rotation, rotAngle);
	}
}

void Model::Scale(glm::vec3 scale)
{
	/* Scale the Entity*/
	Entity::Scale(scale);

	/* Scale each part of the entity*/
	for (Entity* p : Parts)
	{
		p->Scale(scale);
	}
}

void Model::Buffer(glm::mat4 view, glm::mat4 projection)
{
	/* Buffer each part of the model*/
	for (Entity* p : Parts) p->Buffer(view, projection);
}

void Model::Render(glm::mat4 view, glm::mat4 projection)
{
	/* Render each part of the model*/
	for (Entity* p : Parts) p->Render(view, projection);
}



#include "Model.h"

void Model::SetPosition(glm::vec3 position)
{
	glm::vec3 before = GetPosition();
	Entity::SetPosition(position);
	for (Entity* p : Parts)
	{
		glm::vec3 difference = GetPosition() - before;
		p->SetPosition(p->GetPosition() + difference);
	}
}

void Model::SetRotation(glm::vec3 rotation, float rotAngle)
{
	Entity::SetRotation(rotation, rotAngle);
	for (Entity* p : Parts)
	{
		p->SetRotation(rotation, rotAngle);
	}
}

void Model::SetScale(glm::vec3 scale)
{
	Entity::SetScale(scale);
	for (Entity* p : Parts)
	{
		p->SetScale(scale);
	}
}

void Model::Transform()
{
	for (Entity* p : Parts) {
		p->Transform();
	}
}

void Model::ResetComponents()
{
	Parts.clear();
	ResetComponents();
}


void Model::Buffer(glm::mat4 view, glm::mat4 projection)
{
	for (Entity* p : Parts) p->Buffer(view, projection);
}

void Model::Render(glm::mat4 view, glm::mat4 projection)
{
	for (Entity* p : Parts) p->Render(view, projection);
}



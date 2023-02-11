#include "Model.h"

void Model::SetPosition(float positionX, float positionY, float positionZ)
{
	glm::vec3 before = GetPosition();
	Entity::SetPosition(positionX, positionY, positionZ);
	for (Entity* p : Parts)
	{
		glm::vec3 difference = GetPosition() - before;

		p->SetPosition(p->GetPosition().x + difference.x,
					   p->GetPosition().y + difference.y, 
					   p->GetPosition().z + difference.z);
	}
}

void Model::SetRotation(float rotationX, float rotationY, float rotationZ, float rotAngle)
{
	Entity::SetRotation(rotationX, rotationY, rotationZ,rotAngle);
	for (Entity* p : Parts)
	{
		p->SetRotation(rotationX, rotationY, rotationZ, rotAngle);
	}
}

void Model::SetScale(float scaleX, float scaleY, float scaleZ)
{
	Entity::SetScale(scaleX, scaleY, scaleZ);
	for (Entity* p : Parts)
	{
		p->SetScale(scaleX, scaleY, scaleZ);
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



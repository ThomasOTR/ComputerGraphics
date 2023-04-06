#include "Model.h"
#include <glm/gtx/string_cast.hpp>

void Model::Rotate(glm::vec3 rotation, float rotAngle)
{
	Entity::Rotate(rotation, rotAngle);
	for (Entity* p : Parts)
	{
		p->Rotate(rotation, rotAngle);
	}
}

void Model::Scale(glm::vec3 scale)
{
	Entity::Scale(scale);
	for (Entity* p : Parts)
	{
		p->Scale(scale);
	}
}

void Model::RunAnimations()
{
		for (Entity* p : Parts) {
			
			if(p->animations.size() != 0) p->RunAnimations();
		}
}

void Model::Buffer(glm::mat4 view, glm::mat4 projection)
{
	for (Entity* p : Parts) p->Buffer(view, projection);
}

void Model::Render(glm::mat4 view, glm::mat4 projection)
{
	for (Entity* p : Parts) {
		RunAnimations();
		p->Render(view, projection);
	}
}

void Model::AddAnimation(Animation* animation)
{
	for (Entity* p : Parts) {
		
		p->AddAnimation(animation);
	}
}



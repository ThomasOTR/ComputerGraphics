#include "Model.h"
#include <glm/gtx/string_cast.hpp>

void Model::Move(glm::vec3 position)
{
	Entity::Move(position);
	ResetComponents();
}

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
	if (animations.size() != 0)
	{
		Animation* animation = animations.front();
		for (Entity* p : Parts) {
			p->model = animation->Animate(p->model);
		}

		if (animation->AnimationCompleted == true)
		{
			if (AnimationInLoop)
			{
				animation->ResetAnimation();
				animations.push_back(animation);
			}
			animations.erase(animations.begin());
		}

	}
}

void Model::ResetComponents()
{
	Parts.clear();
	AddComponents();
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



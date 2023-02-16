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



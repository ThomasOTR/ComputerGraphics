#include "Entity.h"
#include "Transformations.h"

void Entity::AddAnimation(Animation* animation)
{
	animations.push_back(animation);
}

void Entity::AddAnimations(std::vector<Animation*> animations)
{
	for (Animation* a : animations) this->animations.push_back(a);
}

void Entity::RunAnimations()
{
	if (animations.size() != 0)
	{
		Animation* animation = animations.front();
		model = animation->Animate(model);

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

void Entity::Move(glm::vec3 position)
{
	model = TranslateEntity(model, position);
}

glm::vec3 Entity::GetPosition()
{
	return glm::vec3(model[3].x, model[3].y, model[3].z);
}

void Entity::Rotate(glm::vec3 rotation, float rotAngle)
{
	model = RotateEntity(model, rotAngle, rotation);
}

void Entity::Scale(glm::vec3 scale)
{
	model = ScaleEntity(model, scale);
}


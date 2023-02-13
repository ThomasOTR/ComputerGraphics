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

void Entity::Transform()
{
	if (Position != glm::vec3()) model = translate(model, Position.x, Position.y, Position.z);
	if (Scale != glm::vec3()) model = scale(model, Scale.x, Scale.y, Scale.z);
	if (Rotation != glm::vec3()) model = rotate(model, RotAngle, Rotation.x, Rotation.y, Rotation.z);
}

void Entity::SetPosition(glm::vec3 position)
{
	Position = position;
}

glm::vec3 Entity::GetPosition()
{
	return Position;
}

void Entity::SetRotation(glm::vec3 rotation, float rotAngle)
{
	Rotation = rotation;
	RotAngle = rotAngle;
}

glm::vec3 Entity::GetRotation()
{
	return Rotation;
}

void Entity::SetScale(glm::vec3 scale)
{
	Scale = scale;
}

glm::vec3 Entity::GetScale()
{
	return Scale;
}

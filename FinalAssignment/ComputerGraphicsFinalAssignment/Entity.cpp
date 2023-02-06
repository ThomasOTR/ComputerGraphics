#include "Entity.h"
#include "Transformations.h"

void Entity::RunAnimations()
{
	if (animations.size() == 0) return;
	else
	{
		AnimationRunning = true;
		int index = 0;
		while (AnimationRunning)
		{
			Animation* A = animations[index];
			A->Animate(model);
			index++;
			if (index >= animations.size()) index=0;
		}
	}

}
void Entity::Transform()
{
	if(Position != glm::vec3()) model = translate(model, Position.x, Position.y, Position.z);
	if(Scale != glm::vec3()) model = scale(model, Scale.x, Scale.y, Scale.z);
	if(Rotation != glm::vec3()) model =rotate(model, RotAngle, Rotation.x, Rotation.y, Rotation.z);
}

void Entity::SetPosition(float positionX, float positionY, float positionZ)
{
	Position = glm::vec3(positionX, positionY, positionZ);
}

glm::vec3 Entity::GetPosition()
{
	return Position;
}

void Entity::SetRotation(float rotationX, float rotationY, float rotationZ, float rotAngle)
{
	Rotation = glm::vec3(rotationX, rotationY, rotationZ);
	RotAngle = rotAngle;
}

glm::vec3 Entity::GetRotation()
{
	return Rotation;
}

void Entity::SetScale(float scaleX, float scaleY, float scaleZ)
{
	Scale = glm::vec3(scaleX, scaleY, scaleZ);
}

glm::vec3 Entity::GetScale()
{
	return Scale;
}

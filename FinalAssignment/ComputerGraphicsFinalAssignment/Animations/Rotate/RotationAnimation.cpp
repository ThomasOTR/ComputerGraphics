#include "Rotation_Animation.h"

Rotation_Animation::Rotation_Animation(float rotateX, float rotateY, float rotateZ, float rotAngle )
{
	this->rotAngle = rotAngle;
	rotation = glm::vec3(rotateX, rotateY, rotateZ);
}

glm::mat4 Rotation_Animation::Animate(glm::mat4 model)
{
	this->AnimationCompleted = true;
	return rotate(model, rotAngle, rotation.x, rotation.y, rotation.z);
}

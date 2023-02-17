#include "RotationAnimation.h"

RotationAnimation::RotationAnimation(float rotateX, float rotateY, float rotateZ, float rotAngle )
{
	this->rotAngle = rotAngle;
	rotation = glm::vec3(rotateX, rotateY, rotateZ);
}

glm::mat4 RotationAnimation::Animate(glm::mat4 model)
{
	this->AnimationCompleted = true;
	return RotateEntity(model, glm::radians(rotAngle), rotation);
}

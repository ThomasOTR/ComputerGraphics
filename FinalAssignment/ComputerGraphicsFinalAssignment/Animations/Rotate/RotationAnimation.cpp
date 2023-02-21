#include "RotationAnimation.h"
#include <iostream>

RotationAnimation::RotationAnimation(glm::vec3 rotation, float rotAngle)
{
	this->rotAngle = rotAngle;
	this->rotation = rotation;

}

glm::mat4 RotationAnimation::Animate(glm::mat4 model)
{
	this->AnimationCompleted = true;
	return RotateEntity(model, rotAngle, rotation);
}

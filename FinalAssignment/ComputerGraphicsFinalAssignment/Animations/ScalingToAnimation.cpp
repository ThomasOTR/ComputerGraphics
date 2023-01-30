#include "ScalingToAnimation.h"
#include "../Transformations.h"
#include <iostream>

ScalingToAnimation::ScalingToAnimation(float maxSize)
{
	this->maxSize = maxSize;
}

glm::mat4 ScalingToAnimation::Animate(glm::mat4)
{
	return glm::mat4();
}

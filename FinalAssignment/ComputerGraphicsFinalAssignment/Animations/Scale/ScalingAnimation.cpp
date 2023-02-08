#include "ScalingAnimation.h"
#include "../../Transformations.h"
#include <iostream>

ScalingAnimation::ScalingAnimation(float maxSize)
{
	AddValue = maxSize;
}

glm::mat4 ScalingAnimation::Animate(glm::mat4)
{
	return glm::mat4();
}

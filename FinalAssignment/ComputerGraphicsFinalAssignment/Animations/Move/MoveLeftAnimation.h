#pragma once
#include "../../Animation.h"
class MoveLeftAnimation : Animation
{
	MoveLeftAnimation(float, float, bool);
	// Inherited via Animation
	virtual glm::mat4 Animate(glm::mat4 model) override;
};


#pragma once
#include "../Animation.h"

class ScalingToAnimation :
	public Animation
{
public:
	float animateValue = 0.1f;
	float startSize = 0;
	float maxSize;
	// Inherited via Animation
	ScalingToAnimation(float);
	virtual glm::mat4 Animate(glm::mat4) override;
};
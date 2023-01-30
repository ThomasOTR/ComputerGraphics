#pragma once
#include "../Animation.h"
class UpDownAnimation : 
	public Animation
{
public:
	float animateValue = 0.1f;
	float startY;
	float maxY;
	// Inherited via Animation
	UpDownAnimation(float);
	virtual glm::mat4 Animate(glm::mat4) override;
};


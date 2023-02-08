#pragma once
#include "../../Animation.h"

class ScalingAnimation :
	public Animation
{
public:
	ScalingAnimation(float);

	// Inherited via Animation
	virtual glm::mat4 Animate(glm::mat4) override;

};
#pragma once
#include "../../Animation.h"

/// <summary>
/// An Animation subclass that scales an entity. 
/// </summary>
class ScalingAnimation :
	public Animation
{
public:
	ScalingAnimation(float, float);

	// Inherited via Animation
	virtual glm::mat4 Animate(glm::mat4) override;

};
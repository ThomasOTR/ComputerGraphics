#pragma once
#include "../../Animation.h"

/// <summary>
/// An Animation subclass that translates an entity on the Z-Axis. 
/// </summary>
class TranslateZ_Animation : 
	public Animation
{
public:
	TranslateZ_Animation(float, float);
	// Inherited via Animation
	virtual glm::mat4 Animate(glm::mat4) override;

};


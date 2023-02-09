#pragma once
#include "../../Animation.h"
class TranslateZ_Animation : 
	public Animation
{
public:
	TranslateZ_Animation(float, float);
	// Inherited via Animation
	virtual glm::mat4 Animate(glm::mat4) override;

};


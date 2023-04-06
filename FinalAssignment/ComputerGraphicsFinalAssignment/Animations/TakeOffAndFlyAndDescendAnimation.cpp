#include "TakeOffAndFlyAndDescendAnimation.h"
#include <iostream>

TakeOffAndFlyAndDescendAnimation::TakeOffAndFlyAndDescendAnimation(float Goal, float AnimateValue, float maxY,bool Negative )
{
	this->Goal = Goal;
	this->AnimateValue = AnimateValue;
	this->maxY = maxY;

	this->Negative = Negative;
}

glm::mat4 TakeOffAndFlyAndDescendAnimation::Animate(glm::mat4 model)
{
	if (!AnimationStarted) { startY = model[3].y; AnimationStarted = true; }

	if (!HasReachedYLimit)
	{
		if (model[3].y > maxY) {
			HasReachedYLimit = true; return model;
		}
		else return TranslateEntity(model, glm::vec3(0.0, AnimateValue, 0.0));
	}
	
	else if (!HasReachedZLimit && HasReachedYLimit)
	{
		if (Negative)
		{
			if(model[3].z > Goal) return TranslateEntity(model, glm::vec3(0.0, 0.0, -0.5));
			else { HasReachedZLimit = true; return model; }
		}
		else if (!Negative)
		{
			if(model[3].z < Goal) return TranslateEntity(model, glm::vec3(0.0, 0.0, 0.5));
			else { HasReachedZLimit = true; return model; }
		}
		return model;
	}
	else
	{
		if (model[3].y > startY) return TranslateEntity(model, glm::vec3(0.0, -AnimateValue, 0.0));
		else { AnimationCompleted = true; return model; }
	}
	


}

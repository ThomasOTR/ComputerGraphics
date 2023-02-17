#include "ScalingAnimation.h"
#include "../../Transformations.h"
#include <iostream>

ScalingAnimation::ScalingAnimation(float Goal, float AnimateValue)
{
	this->Goal = Goal;
	this->AnimateValue = AnimateValue;


}

glm::mat4 ScalingAnimation::Animate(glm::mat4 model)
{
	/* A check to start the animation with adding the startvalue */
	if (!AnimationStarted)
	{
		AnimationStarted = true;
		if (model[3].y > Goal) Negative = true;
	}

	/* Checks if the Animation is completed */
	if ((!Negative && model[3].y < Goal) or (Negative && model[3].y > Goal))
	{
		AnimationCompleted = true;
		return model;
	}

	else return ScaleEntity(model, glm::vec3(
					  Negative ? 1.0 - AnimateValue : 1.0 + AnimateValue,
		              Negative ? 1.0 - AnimateValue : 1.0 + AnimateValue, 
		              Negative ? 1.0 - AnimateValue : 1.0 + AnimateValue
					 ));
}

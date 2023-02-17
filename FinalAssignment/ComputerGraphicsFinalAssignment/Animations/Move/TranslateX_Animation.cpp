#include "TranslateX_Animation.h"
#include "../../Transformations.h"
#include <iostream>
TranslateX_Animation::TranslateX_Animation(float Goal, float AnimateValue)
{
	this->Goal = Goal;
	this->AnimateValue = AnimateValue;
}

glm::mat4 TranslateX_Animation::Animate(glm::mat4 model)
{
	/* A check to start the animation with adding the startvalue */
	if (!AnimationStarted)
	{
		AnimationStarted = true;
		float bla = model[3].x;
		if (model[3].x > Goal) Negative = true;
	}

	/* Checks if the Animation is completed */
	if ((!Negative && model[3].x > Goal) or (Negative && model[3].x < Goal))
	{
		AnimationCompleted = true;
		return model;
	}
	else return TranslateEntity(model, glm::vec3(0.0, 0.0, Negative ? -AnimateValue : AnimateValue));
}

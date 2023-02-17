#include "TranslateY_Animation.h"
#include "../../Transformations.h"

TranslateY_Animation::TranslateY_Animation(float AddValue, float AnimateValue)
{
    this->Goal = AddValue;
	this->AnimateValue = AnimateValue;
}

glm::mat4 TranslateY_Animation::Animate(glm::mat4 model)
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
	else return TranslateEntity(model, glm::vec3(0.0, Negative ? -AnimateValue : AnimateValue, 0.0));
}
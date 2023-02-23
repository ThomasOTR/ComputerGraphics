#include "MoveRightAnimation.h"
#include "../../Transformations.h"

MoveRightAnimation::MoveRightAnimation(float Goal, float AnimateValue, bool Negative)
{
	this->Goal = Goal;
	this->AnimateValue = AnimateValue;
	this->Negative = Negative;
}

glm::mat4 MoveRightAnimation::Animate(glm::mat4 model)
{
	/* A check to start the animation with adding the startvalue */
	if (!AnimationStarted)
	{
		AnimationStarted = true;
	}
	if ((!Negative && model[3].x > Goal) or (Negative && model[3].x < Goal))
	{
		AnimationCompleted = true;
		return model;
	}
	else return TranslateEntity(model, glm::vec3(AnimateValue, 0.0, 0.0));
}

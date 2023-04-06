
#include "MoveRightAndTurnAroundAnimation.h"
#include <iostream>

MoveRightAndTurnAroundAnimation::MoveRightAndTurnAroundAnimation(float Goal, float AnimateValue)
{
	this->Goal = Goal;
	this->AnimateValue = AnimateValue;
}

void MoveRightAndTurnAroundAnimation::ResetAnimation()
{
	AnimationStarted = false;
	AnimationCompleted = false;
	IsTurnedAround = false;
}

glm::mat4 MoveRightAndTurnAroundAnimation::Animate(glm::mat4 model)
{
	std::cout << model[3].x << std::endl;
	/* Start the Animation */
	if (!AnimationStarted) { AnimationStarted = true; StartX = model[3].x; }

	/* If the Goal position has been reached. Turn around to move back.*/
	else if (model[3].x > Goal && !IsTurnedAround)
	{
		IsTurnedAround = true;
		return RotateEntity(model, 180, glm::vec3(0, 1, 0));
	}
	/* If the start position has been reached. Turn around again so it's back in place*/
	else if (model[3].x <= StartX && IsTurnedAround)
	{
		
		AnimationCompleted = true;
		return RotateEntity(model, 180, glm::vec3(0, 1, 0));
	}
	return TranslateEntity(model, glm::vec3(AnimateValue, 0.0, 0.0));
}


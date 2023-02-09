#include "ScalingAnimation.h"
#include "../../Transformations.h"
#include <iostream>

ScalingAnimation::ScalingAnimation(float AddValue, float AnimateValue)
{
	this->AddValue = AddValue;
	this->AnimateValue = AnimateValue;
	if (AddValue > 0 || AddValue < 1) Negative = true;


}

glm::mat4 ScalingAnimation::Animate(glm::mat4 model)
{
	if (!AnimationStarted)
	{
		AnimationStarted = true;
		StartValue = model[1].y;
	}

	if (!Negative && (StartValue + AddValue <= model[1].y) or (Negative && StartValue + AddValue >= model[1].y))
	{
		AnimationCompleted = true;
		return model;
	}
	else return scale(model, 
					  Negative ? 1.0 - AnimateValue : 1.0 + AnimateValue,
		              Negative ? 1.0 - AnimateValue : 1.0 + AnimateValue, 
		              Negative ? 1.0 - AnimateValue : 1.0 + AnimateValue
					 );
}

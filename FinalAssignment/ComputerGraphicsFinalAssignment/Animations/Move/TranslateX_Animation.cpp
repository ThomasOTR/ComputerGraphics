#include "TranslateX_Animation.h"
#include "../../Transformations.h"
#include <iostream>
TranslateX_Animation::TranslateX_Animation(float AddValue)
{
	this->AddValue = AddValue;
	if (signbit(AddValue)) Negative = true;
}

glm::mat4 TranslateX_Animation::Animate(glm::mat4 model)
{
	if (!AnimationStarted)
	{
		AnimationStarted = true;
		StartValue = model[3].x;
	}

	if (!Negative && (StartValue + AddValue >= model[3].x) or (Negative && StartValue + AddValue <= model[3].x))
	{
		AnimationCompleted = true;
		return model;
	}
	else return translate(model, Negative ? -AnimateValue : AnimateValue, 0.0, 0.0);
}

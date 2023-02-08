#include "TranslateZ_Animation.h"

TranslateZ_Animation::TranslateZ_Animation(float AddValue)
{
	this->AddValue = AddValue;
	if (signbit(AddValue)) Negative = true;
}

glm::mat4 TranslateZ_Animation::Animate(glm::mat4 model)
{
	if (!AnimationStarted)
	{
		AnimationStarted = true;
		StartValue = model[3].z;
	}

	if (!Negative && (StartValue + AddValue >= model[3].z) or (Negative && StartValue + AddValue <= model[3].z))
	{
		AnimationCompleted = true;
		return model;
	}
	else return translate(model, Negative ? -AnimateValue : AnimateValue, 0.0, 0.0);
}

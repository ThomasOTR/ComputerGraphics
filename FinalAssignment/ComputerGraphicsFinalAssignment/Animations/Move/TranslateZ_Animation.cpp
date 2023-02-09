#include "TranslateZ_Animation.h"

TranslateZ_Animation::TranslateZ_Animation(float AddValue, float AnimateValue)
{
	this->AddValue = AddValue;
	this->AnimateValue = AnimateValue;
	if (signbit(AddValue)) Negative = true;
}

glm::mat4 TranslateZ_Animation::Animate(glm::mat4 model)
{
	if (!AnimationStarted)
	{
		AnimationStarted = true;
		StartValue = model[3].z;
	}

	if (!Negative && (StartValue + AddValue <= model[3].z) or (Negative && StartValue + AddValue >= model[3].z))
	{
		AnimationCompleted = true;
		return model;
	}
	else return translate(model, 0.0, 0.0, Negative ? -AnimateValue : AnimateValue);
}

#include "TranslateY_Animation.h"
#include "../../Transformations.h"

TranslateY_Animation::TranslateY_Animation(float AddValue, float AnimateValue)
{
    this->AddValue = AddValue;
	this->AnimateValue = AnimateValue;
	if (signbit(AddValue)) Negative = true;
}

glm::mat4 TranslateY_Animation::Animate(glm::mat4 model)
{
	if (!AnimationStarted)
	{
		AnimationStarted = true;
		StartValue = model[3].y;
	}

	if (!Negative && (StartValue + AddValue <= model[3].y) or (Negative && StartValue + AddValue >= model[3].y))
	{
		AnimationCompleted = true;
		return model;
	}
	else return translate(model, 0.0, Negative ? -AnimateValue : AnimateValue, 0.0);
}
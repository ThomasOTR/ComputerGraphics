#include "TranslateX_Animation.h"
#include "../../Transformations.h"
#include <iostream>
TranslateX_Animation::TranslateX_Animation(float AddValue, float AnimateValue)
{
	this->AddValue = AddValue;
	this->AnimateValue = AnimateValue;
	if (signbit(AddValue)) Negative = true;
}

glm::mat4 TranslateX_Animation::Animate(glm::mat4 model)
{
	glm::vec3 position = glm::vec3(model[3].x, model[3].y, model[3].z);
	if (!AnimationStarted)
	{
		AnimationStarted = true;
		StartValue = position.x;
	}

	if (!Negative && (StartValue + AddValue <= position.x) or (Negative && StartValue + AddValue >= position.x))
	{
		AnimationCompleted = true;
		return model;
	}
	else return translate(model, Negative ? -AnimateValue : AnimateValue, 0.0, 0.0);
}

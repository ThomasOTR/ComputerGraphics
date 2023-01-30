#include "UpDownAnimation.h"
#include "../Transformations.h"
#include <iostream>

UpDownAnimation::UpDownAnimation(float maxY)
{
    this->maxY = maxY;
    this->startY = 0;
}

glm::mat4 UpDownAnimation::Animate(glm::mat4 model)
{
    if (AnimationStarted == false) {
        AnimationStarted = true;
        startY = model[3].y;
    }
    if (startY + maxY <= model[3].y && animateValue > 0) {
        animateValue = -animateValue;
    }
    if (startY >= model[3].y && animateValue < 0) {
        animateValue = -animateValue;
    }
    return translate(model, 0, animateValue,0);
}

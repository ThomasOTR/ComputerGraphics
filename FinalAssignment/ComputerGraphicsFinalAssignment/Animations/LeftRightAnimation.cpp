#include "LeftRightAnimation.h"
#include "../Transformations.h"

LeftRightAnimation::LeftRightAnimation(float maxX)
{
    this->maxX = maxX;
    this->startX = 0;
}

glm::mat4 LeftRightAnimation::Animate(glm::mat4 model)
{
    if (AnimationStarted == false) {
        AnimationStarted = true;
        startX = model[3].y;
    }
    if (startX + maxX <= model[3].y && animateValue > 0) {
        animateValue = -animateValue;
    }
    if (startX >= model[3].y && animateValue < 0) {
        animateValue = -animateValue;
    }
    return translate(model, animateValue,0, 0);
}

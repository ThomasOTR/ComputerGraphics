#include "ForwardBackwardAnimation.h"
#include "../Transformations.h"

ForwardBackwardAnimation::ForwardBackwardAnimation(float maxZ)
{
    this->maxZ = maxZ;
    this->startZ = 0;
}

glm::mat4 ForwardBackwardAnimation::Animate(glm::mat4 model)
{
    if (AnimationStarted == false) {
        AnimationStarted = true;
        startZ = model[3].z;
    }
    if (startZ + maxZ <= model[3].y && animateValue > 0) {
        animateValue = -animateValue;
    }
    if (startZ >= model[3].y && animateValue < 0) {
        animateValue = -animateValue;
    }
    return translate(model, 0, 0, animateValue);
}

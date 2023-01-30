#pragma once
#include "../Animation.h"
class LeftRightAnimation :
    public Animation
{
public:
    float animateValue = .1f;
    float startX;
    float maxX;
    // Inherited via Animation
    LeftRightAnimation(float);
    virtual glm::mat4 Animate(glm::mat4) override;
};


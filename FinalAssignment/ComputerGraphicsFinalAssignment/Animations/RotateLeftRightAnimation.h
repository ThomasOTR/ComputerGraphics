#pragma once
#include "../Animation.h"
class RotateLeftRightAnimation :
    public Animation
{
    RotateLeftRightAnimation(float);
    // Inherited via Animation
    virtual glm::mat4 Animate(glm::mat4) override;
};


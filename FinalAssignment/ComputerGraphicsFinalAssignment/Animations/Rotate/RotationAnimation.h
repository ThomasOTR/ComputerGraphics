#pragma once
#include "../../Animation.h"
class RotationAnimation :
    public Animation
{
    RotationAnimation(float,float);

    // Inherited via Animation
    virtual glm::mat4 Animate(glm::mat4) override;

};


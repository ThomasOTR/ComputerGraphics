#pragma once
#include "../Animation.h"
class ForwardBackwardAnimation :
    public Animation
{
    public:
        float animateValue = .1f;
        float startZ;
        float maxZ;
        // Inherited via Animation
        ForwardBackwardAnimation(float);
        virtual glm::mat4 Animate(glm::mat4) override;
    };


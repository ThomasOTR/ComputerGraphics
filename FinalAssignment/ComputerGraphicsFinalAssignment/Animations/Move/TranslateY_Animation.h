#pragma once
#include "../../Animation.h"
class TranslateY_Animation :
    public Animation
{
    public:
        TranslateY_Animation(float,float);

        // Inherited via Animation
        virtual glm::mat4 Animate(glm::mat4) override;
    };


#pragma once
#include "../../Animation.h"
class TranslateX_Animation :
    public Animation
{
public:
    TranslateX_Animation(float);

    // Inherited via Animation
    virtual glm::mat4 Animate(glm::mat4) override;

};


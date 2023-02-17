#pragma once
#include "../../Animation.h"

/// <summary>
/// An Animation subclass that translates an entity on the X-Axis. 
/// </summary>
class TranslateX_Animation :
    public Animation
{
public:
    TranslateX_Animation(float,float);

    // Inherited via Animation
    virtual glm::mat4 Animate(glm::mat4) override;

};


#pragma once
#include "../../Animation.h"

/// <summary>
/// An Animation subclass that translates an entity on the X-Axis. 
/// </summary>
class MoveRightAnimation :
    public Animation
{
public:
    MoveRightAnimation(float,float,bool);

    // Inherited via Animation
    virtual glm::mat4 Animate(glm::mat4) override;

};


#pragma once
#include "../../Animation.h"

/// <summary>
/// An Animation subclass that rotates an entity
/// </summary>
class RotationAnimation :
    public Animation
{
public:
    RotationAnimation(float, float, float, float);
    // Inherited via Animation
    virtual glm::mat4 Animate(glm::mat4) override;

    float rotAngle;
    glm::vec3 rotation;
};


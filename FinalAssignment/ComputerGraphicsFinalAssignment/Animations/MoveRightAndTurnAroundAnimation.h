#pragma once
#include "../Animation.h"
class MoveRightAndTurnAroundAnimation :
    public Animation
{
private:
    /* Boolean to easily detect if the entity is turned around*/
    bool IsTurnedAround = false;

    /* Float value that helps the entity moving back to it's former position*/
    float StartX = 0;
public:
    MoveRightAndTurnAroundAnimation(float Goal, float AnimateValue);

    // Inherited via Animation
    virtual glm::mat4 Animate(glm::mat4 model) override;
};


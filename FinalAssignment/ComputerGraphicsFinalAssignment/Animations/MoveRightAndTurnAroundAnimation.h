#pragma once
#include "../Animation.h"
class MoveRightAndTurnAroundAnimation :
    public Animation
{
private:
    bool IsTurnedAround = false;
    float StartX = 0;
public:
    MoveRightAndTurnAroundAnimation(float Goal, float AnimateValue);
    void ResetAnimation() override;
    // Inherited via Animation
    virtual glm::mat4 Animate(glm::mat4 model) override;
};


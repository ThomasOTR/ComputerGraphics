#include "../Animation.h"

class TakeOffAndFlyAndDescendAnimation :
    public Animation
{
private:
    float maxY;
    float startY = 0.0;
    bool HasReachedYLimit = false;
    bool HasReachedZLimit = false;

public:
    TakeOffAndFlyAndDescendAnimation(float Goal, float AnimateValue, float maxY, bool negative);
    // Inherited via Animation
    virtual glm::mat4 Animate(glm::mat4 model) override;

};
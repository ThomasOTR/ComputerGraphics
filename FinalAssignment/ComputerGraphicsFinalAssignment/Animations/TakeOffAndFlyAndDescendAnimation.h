#include "../Animation.h"

class TakeOffAndFlyAndDescendAnimation :
    public Animation
{
private:
    int maxY;
    int startY = 0;
    bool HasReachedYLimit = false;
    bool HasReachedZLimit = false;

public:
    TakeOffAndFlyAndDescendAnimation(float Goal, float AnimateValue, float maxY, bool negative);
    // Inherited via Animation
    virtual glm::mat4 Animate(glm::mat4 model) override;

};
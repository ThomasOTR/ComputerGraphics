#pragma once
#include "../Model.h"
class TrashBin :
    public Model
{
public:
    TrashBin() = default;
    TrashBin(glm::vec3);

    // Inherited via Model
    virtual void AddComponents() override;
};


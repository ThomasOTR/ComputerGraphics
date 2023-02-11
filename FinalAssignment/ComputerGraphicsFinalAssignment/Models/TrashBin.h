#pragma once
#include "../Model.h"
class TrashBin :
    public Model
{
public:
    TrashBin() = default;
    TrashBin(float, float, float);

    // Inherited via Model
    virtual void AddComponents() override;
};


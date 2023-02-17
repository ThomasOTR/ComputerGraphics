#pragma once
#include "../Model.h"

/// <summary>
/// An subclass of Model that creates a Trashbin
/// </summary>
class TrashBin :
    public Model
{
public:
    TrashBin();

    // Inherited via Model
    virtual void AddComponents() override;
};


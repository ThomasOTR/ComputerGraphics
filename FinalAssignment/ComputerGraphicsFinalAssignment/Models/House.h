#pragma once
#include "../Model.h"

/// <summary>
/// An subclass of Model that creates a House
/// </summary>
class House :
    public Model
{
public:
    House() = default;

    // Inherited via Mesh
    virtual void AddComponents() override;
};


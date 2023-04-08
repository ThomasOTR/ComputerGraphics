#pragma once
#include "../Model.h"

/// <summary>
/// An subclass of Model that creates a Lamppost
/// </summary>
class Lamppost :
    public Model
{
public:
    Lamppost() = default;
    // Inherited via Model
    virtual void AddComponents() override;
};


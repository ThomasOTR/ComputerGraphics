#pragma once
#include "../Model.h"

/// <summary>
/// An subclass of Model that creates a Car.
/// </summary>
class Car :
    public Model
{
public:
    Car() = default;

    // Inherited via Mesh
    virtual void AddComponents() override;
};
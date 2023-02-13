#pragma once
#include "../Model.h"

/// <summary>
/// A class to create a Blokkentoren Mesh
/// </summary>
class House :
    public Model
{
public:
    House() = default;
    House(glm::vec3);

    // Inherited via Mesh
    virtual void AddComponents() override;
};


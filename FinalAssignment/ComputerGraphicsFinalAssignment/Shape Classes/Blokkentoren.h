#pragma once
#include "../Mesh.h"

/// <summary>
/// A class to create a Blokkentoren Mesh
/// </summary>
class Blokkentoren :
    public Mesh
{
public:
    Blokkentoren() = default;
    Blokkentoren(float, float, float);

    // Inherited via Mesh
    virtual void AddComponents() override;


    // Inherited via Mesh
    virtual void ResetComponents() override;

};


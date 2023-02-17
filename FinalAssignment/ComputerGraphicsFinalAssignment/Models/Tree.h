#pragma once
#include "../Model.h"

/// <summary>
/// An subclass of Model that creates a Tree
/// </summary>
class Tree :
    public Model
{
public:
    Tree();

    // Inherited via Model
    virtual void AddComponents() override;
};


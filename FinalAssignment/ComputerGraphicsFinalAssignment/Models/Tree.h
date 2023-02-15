#pragma once
#include "../Model.h"
class Tree :
    public Model
{
public:
    Tree() = default;
    Tree(glm::vec3);
    ;
    // Inherited via Model
    virtual void AddComponents() override;
};


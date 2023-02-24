#pragma once
#include "../Model.h"
class Lamppost :
    public Model
{
public:
    Lamppost() = default;
    // Inherited via Model
    virtual void AddComponents() override;
};


#pragma once
#include "../Model.h"
class Lamppost :
    public Model
{
public:
    Lamppost();
    // Inherited via Model
    virtual void AddComponents() override;
};


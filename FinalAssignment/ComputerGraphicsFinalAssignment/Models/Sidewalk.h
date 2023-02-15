#pragma once
#include "../Model.h"
class Sidewalk :
    public Model
{
private:
    int amountOfBlocks;
    bool x_axis;
public:
    Sidewalk() = default;
    Sidewalk(glm::vec3,int,bool);
    // Inherited via Model
    virtual void AddComponents() override;
};


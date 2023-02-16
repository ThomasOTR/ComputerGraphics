#pragma once
#include "../Model.h"
class Car :
    public Model
{
public:
    Car() = default;
    Car(glm::vec3);

    // Inherited via Mesh
    virtual void AddComponents() override;
};
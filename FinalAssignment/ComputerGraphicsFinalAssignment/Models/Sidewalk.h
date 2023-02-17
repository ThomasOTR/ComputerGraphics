#pragma once
#include "../Model.h"

/// <summary>
/// An subclass of Model that creates a Sidewalk
/// </summary>
class Sidewalk :
    public Model
{
private:

    /* 
     * A value that determines how long the sidewalk is.
     * The sidewalk is build by multiple blocks next to each other to keep it textured nice 
     */
    int amountOfBlocks;

    /* A bool that is set to know in which direction the sidewalk is build */
    bool x_axis;
public:
    Sidewalk() = default;
    Sidewalk(int,bool);
    // Inherited via Model
    virtual void AddComponents() override;
};


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
    int AmountOfParts;

    /* A bool that determines in which direction the sidewalk will extend */
    bool BuildOnXaxis;
public:
    Sidewalk() = default;
    Sidewalk(int,bool);
    // Inherited via Model
    virtual void AddComponents() override;
};


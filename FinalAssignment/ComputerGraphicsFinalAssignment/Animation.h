#pragma once
#include <glm/glm.hpp>
#include <vector>
#include "Transformations.h"

/// <summary>
/// A base class for every animation 
/// </summary>
class Animation
{
public:
	/* A boolean that will be used to check if the animation is already started. */
	bool AnimationStarted = false;

	/* A boolean that will be used to check if the animation is completed. With this boolean the Entity knows it can start a new animation. */
	bool AnimationCompleted = false;

	/* A boolean to know in which direction it has to animate. */
	bool Negative = false;

	/* Useful values about speed, start and finish. */
	float AnimateValue = 0.1f;
	float Goal;

	
	Animation() = default;
	
	/// <summary>
	/// The method to start the animation 
	/// </summary>
	/// <param name="model">The model that will be updated in the Animation. </param>
	/// <returns></returns>
	virtual glm::mat4 Animate(glm::mat4 model) = 0;

	/// <summary>
	/// A method to reset the Animation so it can be reused without creating a new animation with all the values. */
	/// </summary>
	void ResetAnimation();
};


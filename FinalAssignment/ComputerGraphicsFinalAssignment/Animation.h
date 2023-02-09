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
	/// <summary>
	/// A boolean to know if a animation is already started
	/// This boolean will be true when the animation is started.
	/// </summary>
	bool AnimationStarted = false;
	bool AnimationCompleted = false;
	bool Negative = false;

	float AnimateValue = 0.1f;
	float StartValue = 0.0f;
	float AddValue = 0.0f;
	/// <summary>
	/// A method to start the animation
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	///
	
	Animation() = default;
	virtual glm::mat4 Animate(glm::mat4) = 0;
	void ResetAnimation();
};


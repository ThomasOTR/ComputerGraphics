#pragma once
#include <glm/glm.hpp>

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
	/// <summary>
	/// A method to start the animation
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	virtual glm::mat4 Animate(glm::mat4) = 0;
};


#pragma once
#include <glm/glm.hpp>
class Animation
{
public:
	bool AnimationStarted = false;
	virtual glm::mat4 Animate(glm::mat4) = 0;
};


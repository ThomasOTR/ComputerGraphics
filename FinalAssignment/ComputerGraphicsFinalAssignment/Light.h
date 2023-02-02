#pragma once
#include <glm/glm.hpp>
class Light
{
public:
	glm::vec3 Position = glm::vec3();

	Light() = default;
	Light(glm::vec3);

};

